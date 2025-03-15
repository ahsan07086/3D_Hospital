#ifndef CAPSULE_H
#define CAPSULE_H

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#define PI 3.141516

class Capsule {
public:
    // Material properties
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

    // Texture property
    unsigned int textureMap;
    glm::mat4 transform;

    // Common properties
    float shininess;
    glm::mat4 positionMatrix = glm::mat4(1.0f);
    glm::mat4 scaleMatrix = glm::mat4(1.0f);
    glm::mat4 rotationMatrix = glm::mat4(1.0f);

    // Constructor with default arguments
    Capsule(unsigned int tMap, glm::vec3 amb = glm::vec3(1.0f, 0.5f, 0.3f),
            glm::vec3 diff = glm::vec3(1.0f, 0.5f, 0.3f),
            glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f),
            float shiny = 32.0f)
        : transform(glm::mat4(1.0f)) {
        this->textureMap = tMap;
        this->ambient = amb;
        this->diffuse = diff;
        this->specular = spec;
        this->shininess = shiny;

        generateCapsuleVerticesAndIndices();
        setupCapsuleVAO();
    }

    // Destructor
    ~Capsule() {
        glDeleteVertexArrays(1, &capsuleVAO);
        glDeleteBuffers(1, &capsuleVBO);
        glDeleteBuffers(1, &capsuleEBO);
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

        glBindVertexArray(capsuleVAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

    // Transformation setters
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
    unsigned int capsuleVAO;
    unsigned int capsuleVBO;
    unsigned int capsuleEBO;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    void generateCapsuleVerticesAndIndices() {
        const int sectors = 36;
        const int stacks = 18;
        const float radius = 1.0f;
        const float height = 2.0f;
        const float halfHeight = height / 2.0f;

        float sectorStep = 2 * PI / sectors;
        float stackStep = PI / stacks;

        // Top hemisphere
        for (int i = 0; i <= stacks / 2; ++i) {
            float stackAngle = PI / 2 - i * stackStep;
            float xy = radius * cosf(stackAngle);
            float z = radius * sinf(stackAngle);

            for (int j = 0; j <= sectors; ++j) {
                float sectorAngle = j * sectorStep;
                float x = xy * cosf(sectorAngle);
                float y = xy * sinf(sectorAngle);

                vertices.push_back(x);
                vertices.push_back(z + halfHeight); // Translate upwards
                vertices.push_back(y);

                vertices.push_back(x / radius);
                vertices.push_back(z / radius);
                vertices.push_back(y / radius);

                vertices.push_back((float)j / sectors);
                vertices.push_back((float)i / stacks);
            }
        }

        // Cylinder body
        for (int i = 0; i <= 1; ++i) {
            float z = (i == 0) ? halfHeight : -halfHeight;

            for (int j = 0; j <= sectors; ++j) {
                float angle = j * sectorStep;
                float x = radius * cos(angle);
                float y = radius * sin(angle);

                vertices.push_back(x);
                vertices.push_back(z);
                vertices.push_back(y);

                vertices.push_back(0.0f);
                vertices.push_back((i == 0) ? 1.0f : -1.0f);
                vertices.push_back(0.0f);

                vertices.push_back((float)j / sectors);
                vertices.push_back((i == 0) ? 1.0f : 0.0f);
            }
        }

        // Bottom hemisphere
        for (int i = stacks / 2; i <= stacks; ++i) {
            float stackAngle = PI / 2 - i * stackStep;
            float xy = radius * cosf(stackAngle);
            float z = radius * sinf(stackAngle);

            for (int j = 0; j <= sectors; ++j) {
                float sectorAngle = j * sectorStep;
                float x = xy * cosf(sectorAngle);
                float y = xy * sinf(sectorAngle);

                vertices.push_back(x);
                vertices.push_back(z - halfHeight); // Translate downwards
                vertices.push_back(y);

                vertices.push_back(x / radius);
                vertices.push_back(z / radius);
                vertices.push_back(y / radius);

                vertices.push_back((float)j / sectors);
                vertices.push_back((float)i / stacks);
            }
        }

        // Generate indices
        int k1, k2;
        for (int i = 0; i < stacks; ++i) {
            k1 = i * (sectors + 1);
            k2 = k1 + sectors + 1;

            for (int j = 0; j < sectors; ++j, ++k1, ++k2) {
                if (i != 0) {
                    indices.push_back(k1);
                    indices.push_back(k2);
                    indices.push_back(k1 + 1);
                }
                if (i != (stacks - 1)) {
                    indices.push_back(k1 + 1);
                    indices.push_back(k2);
                    indices.push_back(k2 + 1);
                }
            }
        }
    }

    void setupCapsuleVAO() {
        glGenVertexArrays(1, &capsuleVAO);
        glGenBuffers(1, &capsuleVBO);
        glGenBuffers(1, &capsuleEBO);

        glBindVertexArray(capsuleVAO);

        glBindBuffer(GL_ARRAY_BUFFER, capsuleVBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, capsuleEBO);
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

#endif /* CAPSULE_H */
