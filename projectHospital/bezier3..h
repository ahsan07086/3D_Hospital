#pragma once
#ifndef BEZIER_H
#define BEZIER_H

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"

using namespace std;

class Bezier3 {
public:
    glm::vec4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;
    float shininess;

    // Constructor
    Bezier3(float cPoints[], int sz, glm::vec4 diff = glm::vec4(1.0f, 1.0f, 1.0f),
        glm::vec4 amb = glm::vec4(1.0f, 0.0f, 0.0f), glm::vec4 spec = glm::vec4(0.5f, 0.5f, 0.5f),
        float shiny = 32.0f)
        : ambient(amb), diffuse(diff), specular(spec), shininess(shiny) {

        for (int i = 0; i < sz; i++) {
            this->cntrlPoints.push_back(cPoints[i]);
        }

        bezierVAO = generateFan(cntrlPoints.data(), (unsigned int)(cntrlPoints.size() / 3) - 1);
    }

    // Destructor
    ~Bezier3() {}

    // Draw the generated Bezier fan shape
    void drawBezier(Shader& lightingShader, glm::mat4 model) const {
        lightingShader.use();
        lightingShader.setVec4("material.ambient", this->ambient);
        lightingShader.setVec4("material.diffuse", this->diffuse);
        lightingShader.setVec4("material.specular", this->specular);
        lightingShader.setFloat("material.shininess", this->shininess);

        lightingShader.setMat4("model", model);
        glBindVertexArray(bezierVAO);
        glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
        glBindVertexArray(0);
    }

    // Helper function to compute nCr (combination)
    long long nCr(int n, int r) {
        if (r > n / 2) r = n - r;
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans *= n - r + i;
            ans /= i;
        }
        return ans;
    }

    // Polynomial interpretation for N points in Bezier curve
    void BezierCurve(double t, float xy[2], GLfloat ctrlpoints[], int L) {
        double x = 0, y = 0;
        t = t > 1.0 ? 1.0 : t;
        for (int i = 0; i < L + 1; i++) {
            long long ncr = nCr(L, i);
            double oneMinusTpow = pow(1 - t, double(L - i));
            double tPow = pow(t, double(i));
            double coef = oneMinusTpow * tPow * ncr;
            x += coef * ctrlpoints[i * 3];
            y += coef * ctrlpoints[(i * 3) + 1];
        }
        xy[0] = float(x);
        xy[1] = float(y);
    }

    // Generate the fan-like Bezier shape
    unsigned int generateFan(GLfloat ctrlpoints[], int L) {
        int i, j;
        float x, y, z, r;
        float theta;
        float nx, ny, nz, lengthInv;

        const float dtheta = 2 * pi / ntheta;  // Angular step size

        float t = 0;
        float dt = 1.0 / nt;
        float xy[2];

        // Loop to generate the Bezier curves for the fan
        for (i = 0; i <= nt; ++i) {
            BezierCurve(t, xy, ctrlpoints, L);
            r = xy[0];   // radius
            y = xy[1];   // height
            theta = 0;
            t += dt;
            lengthInv = 1.0 / r;

            for (j = 0; j <= ntheta; ++j) {
                double cosa = cos(theta);
                double sina = sin(theta);
                z = r * cosa;
                x = r * sina;

                coordinates.push_back(x);
                coordinates.push_back(y);
                coordinates.push_back(z);

                nx = (x - 0) * lengthInv;  // Normal vector calculation
                ny = (y - y) * lengthInv;
                nz = (z - 0) * lengthInv;

                normals.push_back(nx);
                normals.push_back(ny);
                normals.push_back(nz);

                theta += dtheta;
            }
        }

        // Create the index list to generate the fan's triangles
        int k1, k2;
        for (int i = 0; i < nt; ++i) {
            k1 = i * (ntheta + 1);  // Current stack start
            k2 = k1 + ntheta + 1;   // Next stack start

            for (int j = 0; j < ntheta; ++j, ++k1, ++k2) {
                // Generate the fan's triangles for the fan shape
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }

        // Copy vertices and normals for rendering
        size_t count = coordinates.size();
        for (int i = 0; i < count; i += 3) {
            vertices.push_back(coordinates[i]);
            vertices.push_back(coordinates[i + 1]);
            vertices.push_back(coordinates[i + 2]);
            vertices.push_back(normals[i]);
            vertices.push_back(normals[i + 1]);
            vertices.push_back(normals[i + 2]);
        }

        // Generate the VAO, VBO, and EBO for the Bezier fan object
        unsigned int bezierVAO;
        glGenVertexArrays(1, &bezierVAO);
        glBindVertexArray(bezierVAO);

        unsigned int bezierVBO;
        glGenBuffers(1, &bezierVBO);
        glBindBuffer(GL_ARRAY_BUFFER, bezierVBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        unsigned int bezierEBO;
        glGenBuffers(1, &bezierEBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bezierEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)(sizeof(float) * 3));

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        return bezierVAO;
    }

    // Member variables
    const int nt = 40;  // Number of segments in the vertical direction
    const int ntheta = 20;  // Number of radial segments (fan segments)
    vector<float> cntrlPoints;
    vector<float> coordinates;
    vector<float> normals;
    vector<int> indices;
    vector<float> vertices;
    unsigned int bezierVAO;
    const double pi = 3.14159265389;
};

#endif // BEZIER_H
