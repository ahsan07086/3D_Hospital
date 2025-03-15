#ifndef CURVED_PIPE_SEGMENT_H
#define CURVED_PIPE_SEGMENT_H

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#define PI 3.141516

class CurvedPipeSegment {
public:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

    // Texture property
    unsigned int textureMap;
    glm::mat4 transform;

    float shininess;
    glm::mat4 positionMatrix = glm::mat4(1.0f);
    glm::mat4 scaleMatrix = glm::mat4(1.0f);
    glm::mat4 rotationMatrix = glm::mat4(1.0f);

    CurvedPipeSegment(unsigned int tMap, float pipeRadius, float arcLength, glm::vec3 amb = glm::vec3(0.0f, 0.0f, 1.0f),
                      glm::vec3 diff = glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f),
                      float shiny = 32.0f)
        : transform(glm::mat4(1.0f)) {
        this->textureMap = tMap;
        this->ambient = amb;
        this->diffuse = diff;
        this->specular = spec;
        this->shininess = shiny;

        generateSegmentVerticesAndIndices(pipeRadius, arcLength);
        setupSegmentVAO();
    }

    ~CurvedPipeSegment() {
        glDeleteVertexArrays(1, &segmentVAO);
        glDeleteBuffers(1, &segmentVBO);
        glDeleteBuffers(1, &segmentEBO);
    }

    void draw(Shader& shader, glm::mat4 model = glm::mat4(1.0f)) {
        shader.use();

        shader.setVec3("material.ambient", this->ambient);
        shader.setVec3("material.diffuse", this->diffuse);
        shader.setVec3("material.specular", this->specular);
        shader.setFloat("material.shininess", this->shininess);

        glBindTexture(GL_TEXTURE_2D, this->textureMap);

        transform = positionMatrix * rotationMatrix * scaleMatrix;
        model = model * transform;
        shader.setMat4("model", model);

        glBindVertexArray(segmentVAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

    void setPosition(glm::vec3 pos) {
        positionMatrix = glm::translate(glm::mat4(1.0f), pos);
    }

    void setScale(glm::vec3 scale) {
        scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
    }

    void setRotation(float angle, glm::vec3 axis) {
        rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
    }

private:
    unsigned int segmentVAO, segmentVBO, segmentEBO;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    void generateSegmentVerticesAndIndices(float pipeRadius, float arcLength) {
        const int tubeSegments = 36;
        const int arcSegments = 12; // Segments along the curve
        float tubeStep = 2 * PI / tubeSegments;
        float arcStep = arcLength / arcSegments;

        for (int i = 0; i <= arcSegments; ++i) {
            float theta = i * arcStep - arcLength / 2.0f;
            glm::vec3 center = glm::vec3(sinf(theta), 0.0f, cosf(theta));

            for (int j = 0; j <= tubeSegments; ++j) {
                float phi = j * tubeStep;
                float x = pipeRadius * cos(phi);
                float y = pipeRadius * sin(phi);
                glm::vec3 point = center + glm::vec3(x, y, 0.0f);

                // Position
                vertices.push_back(point.x);
                vertices.push_back(point.y);
                vertices.push_back(point.z);

                // Normal
                vertices.push_back(x / pipeRadius);
                vertices.push_back(y / pipeRadius);
                vertices.push_back(0.0f);

                // Texture coordinates
                vertices.push_back((float)j / tubeSegments);
                vertices.push_back((float)i / arcSegments);
            }
        }

        // Generate indices
        for (int i = 0; i < arcSegments; ++i) {
            for (int j = 0; j < tubeSegments; ++j) {
                int k1 = i * (tubeSegments + 1) + j;
                int k2 = k1 + tubeSegments + 1;

                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);

                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }

    void setupSegmentVAO() {
        glGenVertexArrays(1, &segmentVAO);
        glGenBuffers(1, &segmentVBO);
        glGenBuffers(1, &segmentEBO);

        glBindVertexArray(segmentVAO);

        glBindBuffer(GL_ARRAY_BUFFER, segmentVBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, segmentEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
    }
};

#endif /* CURVED_PIPE_SEGMENT_H */
