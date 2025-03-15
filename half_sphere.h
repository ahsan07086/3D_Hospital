#ifndef HALF_SPHERE_H
#define HALF_SPHERE_H

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"

using namespace std;

class HalfSphere {
public:
    // Material properties
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;

    // Texture property
    unsigned int textureMap;
    glm::mat4 transform;
    // Common property
    float shininess;
    glm::mat4 positionMatrix = glm::mat4(1.0f);
    glm::mat4 scaleMatrix = glm::mat4(1.0f);
    glm::mat4 rotationMatrix = glm::mat4(1.0f);

    // Constructor with default arguments
    HalfSphere(unsigned int tMap = 0, glm::vec3 amb = glm::vec3(1.0f, 0.5f, 0.3f),
        glm::vec3 diff = glm::vec3(1.0f, 0.5f, 0.3f),
        glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f),
        float shiny = 32.0f)
        : transform(glm::mat4(1.0f)) {
        this->textureMap = tMap;
        this->ambient = amb;
        this->diffuse = diff;
        this->specular = spec;
        this->shininess = shiny;

        setUpHalfSphereVertexDataAndConfigureVertexAttribute();
    }

    // Destructor
    ~HalfSphere() {
        glDeleteVertexArrays(1, &halfSphereVAO);
        glDeleteBuffers(1, &halfSphereVBO);
        glDeleteBuffers(1, &halfSphereEBO);
    }

    void draw(Shader& shader, glm::mat4 model = glm::mat4(1.0f)) {
        shader.use();

        shader.setInt("texUnit", 0);
        shader.setVec3("material.ambient", this->ambient);
        shader.setVec3("material.diffuse", this->diffuse);
        shader.setVec3("material.specular", this->specular);
        shader.setFloat("material.shininess", this->shininess);

        // Bind texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->textureMap);
        transform = positionMatrix * rotationMatrix * scaleMatrix;
        model = model * transform;
        shader.setMat4("model", model);

        glBindVertexArray(halfSphereVAO);
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
    unsigned int halfSphereVAO;
    unsigned int halfSphereVBO;
    unsigned int halfSphereEBO;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    void setUpHalfSphereVertexDataAndConfigureVertexAttribute() {
        const int sectorCount = 36;
        const int stackCount = 18;

        for (int i = 0; i <= stackCount; ++i) {
            float stackAngle = glm::pi<float>() / 2 - i * glm::pi<float>() / (2 * stackCount); // Half-sphere
            float radius = cos(stackAngle);
            float y = sin(stackAngle);

            for (int j = 0; j <= sectorCount; ++j) {
                float sectorAngle = j * 2 * glm::pi<float>() / sectorCount;
                float x = radius * cos(sectorAngle);
                float z = radius * sin(sectorAngle);

                vertices.push_back(x);
                vertices.push_back(y);
                vertices.push_back(z);

                vertices.push_back(x);
                vertices.push_back(y);
                vertices.push_back(z);

                float u = (float)j / sectorCount;
                float v = (float)i / stackCount;
                vertices.push_back(u);
                vertices.push_back(v);
            }
        }

        for (int i = 0; i < stackCount; ++i) {
            for (int j = 0; j < sectorCount; ++j) {
                int first = i * (sectorCount + 1) + j;
                int second = first + sectorCount + 1;
                indices.push_back(first);
                indices.push_back(second);
                indices.push_back(first + 1);
                indices.push_back(second);
                indices.push_back(second + 1);
                indices.push_back(first + 1);
            }
        }

        glGenVertexArrays(1, &halfSphereVAO);
        glGenBuffers(1, &halfSphereVBO);
        glGenBuffers(1, &halfSphereEBO);

        glBindVertexArray(halfSphereVAO);

        glBindBuffer(GL_ARRAY_BUFFER, halfSphereVBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, halfSphereEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)12);
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)24);
        glEnableVertexAttribArray(2);
    }
};
#endif // HALF_SPHERE_H
