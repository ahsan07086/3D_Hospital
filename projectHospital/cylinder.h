#ifndef CYLINDER_H
#define CYLINDER_H

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#define PI 3.141516

class Cylinder {
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
    Cylinder(unsigned int tMap, glm::vec3 amb = glm::vec3(1.0f, 0.5f, 0.3f),
        glm::vec3 diff = glm::vec3(1.0f, 0.5f, 0.3f),
        glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f),
        float shiny = 32.0f)
        : transform(glm::mat4(1.0f))
    {
        this->textureMap = tMap;
        this->ambient = amb;
        this->diffuse = diff;
        this->specular = spec;
        this->shininess = shiny;

        generateCylinderVerticesAndIndices();
        setupCylinderVAO();
    }

    // Destructor
    ~Cylinder()
    {
        glDeleteVertexArrays(1, &cylinderVAO);
        glDeleteBuffers(1, &cylinderVBO);
        glDeleteBuffers(1, &cylinderEBO);
    }

    void draw(Shader& shader, glm::mat4 model = glm::mat4(1.0f))
    {
        shader.use();

        //shader.setInt("texUnit", 0);
        shader.setVec3("material.ambient", this->ambient);
        shader.setVec3("material.diffuse", this->diffuse);
        shader.setVec3("material.specular", this->specular);
        shader.setFloat("material.shininess", this->shininess);

        // Bind diffuse map
        //glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->textureMap);

        transform = positionMatrix * rotationMatrix * scaleMatrix;
        model = model * transform;
        shader.setMat4("model", model);

        glBindVertexArray(cylinderVAO);
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
    unsigned int cylinderVAO;
    unsigned int cylinderVBO;
    unsigned int cylinderEBO;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    void generateCylinderVerticesAndIndices() {
        const int sectors = 36;       // Number of sectors (horizontal divisions)
        const float height = 2.0f;    // Height of the cylinder
        const float radius = 1.0f;    // Radius of the cylinder

        float sectorStep = 2 * PI / sectors;

        // Generate vertices for the top and bottom circles
        for (int i = 0; i <= sectors; ++i) {
            float angle = i * sectorStep;
            float x = radius * cos(angle);
            float z = radius * sin(angle);

            // Texture coordinates: (u, v)
            float u = (float)i / sectors;  // u varies along the circumference
            float vTop = 1.0f;             // v is 1.0 for the top circle
            float vBottom = 0.0f;          // v is 0.0 for the bottom circle

            // Top circle vertex
            vertices.push_back(x);        // x
            vertices.push_back(height / 2); // y
            vertices.push_back(z);        // z
            vertices.push_back(0.0f);     // Normal x
            vertices.push_back(1.0f);     // Normal y
            vertices.push_back(0.0f);     // Normal z
            vertices.push_back(u);        // Texture coordinate u
            vertices.push_back(vTop);     // Texture coordinate v

            // Bottom circle vertex
            vertices.push_back(x);        // x
            vertices.push_back(-height / 2); // y
            vertices.push_back(z);        // z
            vertices.push_back(0.0f);     // Normal x
            vertices.push_back(-1.0f);    // Normal y
            vertices.push_back(0.0f);     // Normal z
            vertices.push_back(u);        // Texture coordinate u
            vertices.push_back(vBottom);  // Texture coordinate v
        }

        // Generate indices for the side surface
        for (int i = 0; i < sectors; ++i) {
            int top1 = i * 2;
            int bottom1 = top1 + 1;
            int top2 = (i + 1) * 2;
            int bottom2 = top2 + 1;

            indices.push_back(top1);
            indices.push_back(bottom1);
            indices.push_back(top2);

            indices.push_back(bottom1);
            indices.push_back(bottom2);
            indices.push_back(top2);
        }
    }



    void setupCylinderVAO() {
        glGenVertexArrays(1, &cylinderVAO);
        glGenBuffers(1, &cylinderVBO);
        glGenBuffers(1, &cylinderEBO);

        glBindVertexArray(cylinderVAO);

        glBindBuffer(GL_ARRAY_BUFFER, cylinderVBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cylinderEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Normal attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // Texture coordinate attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
    }
};

#endif /* CYLINDER_H */
