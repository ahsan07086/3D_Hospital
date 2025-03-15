// wheel.h
// test
//
// Created by User on 19/01/2025.
//

#ifndef wheel_h
#define wheel_h

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include <GLFW/glfw3.h> // Include GLFW for handling input events

using namespace std;

class Wheel {
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
    Wheel(unsigned int tMap = 0, glm::vec3 amb = glm::vec3(1.0f, 0.5f, 0.3f),
        glm::vec3 diff = glm::vec3(1.0f, 0.5f, 0.3f),
        glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f),
        float shiny = 32.0f, glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f))
        : transform(glm::mat4(1.0f))
    {
        this->textureMap = tMap;
        this->ambient = amb;
        this->diffuse = diff;
        this->specular = spec;
        this->shininess = shiny;

        setUpWheelVertexDataAndConfigureVertexAttribute();
    }

    // Destructor
    ~Wheel()
    {
        glDeleteVertexArrays(1, &wheelVAO);
        glDeleteBuffers(1, &wheelVBO);
        glDeleteBuffers(1, &wheelEBO);
    }

    void draw(Shader& lightingShaderWithTexture, glm::mat4 model = glm::mat4(1.0f))
    {
        lightingShaderWithTexture.use();

        lightingShaderWithTexture.setInt("texUnit", 0);
        lightingShaderWithTexture.setVec3("material.ambient", this->ambient);
        lightingShaderWithTexture.setVec3("material.diffuse", this->diffuse);
        lightingShaderWithTexture.setVec3("material.specular", this->specular);
        lightingShaderWithTexture.setFloat("material.shininess", this->shininess);

        // Bind diffuse map
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->textureMap);
        transform = positionMatrix * rotationMatrix * scaleMatrix;
        model = model * transform;
        lightingShaderWithTexture.setMat4("model", model);

        glBindVertexArray(wheelVAO);
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
    void drawColor(Shader& lightingShaderWithTexture, glm::mat4 model = glm::mat4(1.0f))
    {
        lightingShaderWithTexture.use();

        lightingShaderWithTexture.setVec3("color", this->ambient);

        // Bind diffuse map
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->textureMap);

        lightingShaderWithTexture.setMat4("model", model);

        glBindVertexArray(wheelVAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

private:
    unsigned int wheelVAO;
    unsigned int wheelVBO;
    unsigned int wheelEBO;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    void setUpWheelVertexDataAndConfigureVertexAttribute()
    {
        // Set up the wheel's vertex data, buffers, and configure vertex attributes
        const int sectorCount = 36;
        const int stackCount = 18;

        for (int i = 0; i <= stackCount; ++i) {
            float stackAngle = glm::pi<float>() / 2 - i * glm::pi<float>() / stackCount;
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

        glGenVertexArrays(1, &wheelVAO);
        glGenBuffers(1, &wheelVBO);
        glGenBuffers(1, &wheelEBO);

        glBindVertexArray(wheelVAO);

        glBindBuffer(GL_ARRAY_BUFFER, wheelVBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, wheelEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)12);
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)24);
        glEnableVertexAttribArray(2);
    }
};
#endif /* cube_h */