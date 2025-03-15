//
//  main.cpp

//
//  
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "sphere.h"
#include "bezier2.h"
#include "sphere2.h"
#include "shader.h"
#include "camera.h"
#include "curve.h"
#include "basic_camera.h"
#include "directionalLight.h"
#include "pointLight.h"
#include "spotLight.h"
#include "wheel.h"
#include "stb_image.h"
#include "bezier.h"
#include "cylinder.h"
#include <iostream>
#include <stdlib.h>
#include<windows.h>  

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void sign_board(Shader& ourShader, glm::mat4 moveMatrix, glm::vec4 color);

void line_strip(Shader& ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void xray_lathi(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void pat_lathi(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void xray_danda(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void Lift(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void entrancegate(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void book_self(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void stool(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void MRI(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color, Sphere sphere);
void hospital(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void pat_bed(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void AC_1(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void sofa(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);


void mri_bed(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void xray_bed(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void pat_chair(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void computer(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void doc_table(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void danda(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void slide(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void staircase(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void baki_floor(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void glass_window(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void pillers(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void doc_chair(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void door(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window, Wheel& mywheel, Wheel& mywheel1,
    Wheel& mywheel2, Wheel& mywheel3);
void Bed(Shader ourshader, glm::mat4 moveMatrix);
void porda(Shader ourshader, glm::mat4 moveMatrix, glm::vec4 color);
void Chair(Shader ourShader, glm::mat4 moveMatrix);
void Floor(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void sperateWall(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void Fan1(Shader ourShader, glm::mat4 moveMatrix);
void drawCube(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color, float spec, float shininess);
void carpet(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void Boundary(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void outside_boundary(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void Gate(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color);
void GuardRoom(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color, unsigned int texture);
void Shop(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color, unsigned int texture);
void LampPost(Shader ourShader, glm::mat4 moveMatrix);
void load_texture(unsigned int& texture, string image_name, GLenum format, bool repeat);
// Function to generate a cylinder geometry (simplified version)
void generateCylinder(std::vector<float>& vertices, std::vector<unsigned int>& indices, float radius, float height, unsigned int sectors);
GLuint createBufferObject(std::vector<float>& data, GLenum usage) {
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], usage);
    return buffer;
}

GLuint createIndexBufferObject(std::vector<unsigned int>& indices, GLenum usage) {
    GLuint indexBuffer;
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], usage);
    return indexBuffer;
}


float angle = 90;
float angle1 = -90;
float transX1 = 0.0;
float wheelX1 = 0.0;
float wheelX2 = 0.0;
float wheelX3 = 0.0;
float wheelX4 = 0.0;


// settings
const unsigned int SCR_WIDTH = 1500;
const unsigned int SCR_HEIGHT = 800;

// modelling transform
float rotateAngle_X = 0.0;
float rotateAngle_Y = 0.0;
float rotateAngle_Z = 0.0;
float rotateAxis_X = 0.0;
float rotateAxis_Y = 0.0;
float rotateAxis_Z = 0.0;
float translate_X = 0.0;
float translate_Y = 0.0;
float translate_Z = 0.0;
float scale_X = 1.0;
float scale_Y = 1.0;
float scale_Z = 1.0;

float rotateAngleTest_Y = 0.0;

bool mriInside = false;
float mriTranslate = 0.0f;
float mriSpeed = 0.001f;
float mriRotateAngle = 0.0f;

bool isLiftOpening = false;
bool isLiftGoingUp = false;
float liftOpeningSpeed = 0.01f;
float liftOpenCurrent = 0.0f;
float liftUpCurrent = 0.0f;
float liftUpSpeed = 0.01f;

bool isgateOpening = false;

float gateOpeningSpeed = 0.01f;
float gateOpenCurrent = 0.0f;
float xraypos = 0;
float signxray = 1;

// camera               8.0   1.0   18.1
Camera camera(glm::vec3(5.0f, 5.0f, 40.1f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float eyeX = 0.0, eyeY = 1.0, eyeZ = 2.5;
float lookAtX = 0.0, lookAtY = 1.0, lookAtZ = 0.0;
glm::vec3 V = glm::vec3(0.0f, 1.0f, 0.0f);
BasicCamera basic_camera(eyeX, eyeY, eyeZ, lookAtX, lookAtY, lookAtZ, V);

// timing
float deltaTime = 0.0f;    // time between current frame and last frame
float lastFrame = 0.0f;


glm::vec3 lightPositions[] = {
        glm::vec3(-0.95f, 1.4f, -2.7f),         //Directional Light
        glm::vec3(10.1f, 1.28f, 14.37f),
        glm::vec3(14.5f, 4.30f, 8.2f)


};

glm::vec3 lightDirections[] = {
    glm::vec3(0.0f, -0.05f, 0.0f)
};


DirectionalLight directionalLight(-lightPositions[0], glm::vec4(0.4f, 0.4f, 0.4f, 1.0f), glm::vec4(0.9f, 0.9f, 0.9f, 1.0f), glm::vec4(0.2f, 0.2f, 0.2f, 0.2f), 1);
SpotLight spotLight(lightPositions[2], lightDirections[0], 8.5f, 15.5f, glm::vec4(0.2f, 0.2f, 0.2f, 1.0f), glm::vec4(0.5f, 0.5f, 0.5f, 1.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 1.0f, 0.0014f, 0.000007f, 1);
PointLight pointLight(lightPositions[1], glm::vec4(0.2f, 0.2f, 0.2f, 1.0f), glm::vec4(0.9f, 0.9f, 0.9f, 1.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 1.0f, 0.09f, 0.032f, 1);

// texture
float extra = 4.0f;
float TXmin = 0.0f;
float TXmax = 1.0f + extra;
float TYmin = 0.0f;
float TYmax = 1.0f + extra;



//rotate
bool isRotating = false;
float fanSpeed = 8.0f;

bool lightingOn = true;
float ambientOn = 1.0;
float diffuseOn = 1.0;
float specularOn = 1.0;
bool dark = false;

float directionalLightOn = 1.0;
float pointLightOn = 0.0;
float spotLightOn = 0.0;

glm::mat4 transforamtion(float tx = 0, float ty = 0, float tz = 0, float rx = 0, float ry = 0, float rz = 0, float sx = 1, float sy = 1, float sz = 1) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(tx, ty, tz));
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rx), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rz), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(sx, sy, sz));
    model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    return model;
}


// Textures
unsigned int texture0, texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8, texture9, texture10, texture11, texture12, texture13, texture14, texture15,texture16;
unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrappingModeS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrappingModeT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilteringModeMin);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilteringModeMax);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

//////////////tamim
glm::mat4 transform(float tr_x, float tr_y, float tr_z, float rot_x, float rot_y, float rot_z, float scal_x, float scal_y, float scal_z) {
    // Modelling Transformation
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(tr_x, tr_y, tr_z));
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rot_x), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rot_y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rot_z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(scal_x, scal_y, scal_z));
    model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    return model;
}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hospital-1907086", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
   
              // Position of the wheel;
    Wheel mywheel;
    Wheel mywheel1;
    Wheel mywheel2;
    Wheel mywheel3;

    // Apply transformations to the Wheel
    mywheel.setPosition(glm::vec3(12.66f+wheelX1, -0.3f, -2.94f)); // Move wheel to (1.0, 0.0, -2.0)
    mywheel.setScale(glm::vec3(0.06f, 0.06f, 0.06f));     // Scale the wheel 1.5x in all directions
    mywheel.setRotation(45.0f, glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate 45 degrees around Y-axis

             // Position of the wheel;
    // Apply transformations to the Wheel
    mywheel1.setPosition(glm::vec3(12.66f+wheelX2, -0.3f, -2.31f)); // Move wheel to (1.0, 0.0, -2.0)
    mywheel1.setScale(glm::vec3(0.06f, 0.06f, 0.06f));     // Scale the wheel 1.5x in all directions
    mywheel1.setRotation(45.0f, glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate 45 degrees around Y-axis


            // Position of the wheel;
    // Apply transformations to the Wheel
    mywheel2.setPosition(glm::vec3(10.97f+wheelX3, -0.4f, -2.31f)); // Move wheel to (1.0, 0.0, -2.0)
    mywheel2.setScale(glm::vec3(0.06f, 0.06f, 0.06f));     // Scale the wheel 1.5x in all directions
    mywheel2.setRotation(45.0f, glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate 45 degrees around Y-axis


             // Position of the wheel;
    // Apply transformations to the Wheel
    mywheel3.setPosition(glm::vec3(10.97f+wheelX4, -0.4f, -2.93f)); // Move wheel to (1.0, 0.0, -2.0)
    mywheel3.setScale(glm::vec3(0.06f, 0.06f, 0.06f));     // Scale the wheel 1.5x in all directions
    mywheel3.setRotation(45.0f, glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate 45 degrees around Y-axis

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("vertexShader.vs", "fragmentShader.fs");
    //Shader lightingShaderWithTexture("vertexShaderForPhongShadingWithTexture.vs", "fragmentShaderForPhongShadingWithTexture.fs");
    Shader lightCubeShader("lightVertexShader.vs", "lightFragmentShader.fs");
    //Shader ourShader2("vertexShader2.vs", "fragmnetShader2.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    string diffuseMapPathUni = "glass.jpg";
    string specularMapPathUni = "glass.jpg";




    unsigned int diffMap = loadTexture(diffuseMapPathUni.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap = loadTexture(specularMapPathUni.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);


    std::cout << "Diffuse Map Path: " << diffuseMapPathUni << std::endl;
    std::cout << "Specular Map Path: " << specularMapPathUni << std::endl;

    //// For axis
    //float axisVertices[] = {
    //    // X axis          // Color
    //    -1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,            //Red
    //    1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,

    //    // Y axis
    //    0.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f,            //Green
    //    0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,

    //    // Z axis
    //    0.0f, 0.0f, -1.0f,  0.0f, 0.0f, 1.0f,            //Blue
    //    0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f
    //};

    /*float cube_vertices[] = {
        0.0f, 0.0f, 0.0f, 0.3f, 0.8f, 0.5f,
        0.5f, 0.0f, 0.0f, 0.5f, 0.4f, 0.3f,
        0.5f, 0.5f, 0.0f, 0.2f, 0.7f, 0.3f,
        0.0f, 0.5f, 0.0f, 0.6f, 0.2f, 0.8f,
        0.0f, 0.0f, 0.5f, 0.8f, 0.3f, 0.6f,
        0.5f, 0.0f, 0.5f, 0.4f, 0.4f, 0.8f,
        0.5f, 0.5f, 0.5f, 0.2f, 0.3f, 0.6f,
        0.0f, 0.5f, 0.5f, 0.7f, 0.5f, 0.4f
    };*/
    /*float cube_vertices[] = {
        0.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.0f, 0.0f, 0.5f,
        0.5f, 0.0f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.0f, 0.5f, 0.5f
    };*/
    //silinder
    vector<float>wheel_vertices = {
    -0.7300, 2.3200, 5.1000,
    -0.7400, 2.1250, 5.1000,
    -0.7350, 1.9250, 5.1000,
    -0.7250, 1.6700, 5.1000,
    -0.7250, 1.4700, 5.1000,
    -0.7250, 1.2600, 5.1000,
    -0.7200, 1.0350, 5.1000
    };

    float cube_vertices[] = {
        // positions      // normals         // texture coords
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, TXmax, TYmin,
        0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, TXmin, TYmin,
        0.5f, 0.5f, 0.0f, 0.0f, 0.0f, -1.0f, TXmin, TYmax,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, -1.0f, TXmax, TYmax,

        0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, TXmax, TYmin,
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, TXmax, TYmax,
        0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, TXmin, TYmin,
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, TXmin, TYmax,

        0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f, TXmin, TYmin,
        0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f, TXmax, TYmin,
        0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, TXmax, TYmax,
        0.0f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, TXmin, TYmax,

        0.0f, 0.0f, 0.5f, -1.0f, 0.0f, 0.0f, TXmax, TYmin,
        0.0f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, TXmax, TYmax,
        0.0f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, TXmin, TYmax,
        0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, TXmin, TYmin,

        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, TXmax, TYmin,
        0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, TXmax, TYmax,
        0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, TXmin, TYmax,
        0.0f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, TXmin, TYmin,

        0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, TXmin, TYmin,
        0.5f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, TXmax, TYmin,
        0.5f, 0.0f, 0.5f, 0.0f, -1.0f, 0.0f, TXmax, TYmax,
        0.0f, 0.0f, 0.5f, 0.0f, -1.0f, 0.0f, TXmin, TYmax
    };
    unsigned int cube_indices[] = {
        0, 3, 2,
        2, 1, 0,

        4, 5, 7,
        7, 6, 4,

        8, 9, 10,
        10, 11, 8,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20
    };
    unsigned int cubeVAO, cubeVBO, cubeEBO;
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glGenBuffers(1, &cubeEBO);

    glBindVertexArray(cubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);

    // position attribute
   // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //vertex normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)12);
    glEnableVertexAttribArray(1);

    // texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)24);
    glEnableVertexAttribArray(2);

    //light's VAO
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);



    ////For Axis
    //unsigned int axisVBO, axisVAO;
    //glGenVertexArrays(1, &axisVAO);
    //glGenBuffers(1, &axisVBO);
    //glBindVertexArray(axisVAO);
    //glBindBuffer(GL_ARRAY_BUFFER, axisVBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(axisVertices), axisVertices, GL_STATIC_DRAW);
    //// position attribute
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);
    //// color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);





    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    //ourShader.use();



    // Texture loading

    //Texture 0
    glGenTextures(1, &texture0);
    glBindTexture(GL_TEXTURE_2D, texture0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("transparent.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        cout << "Failed to load texture 0" << endl;
    }
    stbi_image_free(data);


    load_texture(texture1, "floor2.jpg", GL_RGB, true);
    load_texture(texture2, "wall3.jpg", GL_RGB, true);
    load_texture(texture3, "wood.jpg", GL_RGB, true);
    load_texture(texture8, "curtain.jpg", GL_RGB, true);
    load_texture(texture4, "carpet.jpg", GL_RGB, true);
    load_texture(texture5, "concrete1.png", GL_RGBA, true);
    load_texture(texture6, "stair_upper.jpg", GL_RGB, true);
    load_texture(texture7, "concrete2.png", GL_RGBA, true);
    load_texture(texture9, "Wood.jpg", GL_RGB, true);
    load_texture(texture10, "stick.jpg", GL_RGB, true);
    load_texture(texture11, "sofa.jpg", GL_RGB, true);

    load_texture(texture12, "wood.jpg", GL_RGB, true);
    load_texture(texture13, "sky.jpg", GL_RGB, true);
    load_texture(texture14, "road.jpg", GL_RGB, true);
    load_texture(texture15, "bed.jpg", GL_RGB, true);
    load_texture(texture16, "white.jpg", GL_RGB, true);

    std::cout << "Texture16 ID: " << texture16 << std::endl;

    Sphere2  planet = Sphere2(1.0f, 144, 72, glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f), 32.0f, diffMap, specMap, 0.0f, 0.0f, 1.0f, 1.0f);
    Curve wheel(wheel_vertices, texture1, texture3, 1.0f);

    bool ok = 1;
    bool fine = 0;
    float rail = 0;


    float temp[] = {
-1.4700, 0.3500, 5.1000,
-1.0200, 0.3850, 5.1000,
-1.5250, 0.9400, 5.1000,
-1.0500, 0.9450, 5.1000,
-1.3700, 0.9750, 5.1000,
-1.2850, 1.0000, 5.1000,
-1.1600, 0.9850, 5.1000,
-1.5350, 0.8350, 5.1000,
-1.4650, 0.8400, 5.1000,
-1.3250, 0.8400, 5.1000,
-1.2250, 0.8350, 5.1000,
-1.0900, 0.8200, 5.1000,
-1.0900, 0.8050, 5.1000,
-1.3300, 0.7350, 5.1000,
-1.3650, 0.7250, 5.1000,
-1.4200, 0.7100, 5.1000,
-1.4450, 0.6100, 5.1000,
-1.2700, 0.6000, 5.1000,
-1.1750, 0.5750, 5.1000,
-1.0800, 0.6800, 5.1000,
-1.0850, 0.7850, 5.1000,
-1.1950, 0.7650, 5.1000,
-1.1200, 0.4950, 5.1000,
-1.1200, 0.4950, 5.1000,
-1.2200, 0.4400, 5.1000,
-1.3400, 0.4700, 5.1000,
-1.4200, 0.4450, 5.1000,
-1.4600, 0.5650, 5.1000,
-1.5400, 0.6850, 5.1000,
-1.5400, 0.7500, 5.1000,
-1.5450, 0.6350, 5.1000,
-1.5100, 0.4850, 5.1000,
-1.5200, 0.4100, 5.1000,
-1.5200, 0.3900, 5.1000,
-1.4250, 0.3600, 5.1000,
-1.4000, 0.3650, 5.1000,
-1.2700, 0.3700, 5.1000,
-1.1900, 0.3750, 5.1000,
-1.1400, 0.3800, 5.1000,
-1.1000, 0.3750, 5.1000,
-1.0800, 0.3950, 5.1000,
-1.0250, 0.4750, 5.1000,
-1.0450, 0.5150, 5.1000,
-1.0450, 0.5450, 5.1000,
-1.0400, 0.6250, 5.1000,
-1.0400, 0.7250, 5.1000,
-1.0150, 0.9100, 5.1000,
-1.0150, 0.9150, 5.1000,
-1.0200, 0.9800, 5.1000,
-1.4600, 1.0050, 5.1000,
    };

    
    float fanControlPoints[] = {
        // Number of spokes: 5
        // First spoke: from the center (0, 0) to a point at 0 degrees (smaller radius = 0.5) and a larger radius (thicker = 0.75)
        0.0f, 0.0f, 0.0f,  // Center point
        0.375f, 0.0f, 0.0f,  // Control point (smaller radius)
        0.75f, 0.0f, 0.0f,  // End point (larger radius for thickness)

        // Second spoke: from the center to a point at 72 degrees (smaller radius = 0.5) and larger radius (thicker = 0.75)
        0.0f, 0.0f, 0.0f,  // Center point
        0.309f, 0.0f, 0.951f,  // Control point (smaller radius, cos(72°) * 0.5)
        0.75f, 0.0f, 0.0f,  // End point (larger radius for thickness)

        // Third spoke: from the center to a point at 144 degrees (smaller radius = 0.5) and larger radius (thicker = 0.75)
        0.0f, 0.0f, 0.0f,  // Center point
        -0.404f, 0.0f, 0.809f, // Control point (smaller radius, cos(144°) * 0.5)
        0.75f, 0.0f, 0.0f,  // End point (larger radius for thickness)

        // Fourth spoke: from the center to a point at 216 degrees (smaller radius = 0.5) and larger radius (thicker = 0.75)
        0.0f, 0.0f, 0.0f,  // Center point
        -0.404f, 0.0f, -0.809f, // Control point (smaller radius, cos(216°) * 0.5)
        0.75f, 0.0f, 0.0f,  // End point (larger radius for thickness)

        // Fifth spoke: from the center to a point at 288 degrees (smaller radius = 0.5) and larger radius (thicker = 0.75)
        0.0f, 0.0f, 0.0f,  // Center point
        0.309f, 0.0f, -0.951f, // Control point (smaller radius, cos(288°) * 0.5)
        0.75f, 0.0f, 0.0f   // End point (larger radius for thickness)
    };

    

    


   




    Bezier temp2 = Bezier(temp, sizeof(temp) / sizeof(temp[0]), glm::vec3(1.0f, 1.0f, 1.0f));
    Sphere mri_wheel = Sphere(0.15);
    Cylinder cylinder(texture16);

    // Set transformations
    cylinder.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));   // Move cylinder 3 units back
    cylinder.setScale(glm::vec3(1.0f, 2.0f, 1.0f));       // Scale height by 2
    cylinder.setRotation(45.0f, glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate 45° around Y-axis

    Bezier fan(fanControlPoints, sizeof(fanControlPoints) / sizeof(fanControlPoints[0]));
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window, mywheel, mywheel1, mywheel2, mywheel3);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // activate shader
        ourShader.use();
        glBindVertexArray(cubeVAO);

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        //glm::mat4 projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        ////testing rotating around lookat point
        //const float radius = 2.0f;
        //float camX = sin(glfwGetTime()) * radius;
        //float camZ = cos(glfwGetTime()) * radius;
        //glm::mat4 view;
        //view = glm::lookAt(glm::vec3(camX, 1.0, camZ), glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 1.0, 0.0));

        // camera/view transformation
        //glm::mat4 view = basic_camera.createViewMatrix();
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);


        //**************lighting**************

        /*glm::vec3 lightColor;
        lightColor.x = sin(glfwGetTime() * 1.0f);
        lightColor.y = sin(glfwGetTime() * 0.35f);
        lightColor.z = sin(glfwGetTime() * 0.7f);
        glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);
        glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f);
        ourShader.setVec4("light.ambient", glm::vec4(ambientColor, 1.0f));
        ourShader.setVec4("light.diffuse", glm::vec4(diffuseColor, 1.0f));*/


        /*lightPositions[0].x = 1.0f + sin(glfwGetTime()) * 2.0f;
        lightPositions[0].y = sin(glfwGetTime() / 2.0f) * 1.0f;*/

        //Setting up Directional Light
        directionalLight.setUpLight(ourShader);
        if (!directionalLightOn)
            directionalLight.turnOff();
        if (!ambientOn)
            directionalLight.turnAmbientOff();
        if (!diffuseOn)
            directionalLight.turnDiffuseOff();
        if (!specularOn)
            directionalLight.turnSpecularOff();

        //Setting up Point Light
        pointLight.setUpLight(ourShader);
        if (!pointLightOn)
            pointLight.turnOff();
        if (!ambientOn)
            pointLight.turnAmbientOff();
        if (!diffuseOn)
            pointLight.turnDiffuseOff();
        if (!specularOn)
            pointLight.turnSpecularOff();

        //Setting up Spot Light
        spotLight.setUpLight(ourShader);
        if (!spotLightOn)
            spotLight.turnOff();
        if (!ambientOn)
            spotLight.turnAmbientOff();
        if (!diffuseOn)
            spotLight.turnDiffuseOff();
        if (!specularOn)
            spotLight.turnSpecularOff();

        //Setting up Camera and Others
        ourShader.setVec3("viewPos", camera.Position);
        ourShader.setBool("lightingOn", lightingOn);



        // Define light properties in main.cpp (example for a point light)
        glm::vec3 lightPos(1.0f, 1.0f, 1.0f);  // Example light position
        glm::vec3 lightAmbient(0.2f, 0.2f, 0.2f);  // Ambient light intensity
        glm::vec3 lightDiffuse(0.5f, 0.5f, 0.5f);  // Diffuse light intensity
        glm::vec3 lightSpecular(1.0f, 1.0f, 1.0f);  // Specular light intensity

        // Set these values in the shader
      
      

     

        ////For axis
        //ourShader.use();
        //glm::mat4 identity = glm::mat4(1.0f); // identity matrix
        //ourShader.setMat4("model", identity);
        //glBindVertexArray(axisVAO);
        //glDrawArrays(GL_LINES, 0, 6);use

        // Starting
        glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 translateMatrix, scaleMatrix, rotateYMatrix, rotateXMatrix;
        glm::vec4 color1;

        float chairZ = 0.4f;
        float fixY = 0.45f;
        float chairX = 0.1f;


        //********** Object making ***********
        //curvewheel
       /* translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0f, 2.0f, 5.0f));*/




        glBindTexture(GL_TEXTURE_2D, texture7);

        //// wall speration
        glm::mat4  model2, model;




        //Ground
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.80f, 2.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.35f, 0.2f, 1.42f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, texture1);
        Floor(ourShader, translateMatrix * scaleMatrix, color1);

        //entrance_front_wooden part

        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.9f, -0.4f, 15.05f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 4.6f, 0.2f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.7f, -0.4f, 15.05f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 4.6f, 0.2f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



        //front_wooden part
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.9f, 2.00f, 15.05f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.35f, 4.6f, 0.2f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(6.5f, 2.00f, 15.04f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 4.6f, 0.4f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0f, 2.00f, 15.04f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 4.6f, 0.4f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, 2.00f, 15.04f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 4.6f, 0.4f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0f, 2.00f, 15.04f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 4.6f, 0.4f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.5f, 2.00f, 15.04f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 4.6f, 0.4f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.5f, 2.00f, 15.04f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 4.6f, 0.4f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 2.00f, 15.04f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 4.6f, 0.4f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 2.00f, 15.04f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 4.6f, 0.4f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        ////////////////////////////////////////////////////////////////////

        //outside world

     /*   translateMatrix = glm::translate(identityMatrix, glm::vec3(-20.0f, -1.00f, -20.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(120.0f, 90.0f, 140.0f));
        glBindTexture(GL_TEXTURE_2D, texture0);
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.52f, 0.8f, 0.92f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.52f, 0.8f, 0.92f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);*/


        //outside world

        /*translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.00f, 0.05f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(50.35f, 50.6f, 50.2f));
        model = translateMatrix * rotateYMatrix * scaleMatrix;
        ourShader.setMat4("model", model);
        ourShader.setVec4("material.ambient", glm::vec4(0.52f, 0.8f, 0.92f, 0.5f));
        ourShader.setVec4("material.diffuse", glm::vec4(0.52f, 0.8f, 0.92f, 0.5f));
        ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
        ourShader.setFloat("material.shininess", 32.0f);
        glBindTexture(GL_TEXTURE_2D, texture12);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);*/

        //second_floor
        translateMatrix = glm::translate(identityMatrix, glm::vec3(4.5f, 1.7f, 2.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.73f, 0.2f, 0.98f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, texture1);
        Floor(ourShader, translateMatrix * scaleMatrix, color1);


        //third_floor
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 4.1f, 2.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.35f, 0.2f, 1.42f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, texture1);
        Floor(ourShader, translateMatrix * scaleMatrix, color1);

        //fourth_floor
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 8.9f, 2.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.2f, 0.92f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, texture1);
        //Floor(ourShader, translateMatrix* scaleMatrix, color1);

        //Barrier
        glm::mat4 rotateMatrix;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 5.8f, 21.3f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.35f, 0.2f, 0.1f));
        rotateMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, texture1);
        Floor(ourShader, translateMatrix* rotateMatrix* scaleMatrix, color1);
       

        //grass_floor
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-9.5f, -1.0f, 2.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.8f, 0.2f, 2.42f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, texture14);
        Floor(ourShader, translateMatrix * scaleMatrix, color1);





        // sperate wall
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -2.15f, 9.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, texture2);
        sperateWall(ourShader, translateMatrix, color1);
        //carpet

        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.2f, -2.145f, 2.0f));
        color1 = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);

        glBindTexture(GL_TEXTURE_2D, texture4);

        //carpet(ourShader, translateMatrix, color1);


        //Boundary
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        Boundary(ourShader, translateMatrix, color1);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 4.0f, 0.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Boundary(ourShader, translateMatrix, color1);
        //lift
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-4.4f, -0.5f, 0.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Lift(ourShader, translateMatrix, color1);

        //entrancegate
        //lift
        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.95f, -0.4f, 01.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        entrancegate(ourShader, translateMatrix, color1);

        /* translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
         color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);*/
         //Gate(ourShader, translateMatrix, color1);
         //Fan
         //Fan1(ourShader, translateMatrix);

         ////outside_boundary
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, -2.5f, 0.2f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, 0.5f, 2.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        outside_boundary(ourShader, scaleMatrix * translateMatrix, color1);



        //Guard Room
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f, 0.0f, 0.0f));
        color1 = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
        //GuardRoom(ourShader, translateMatrix, color1, texture3);


        //mri
        glActiveTexture(GL_TEXTURE0);
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 0.6f, 0.0f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.5f, 1.8f, -0.3f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.7f, 1.0f));
        temp2.drawBezier(ourShader, translateMatrix * scaleMatrix * rotateYMatrix * rotateXMatrix);
        


        glBindVertexArray(cubeVAO);
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, -0.6f, -1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.37f, 0.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        MRI(ourShader, translateMatrix * scaleMatrix * rotateYMatrix, color1, mri_wheel);



        //Shops
        glBindVertexArray(cubeVAO);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 0.0f, -2.0f));
        color1 = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
        //Shop(ourShader, translateMatrix, color1, texture5);

        glm::mat4 reflectionMatrix(1.0f);
        glm::vec3 normal(1.0f, 0.0f, 0.0f);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                reflectionMatrix[i][j] = (i == j) ? 1.0f - 2.0f * normal[i] * normal[j] : -2.0f * normal[i] * normal[j];
            }
        }
        glm::mat4 rotationMatrix;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-26.7f, 0.0f, -0.7f));
        rotationMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        color1 = glm::vec4(0.8f, 0.8f, 0.8f, 1.0f);
        Shop(ourShader, reflectionMatrix * translateMatrix , color1, texture6);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f, 0.0f, -6.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Shop(ourShader, translateMatrix, color1, texture7);

        //Lamp Posts
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.0f, 0.0f, -0.7f));
        LampPost(ourShader, translateMatrix);



      

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
        //drawCube(ourShader, translateMatrix, glm::vec4(1.0f), 0.5f, 32.0f);
        // 
        // 
        //Right side
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.9f+transX1, 0.23f, -3.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Bed(ourShader, translateMatrix * scaleMatrix);

       



        //table
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 0.0f, -1.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        //Chair(ourShader, translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.5f, 2.0f, -3.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Gate(ourShader, translateMatrix, color1);
        //Fan
        Fan1(ourShader, translateMatrix);

        //Porda

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.9f, -0.3f, -0.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        porda(ourShader, translateMatrix, color1);


        //Right side
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.9f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Bed(ourShader, translateMatrix * scaleMatrix);

        //Sphere mySphere(glm::vec3(0.8f, 0.8f, 0.8f), glm::vec3(0.7f, 0.2f, 0.1f), glm::vec3(0.2f, 0.2f, 0.2f), 32.0f);
        //table
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 0.0f, 2.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        //Chair(ourShader, translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.5f, 2.0f, 1.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        Gate(ourShader, translateMatrix, color1);
        //Fan
        Fan1(ourShader, translateMatrix);

        //porda
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.4f, -0.3f, 3.1f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //porda(ourShader, translateMatrix, color1);

        //door
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.67f + 12.33f, -0.4f, 1.4f + 7.61f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.80f, 1.23f, 1.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        door(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f)) * scaleMatrix, color1);


        //door

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.67f + 12.34f, -0.4f, 1.4f + 5.6f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.79f, 1.23f, 1.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        door(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(angle1), glm::vec3(0.0f, 1.0f, 0.0f)) * scaleMatrix, color1);


        //door
        translateMatrix = glm::translate(identityMatrix, glm::vec3(4.6f + 9.6f, 2.35f - 0.42f, 1.4f + 7.6f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        door(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f)) * scaleMatrix, color1);


        //door
        translateMatrix = glm::translate(identityMatrix, glm::vec3(4.6f + 9.6f, 2.35f - 0.42f, 1.4f + 0.6f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        door(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f)) * scaleMatrix, color1);


        //door
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.6f + 9.6f, 2.35f - 0.42f, 1.4f + 0.6f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        door(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f)) * scaleMatrix, color1);


        //Right side
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.2f, 0.0f, 4.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        //Bed(ourShader, translateMatrix * scaleMatrix);

        //table
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 0.0f, 5.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Chair(ourShader, translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.6f, 2.0f, 4.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Gate(ourShader, translateMatrix, color1);
        //Fan
        Fan1(ourShader, translateMatrix);

        //porda
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.4f, -0.3f, 6.1f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //porda(ourShader, translateMatrix, color1);



        //Right side dorjar por
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.8f, 0.1f, 10.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Bed(ourShader, translateMatrix * scaleMatrix);

        //table
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 0.0f, 11.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Chair(ourShader, translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.0f, 2.0f, 10.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Gate(ourShader, translateMatrix, color1);
        //Fan
        Fan1(ourShader, translateMatrix);

        //porda
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.8f, -0.3f, 9.2f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        porda(ourShader, translateMatrix, color1);












        //left side
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(16.0f, 0.0f, -3.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Bed(ourShader, translateMatrix * scaleMatrix);

        //table
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.0f, 0.0f, -1.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        //Chair(ourShader, translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.0f, 2.0f, -3.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Gate(ourShader, translateMatrix, color1);
        //Fan
        Fan1(ourShader, translateMatrix);

        //Porda

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(16.4f, -0.3f, -0.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        porda(ourShader, translateMatrix, color1);


        //left side
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(19.7f, 1.8f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        //Bed(ourShader, translateMatrix * scaleMatrix);

        //table
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(19.5f, 0.0f, 2.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Chair(ourShader, translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.0f, 2.0f, 1.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Gate(ourShader, translateMatrix, color1);
        //Fan
        Fan1(ourShader, translateMatrix);
        //porda
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(16.4f, -0.3f, 3.1f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //porda(ourShader, translateMatrix, color1);

        //left side
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(19.8f, 0.8f, 4.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Bed(ourShader, translateMatrix * scaleMatrix);

        //table
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.0f, 0.0f, 5.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        //Chair(ourShader, translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.0f, 2.0f, 4.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Gate(ourShader, translateMatrix, color1);
        //Fan
        Fan1(ourShader, translateMatrix);

        //porda
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(16.4f, -0.3f, 6.1f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        porda(ourShader, translateMatrix, color1);

        //left side dorjar por
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(16.0f, 0.0f, 10.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        Bed(ourShader, translateMatrix * scaleMatrix);

        //table
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.0f, 0.0f, 11.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 1.1f, 1.5f));
        //Chair(ourShader, translateMatrix * scaleMatrix);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.0f, 0.0f, 10.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //Gate(ourShader, translateMatrix, color1);
        //Fan
        //Fan1(ourShader, translateMatrix);
        //porda
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(16.4f, -0.3f, 9.2f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        //baki_floor
        glBindTexture(GL_TEXTURE_2D, texture0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.2f, 0.2f, 12.5f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.9f, 1.7f, -3.9f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        baki_floor(ourShader, translateMatrix * scaleMatrix, color1);

        //baki_floor
        glBindTexture(GL_TEXTURE_2D, texture0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.2f, 0.2f, 12.5f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.9f, 1.7f, 10.4f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        baki_floor(ourShader, translateMatrix * scaleMatrix, color1);

        //staircase

        glBindTexture(GL_TEXTURE_2D, texture0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.0f, 0.0f, 1.5f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //staircase(ourShader, translateMatrix, color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.3f, 0.35f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //staircase(ourShader, translateMatrix, color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.6f, 0.7f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // staircase(ourShader, translateMatrix, color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.9f, 1.05f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //staircase(ourShader, translateMatrix, color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -1.2f, 1.40f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // staircase(ourShader, translateMatrix, color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -1.5f, 1.75f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //staircase(ourShader, translateMatrix, color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -1.8f, 2.1f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // staircase(ourShader, translateMatrix, color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -2.1f, 2.45f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // staircase(ourShader, translateMatrix, color1);

        //slide
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.9f, 0.15f, 1.67f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //slide(ourShader, translateMatrix, color1);

        //danda



      


        /*glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.9f, 0.1f, 3.9f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        danda(ourShader, translateMatrix* glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);*/


        /*glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-4.5f, 0.1f, 12.8f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        danda(ourShader, translateMatrix, color1);*/

        /*glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-4.5f, 0.1f, 13.8f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        danda(ourShader, translateMatrix, color1);*/








        //doc_table

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0f, 0.0f, -2.2f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        doc_table(ourShader, translateMatrix, color1);

        //reception
        glBindTexture(GL_TEXTURE_2D, texture0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.3f, 1.0f, 1.0f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.5f, 0.0f, 4.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        doc_table(ourShader, scaleMatrix * translateMatrix, color1);

        //pat_chair




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 0.0f, 2.5f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 0.0f, 1.5f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        //computer




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.5f, .4f, 4.8f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //computer(ourShader, translateMatrix, color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, .4f, 4.8f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //computer(ourShader, translateMatrix, color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0f, .4f, 3.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //computer(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0f, .4f, 1.5f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // computer(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);

        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 1.9f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(6.4f, 0.0f, 2.77f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        doc_table(ourShader, scaleMatrix * translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        //computer




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.4f, 2.9f, 4.5f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //computer(ourShader, glm::rotate(identityMatrix, glm::radians(40.0f), glm::vec3(0.0f, 1.0f, 0.0f)) * translateMatrix, color1);

        //pat_chair




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0f, 2.55f, 0.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 2.55f, 0.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);



        // //pat_chair single




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.7f, 2.55f, 13.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.7f, 2.55f, 12.0f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);



        ///upper class chair

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0f, 2.55f, 5.3f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 2.55f, 5.3f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);



        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 2.55f, 5.3f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.0f, 2.55f, 5.3f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0f, 2.55f, 5.6f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 2.55f, 5.6f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 2.55f, 5.6f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0f, 2.55f, 5.6f));

        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
       // pat_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);


        //sofa

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-01.8f, -0.5f, 11.3f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //sofa(ourShader, translateMatrix, color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.75f, 2.0f, 04.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //sofa(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0f, -0.5f, 5.3f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        sofa(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0f, -0.5f, 8.3f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        sofa(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);


        //sofa

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-01.8f, -0.5f, 8.3f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        sofa(ourShader, translateMatrix, color1);

        //AC_1
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.55f, 3.5f, -1.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //AC_1(ourShader, translateMatrix, color1);

        //AC_1
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.6f, 3.5f, -1.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //AC_1(ourShader, translateMatrix, color1);

        //AC_1
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.55f, 3.5f, 10.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //AC_1(ourShader, translateMatrix, color1);

        //AC_1
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.6f, 3.5f, 10.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //AC_1(ourShader, translateMatrix, color1);

        //pat_bed




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.2f, 2.3f, -2.2f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pat_bed(ourShader, translateMatrix, color1);

        //pat_bed single
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.2f, 2.3f, 10.2f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pat_bed(ourShader, translateMatrix, color1);

        //mri_bed




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.2f, 0.0f, -1.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        mri_bed(ourShader, translateMatrix, color1);

        //xray_bed




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(14.2f, 2.8f, 11.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        xray_bed(ourShader, translateMatrix, color1);

        //hospital




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0f, 4.5f, 22.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 2.0f, 2.1f));
        color1 = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
        hospital(ourShader, translateMatrix * scaleMatrix, color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(2.8f, 2.5f, 30.65f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2f, 1.0f, 1.0f));
        color1 = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
        hospital(ourShader, translateMatrix * scaleMatrix, color1);

        //bookself





        //bookself -xray




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(17.5f, 2.1f, 12.3f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //book_self(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);


        //bookself -room




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(11.0f, 2.1f, 12.3f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //book_self(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);


        //xray_danda

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(14.5f, 3.9f + xraypos, 12.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        xray_danda(ourShader, translateMatrix, color1);

        //xray_lathi




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(15.8f, 1.8f, 12.1f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        xray_lathi(ourShader, translateMatrix, color1);


        //pat_lathi




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.95f, 2.7f, 12.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pat_lathi(ourShader, translateMatrix, color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.95f, 2.7f, 10.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pat_lathi(ourShader, translateMatrix, color1);

        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.95f, 2.7f, 10.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pat_lathi(ourShader, translateMatrix, color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.95f, 2.7f, 12.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pat_lathi(ourShader, translateMatrix, color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 0.45f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(8.95f, 2.7f, 11.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pat_lathi(ourShader, translateMatrix * scaleMatrix, color1);


        glBindTexture(GL_TEXTURE_2D, texture0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.0f, 0.45f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(7.95f, 2.7f, 11.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pat_lathi(ourShader, translateMatrix * scaleMatrix, color1);
        //stool - mri





        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(12.5f, 2.05f, -1.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //stool(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(40.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        //stool - xray






        //stool - single





       
        //sign_board




        glBindTexture(GL_TEXTURE_2D, texture0);
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(17.0f, 2.3f, 2.45f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-8.5f, 2.2f, 30.5f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        sign_board(ourShader, translateMatrix * scaleMatrix, color1);

        //ambulance
        glBindTexture(GL_TEXTURE_2D, texture0);






        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //ambulance(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(0.0f + ambx), glm::vec3(0, 1.0f, 0)), color1, mri_wheel);

        //ambulance




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(21.0f, 0.0f, 13.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //ambulance(ourShader, translateMatrix, color1, mri_wheel);

        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(3.0f, 0.0f, 25.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix, color1);

        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(6.0f, 0.0f, 25.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix, color1);


        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 0.0f, 25.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix, color1);


        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(12.0f, 0.0f, 25.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix, color1);


        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(15.0f, 0.0f, 25.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix, color1);


        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(18.0f, 0.0f, 25.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix, color1);


        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(21.0f, 0.0f, 25.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix, color1);

        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.0f, 0.0f, 25.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix, color1);


        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(30.0f, 0.0f, 20.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(30.0f, 0.0f, 15.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(30.0f, 0.0f, 10.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        //line_strip
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(30.0f, 0.0f, 5.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //line_strip(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);

        //ambulance




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(21.0f, 0.0f, 8.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        // ambulance(ourShader, translateMatrix, color1, mri_wheel);

         //ambulance




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(21.0f, 0.0f, 3.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        //ambulance(ourShader, translateMatrix, color1, mri_wheel);

        //ambulance




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(21.0f, 0.0f, -2.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 21.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);

        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0f, 0.0f, 21.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);


        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 0.0f, 21.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);


        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(15.0f, 0.0f, 21.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);


        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(20.0f, 0.0f, 21.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);


        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.0f, 0.0f, 21.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);


        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.0f, 0.0f, 16.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);

        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.0f, 0.0f, 11.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);

        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.0f, 0.0f, 6.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);

        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.0f, 0.0f, 1.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);

        //pillers
        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(24.0f, 0.0f, -4.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        pillers(ourShader, translateMatrix, color1);

        //glass_window




        glBindTexture(GL_TEXTURE_2D, texture0);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        glass_window(ourShader, translateMatrix, color1);

        //doc_chair
        glBindTexture(GL_TEXTURE_2D, texture0);

        translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 0.0f, -3.3f));
        color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        doc_chair(ourShader, translateMatrix * glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), color1);


        ////tamim
          //glBindTexture(GL_TEXTURE_2D, texture2);
          //model2 = transform(3, 2, 5, 90, 0, 0, 1, 1, 1);
          //wheel.draw(lightCubeShader, model2, glm::vec3(1.0f, 1.0f, 1.0f));

        //model2 = transform(3, 2, 5, 90, 0, 0, .5, .5, .5);
        //wheel.draw(ourShader, model2, glm::vec3(1.0f, 1.0f, 1.0f));

        //sphere
        lightCubeShader.use();
        lightCubeShader.setMat4("projection", projection);
        glm::mat4 view2 = camera.GetViewMatrix();
        lightCubeShader.setMat4("view", view2);

        float time = glfwGetTime();
        float rotationSpeed = 0.1f;
        glm::mat4 modelMatrixForContainer2 = glm::mat4(1.0f);

         modelMatrixForContainer2 = glm::translate(model, glm::vec3(-0.45f, -0.4f, -2.8f));
        glBindTexture(GL_TEXTURE_2D, texture3);
        modelMatrixForContainer2 = transforamtion(5.0, .75, 0.0, 0, 5 * time + rotationSpeed, 0, .4, .12, .4);
         planet.drawSphereWithTexture(lightCubeShader, modelMatrixForContainer2);

         mywheel.draw(lightCubeShader,glm::mat4(1.0f));
         mywheel1.draw(lightCubeShader, glm::mat4(1.0f));
         mywheel2.draw(lightCubeShader, glm::mat4(1.0f));
         mywheel3.draw(lightCubeShader, glm::mat4(1.0f));

         glm::mat4 modelFan = glm::mat4(1.0f);
         // Create and update the model matrix
         modelFan = glm::scale(modelFan, glm::vec3(0.5f, 1.0f, 0.5f)); // Scale
         modelFan = glm::rotate(modelFan, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate
         modelFan = glm::translate(modelFan, glm::vec3(0.0f,0.0f,0.0f)); // Translate

         // Pass the updated model matrix to the shader
         
         lightCubeShader.setMat4("model", model);
         //fan.drawBezier(lightCubeShader, modelFan);
         glm::mat4 modelCylinder = glm::mat4(1.0f);
         cylinder.draw(lightCubeShader);




        modelMatrixForContainer2 = transforamtion(5.0, .75, 0.0, 0, 5 * time + rotationSpeed, 0, .4, .12, .4);
       // planet.drawSphereWithTexture(lightCubeShader, modelMatrixForContainer2);





        //********* END of Object Making **********

        //Lights
        lightCubeShader.use();




        for (int i = 1; i <= 2; i++)
        {

            /*glm::vec3 lightColor;
            lightColor.x = sin(glfwGetTime() * 1.0f);
            lightColor.y = sin(glfwGetTime() * 0.35f);
            lightColor.z = sin(glfwGetTime() * 0.7f);
            glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);
            lightCubeShader.setVec4("bodyColor", glm::vec4(diffuseColor, 1.0f));*/

            glm::vec4 bodyColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

            //emissive
            glm::vec3 val = glm::vec3(0.5f);
            if (i == 1 and pointLightOn == 0.0)
                bodyColor = glm::vec4(val, 1.0f);
            if (i == 2 and spotLightOn == 0.0)
                bodyColor = glm::vec4(val, 1.0f);
            /*if (i == 4 and spotLightOn == 0.0)
                bodyColor = glm::vec4(val, 1.0f);*/


            lightCubeShader.setVec4("bodyColor", bodyColor);
            glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
            lightCubeShader.setMat4("projection", projection);
            glm::mat4 view = camera.GetViewMatrix();
            lightCubeShader.setMat4("view", view);
            glm::mat4 tempModel = glm::mat4(1.0f);
            tempModel = glm::translate(tempModel, lightPositions[i]);
            tempModel = glm::scale(tempModel, glm::vec3(0.5f));
            lightCubeShader.setMat4("model", tempModel);

            glBindVertexArray(lightCubeVAO);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        }


        // render boxes
        //for (unsigned int i = 0; i < 10; i++)
        //{
        //    // calculate the model matrix for each object and pass it to shader before drawing
        //    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        //    model = glm::translate(model, cubePositions[i]);
        //    float angle = 20.0f * i;
        //    model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        //    ourShader.setMat4("model", model);

        //    glDrawArrays(GL_TRIANGLES, 0, 36);
        //}

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteBuffers(1, &cubeVBO);
    glDeleteBuffers(1, &cubeEBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------


float sign = 1, movemribed = 0;
float sign2 = 1, patbedangle = 0;

void processInput(GLFWwindow* window, Wheel& mywheel, Wheel& mywheel1,Wheel& mywheel2, Wheel& mywheel3)
{

    if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS) /// Move MRI BED
    {
        movemribed += sign * 0.01;

        if (movemribed > 0)
            sign *= -1;
        if (movemribed < -1.5)
            sign *= -1;

    }

    if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS) /// Move MRI BED
    {
        xraypos += signxray * 0.01;

        if (xraypos > .3)
            signxray *= -1;
        if (xraypos < -.5)
            signxray *= -1;

    }


    if (glfwGetKey(window, GLFW_KEY_SEMICOLON) == GLFW_PRESS) /// Move MRI BED
    {
        patbedangle += 1 * sign2;

        if (patbedangle >= 45)
            sign2 *= -1;
        if (patbedangle <= 0)
            sign2 *= -1;

    }

    if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS) 
    {
        transX1 += 0.01;
        wheelX1 += 0.01;
        wheelX2 += 0.01;
        wheelX3 += 0.01;
        wheelX4 += 0.01;
        mywheel.setPosition(glm::vec3(12.66f + wheelX1, -0.3f, -2.94f));
        mywheel1.setPosition(glm::vec3(12.66f + wheelX2, -0.3f, -2.31f));
        mywheel2.setPosition(glm::vec3(10.97f + wheelX3, -0.4f, -2.31f)); 
        mywheel3.setPosition(glm::vec3(10.97f + wheelX4, -0.4f, -2.93f));
        cout << wheelX1 << endl;
    }


    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {                 //Forward
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {                 //Backward
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {                 //Left
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {                 //Right
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)                   //Door open-close
    {
        angle -= 1;
        angle = min(angle, 90);
        angle1 += 1;
        angle1 = min(angle1, 00);

    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)                   //Door open-close
    {
        angle += 1;
        angle = min(angle, 00);

    }

    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)                   //Door open-close
    {

        isLiftGoingUp ^= true;


    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)                   //Down
    {
        /*if (rotateAxis_X) rotateAngle_X -= 0.1;
        else if (rotateAxis_Y) rotateAngle_Y -= 0.1;
        else rotateAngle_Z -= 0.1;*/

        camera.ProcessKeyboard(DOWN, deltaTime);


    }

    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)                   //Pitch positive
    {
        /*rotateAngle_X += 1;
        rotateAxis_X = 1.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 0.0;*/
        camera.ProcessYPR(0.0f, 3.0f, 0.0f);
    }
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)                   //Pitch negative
    {
        /*rotateAngle_X += 1;
        rotateAxis_X = 1.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 0.0;*/
        camera.ProcessYPR(0.0f, -3.0f, 0.0f);
    }

    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)                   //Yaw positive
    {
        /*rotateAngle_Y += 1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 1.0;
        rotateAxis_Z = 0.0;*/
        camera.ProcessYPR(3.0f, 0.0f, 0.0f);
    }
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)                   //Yaw negative
    {
        /*rotateAngle_Y += 1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 1.0;
        rotateAxis_Z = 0.0;*/
        camera.ProcessYPR(-3.0f, 0.0f, 0.0f);
    }

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)                   //Roll positive
    {
        /*rotateAngle_Z += 0.1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 1.0;*/
        camera.ProcessYPR(0.0f, 0.0f, 0.5f);

    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)                   //Roll negative
    {
        /*rotateAngle_Z += 0.1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 1.0;*/
        camera.ProcessYPR(0.0f, 0.0f, -0.5f);

    }

    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
        eyeX += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)                   //Rotate camera around a look at point
    {                                                                   //Right
        /*eyeX -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);*/
        camera.RotateAroundLookAt(2.0f);
    }
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)                   //Rotate camera around a look at point
    {                                                                   //Left
        /*eyeX -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);*/
        camera.RotateAroundLookAt(-2.0f);
    }

    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    {
        eyeZ += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)                   //Rotate Fan
    {
        /*eyeZ -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);*/
        isRotating ^= true;
        cout << isRotating << endl;

        Sleep(100);
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        eyeY += 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)                   //Up
    {
        eyeY -= 2.5 * deltaTime;
        basic_camera.changeEye(eyeX, eyeY, eyeZ);

        camera.ProcessKeyboard(UP, deltaTime);

    }

    //***************Lighting***************

    //if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)                   //Lighting On-Off
    //{
    //    lightingOn ^= true;
    //    cout << lightingOn << endl;
    //    Sleep(100);
    //}
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)                   //Ambient On
    {
        ambientOn = 1.0;
        pointLight.turnAmbientOn();
        spotLight.turnAmbientOn();
        directionalLight.turnAmbientOn();
    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)                   //Ambient Off
    {
        ambientOn = 0.0;
        pointLight.turnAmbientOff();
        spotLight.turnAmbientOff();
        directionalLight.turnAmbientOff();
    }

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)                   //Diffuse On
    {
        diffuseOn = 1.0;
        pointLight.turnDiffuseOn();
        spotLight.turnDiffuseOn();
        directionalLight.turnDiffuseOn();

    }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)                   //Diffuse Off
    {
        diffuseOn = 0.0;
        pointLight.turnDiffuseOff();
        spotLight.turnDiffuseOff();
        directionalLight.turnDiffuseOff();
    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)                   //Specular On
    {
        specularOn = 1.0;
        pointLight.turnSpecularOn();
        spotLight.turnSpecularOn();
        directionalLight.turnSpecularOn();
    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)                   //Specular Off
    {
        specularOn = 0.0;
        pointLight.turnSpecularOff();
        spotLight.turnSpecularOff();
        directionalLight.turnSpecularOff();
    }
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)                   //Point Light On
    {
        pointLightOn = 1.0;
        pointLight.turnOn();
    }
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)                   //Point Light Off
    {
        pointLightOn = 0.0;
        pointLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)                   //Directional Light On
    {
        directionalLightOn = 1.0;
        directionalLight.turnOn();
    }
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)                   //Directional Light Off
    {
        directionalLightOn = 0.0;
        directionalLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)                   //Spot Light On
    {
        spotLightOn = 1.0;
        spotLight.turnOn();
    }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)                   //Spot Light Off
    {
        spotLightOn = 0.0;
        spotLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)                   //Dark On-Off
    {
        dark ^= true;
        cout << dark << endl;
        Sleep(100);
    }





    //if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)               //Basic Camera rotate around lookat
    //{
    //    //lookAtX += 2.5 * deltaTime;
    //    //basic_camera.changeLookAt(lookAtX, lookAtY, lookAtZ);
    //    float change = -0.3f;
    //    float x, y, z;
    //    x = eyeX * cos(glm::radians(change)) + eyeZ * sin(glm::radians(change));
    //    y = eyeY;
    //    z = - eyeX * sin(glm::radians(change)) + eyeZ * cos(glm::radians(change));

    //    eyeX = x, eyeY = y, eyeZ = z;
    //    basic_camera.changeEye(eyeX, eyeY, eyeZ);
    //}
    //if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    //{
    //    //lookAtX -= 2.5 * deltaTime;
    //    //basic_camera.changeLookAt(lookAtX, lookAtY, lookAtZ);

    //    float change = 0.3f;
    //    float x, y, z;
    //    x = eyeX * cos(glm::radians(change)) + eyeZ * sin(glm::radians(change));
    //    y = eyeY;
    //    z = -eyeX * sin(glm::radians(change)) + eyeZ * cos(glm::radians(change));

    //    eyeX = x, eyeY = y, eyeZ = z;
    //    basic_camera.changeEye(eyeX, eyeY, eyeZ);
    //}
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        lookAtY += 2.5 * deltaTime;
        basic_camera.changeLookAt(lookAtX, lookAtY, lookAtZ);
    }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    {
        lookAtY -= 2.5 * deltaTime;
        basic_camera.changeLookAt(lookAtX, lookAtY, lookAtZ);
    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        lookAtZ += 2.5 * deltaTime;
        basic_camera.changeLookAt(lookAtX, lookAtY, lookAtZ);
    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
    {
        lookAtZ -= 2.5 * deltaTime;
        basic_camera.changeLookAt(lookAtX, lookAtY, lookAtZ);
    }
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
    {
        basic_camera.changeViewUpVector(glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
    {
        basic_camera.changeViewUpVector(glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
    {
        basic_camera.changeViewUpVector(glm::vec3(0.0f, 0.0f, 1.0f));
    }

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}


//Texture Loading

void load_texture(unsigned int& texture, string image_name, GLenum format, bool repeat)
{
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (repeat) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
    else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(image_name.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        cout << "Failed to load texture " << image_name << endl;
    }
    stbi_image_free(data);
}

//OBJECTS

void drawCube(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), float spec = 1.0f, float shininess = 32.0f)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateYMatrix;

    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngleTest_Y), glm::vec3(0.0f, 1.0f, 0.0f));

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-1.0f, 1.0f, 1.0f));
    model = translateMatrix * rotateYMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", color * spec);
    ourShader.setFloat("material.shininess", shininess);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
void door(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateYMatrix;

    glBindTexture(GL_TEXTURE_2D, texture10);
    //Left Side
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.4f, 4.0f, 0.2f));
    model = translateMatrix * rotateYMatrix * scaleMatrix;

    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // 9.6 9.95
    // -0.42 0.45
    // 7.6 7.575

    glBindTexture(GL_TEXTURE_2D, texture9);
    //glass
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-9.6 + 9.95f, +0.42 + 0.45f, -7.6 + 7.575f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 1.2f, 0.3f));
    //glm::mat4 translate2 = glm::translate(identityMatrix, glm::vec3(-9.95f, -0.45f, -7.575f));
    model = translateMatrix * rotateYMatrix * scaleMatrix;



    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //glBindTexture(GL_TEXTURE_2D, texture7);
    ///*translateMatrix = glm::translate(identityMatrix, glm::vec3(7.1f, -0.42f, 7.5f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, 3.2f, 0.2f));
    //model = translateMatrix * scaleMatrix;*/
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-angle + 180), glm::vec3(0.0f, 1.0f, 0.0f));
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(7.1f, -0.42f, 7.5f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.5f, 3.2f, 0.2f));
    //model = translateMatrix * rotateYMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", color);
    //ourShader.setVec4("material.diffuse", color);
    //ourShader.setVec4("material.specular", color * 0.5f);
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


}

//mri
void MRI(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color, Sphere sphere)
{

    /*if ((-1.0 - camera.Position.z) <= 0 && (3.0 - camera.Position.z) >= 0 && (camera.Position.x - 5.0) <= 4.0 && (camera.Position.x - 5.0) >= 0.0)
    {
        mriInside = true;
    }
    else
    {
        mriInside = false;
    }
    cout << mriInside << endl;*/
    if (mriInside)
    {
        mriRotateAngle += mriSpeed;
        mriTranslate += (0.15 * glm::radians(mriRotateAngle));
        mriTranslate = min(mriTranslate, 3.0);
    }
    else
    {
        mriRotateAngle += mriSpeed;
        mriTranslate -= (0.15 * glm::radians(mriRotateAngle));
        mriTranslate = max(mriTranslate, 0.0);
    }

    //cout << glm::radians(mriRotateAngle) << endl;
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateXMatrix;
    //moveable
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(2.0f - mriTranslate, 4.1f, 10.25f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0f, 0.3f, 3.0f));
    //ourShader.setMat4("model", moveMatrix * translateMatrix * scaleMatrix);
    //ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);

    ////glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //base
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5f, 3.1f, 9.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 1.7f, 6.0f));
    ourShader.setMat4("model", moveMatrix * translateMatrix * scaleMatrix);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //fr
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5f, 3.1f, 12.4f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 2.5f, 0.2f));
    ourShader.setMat4("model", moveMatrix * translateMatrix * scaleMatrix);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //bc
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5f, 3.1f, 9.4f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 2.5f, 0.2f));
    ourShader.setMat4("model", moveMatrix * translateMatrix * scaleMatrix);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    ////leg
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0f - mriTranslate, 3.3f, 10.7f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 1.6f, 0.1f));
    //ourShader.setMat4("model", moveMatrix * translateMatrix * scaleMatrix);
    //ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);

    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0f - mriTranslate, 3.3f, 11.3f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 1.6f, 0.1f));
    //ourShader.setMat4("model", moveMatrix * translateMatrix * scaleMatrix);
    //ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);

    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0f - mriTranslate, 3.2f, 10.7f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.1f, 1.0f));
    //ourShader.setMat4("model", moveMatrix * translateMatrix * scaleMatrix);
    //ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);

    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0f - mriTranslate, 3.2f, 11.3f));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(0.0f + mriRotateAngle), glm::vec3(1.0f, 0.0f, 0.0f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 2.5f, 0.2f));
    //ourShader.setMat4("model", moveMatrix * translateMatrix);
    //ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);

    //sphere.drawSphere(ourShader);


}

void porda(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateYMatrix;


    // nicher danda
   // rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.1f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.2f, 1.8f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", 0.5f, 0.5f, 0.5f, 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //lomba danda
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.3f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", 0.5f, 0.5f, 0.5f, 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //plane danda
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 1.6f, 0.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 0.1f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", 0.5f, 0.5f, 0.5f, 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // nicher danda
   // rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.45f, -0.1f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.2f, 1.8f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", 0.5f, 0.5f, 0.5f, 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //lomba danda
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.45f, 0.0f, 0.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 3.3f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", 0.5f, 0.5f, 0.5f, 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //choto danda
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 1.45f, 0.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 0.3f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", 0.5f, 0.5f, 0.5f, 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.25f, 1.45f, 0.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 0.3f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", 0.5f, 0.5f, 0.5f, 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //cloth

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.152f, 0.3f, 0.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.4f, 2.4f, 0.1f));
    glBindTexture(GL_TEXTURE_2D, texture8);
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", 0.5f, 0.5f, 0.5f, 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


}

void Bed(Shader ourShader, glm::mat4 moveMatrix)
{

    float tableY = 0.02f;
    float tableY1 = -0.13;
    // Top
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f + tableY, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.4f, 0.1f, 1.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.97f, 0.94f, 0.94f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.97f, 0.94f, 0.94f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.97f, 0.94f, 0.94f, 1.0f));
    ourShader.setFloat("material.shininess", 128.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // Leg 1
    glm::mat4 identityMatrix1 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix1, scaleMatrix1, model1;
    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.02f, -0.46f + tableY1, 0.01f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.1f, 1.3f, 0.1f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // Leg 2
    glm::mat4 identityMatrix2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix2, scaleMatrix2, model2;
    translateMatrix2 = glm::translate(identityMatrix2, glm::vec3(0.02f, -0.46f + tableY1, 0.43f));
    scaleMatrix2 = glm::scale(identityMatrix2, glm::vec3(0.1f, 1.3f, 0.1f));
    model2 = translateMatrix2 * scaleMatrix2;
    ourShader.setMat4("model", moveMatrix * model2);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // Leg 3
    //glm::mat4 translateMatrix1, rotateXMatrix1, rotateYMatrix1, rotateZMatrix1, scaleMatrix1, model1;
    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(1.15f, -0.46f + tableY, 0.01f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.1f, 1.0f, 0.1f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // Leg 4
    //glm::mat4 translateMatrix2, rotateXMatrix2, rotateYMatrix2, rotateZMatrix2, scaleMatrix2, model2;
    translateMatrix2 = glm::translate(identityMatrix2, glm::vec3(1.15f, -0.46f + tableY, 0.43f));
    scaleMatrix2 = glm::scale(identityMatrix2, glm::vec3(0.1f, 1.0f, 0.1f));
    model2 = translateMatrix2 * scaleMatrix2;
    ourShader.setMat4("model", moveMatrix * model2);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    // top 1

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.02f, 0.05f + tableY, 0.48f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, .4f, 0.05f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.02f, 0.05f + tableY, 0.30f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, .4f, 0.05f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.02f, 0.05f + tableY, 0.20f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, .4f, 0.05f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // top 2

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(1.15f, 0.05f + tableY, 0.01f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, .4f, 0.05f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(1.15f, 0.05f + tableY, 0.30f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, .4f, 0.05f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(1.15f, 0.05f + tableY, 0.20f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, .4f, 0.05f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // top 3

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(1.15f, 0.05f + tableY, 0.48f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, .4f, 0.05f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // top 4

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.02f, 0.05f + tableY, 0.01f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, .4f, 0.05f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //Top flat1

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.02f, .25f + tableY, 0.0f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, 0.05f, 1.015f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.02f, .08f + tableY, 0.0f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, 0.05f, 1.015f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //down flat1

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.02f, -.35f + tableY, 0.0f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, 0.05f, 1.015f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //Top flat2

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(1.15f, .25f + tableY, 0.0f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, 0.05f, 1.015f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(1.15f, .08f + tableY, 0.0f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, 0.05f, 1.015f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //dowb flat2

    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(1.15f, -.35f + tableY, 0.0f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.05f, 0.05f, 1.015f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.26f, 0.26f, 0.25f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Chair(Shader ourShader, glm::mat4 moveMatrix)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    float fixLeg = 0.7f;
    float fixY = 0.1f;
    float fixYWhole = -0.08f;

    // Top
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.11f, 0.2f - fixY + fixYWhole, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.75f, 0.07f, 1.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.9f, 0.3f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.9f, 0.3f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // Leg 1
    glm::mat4 identityMatrix1 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix1, scaleMatrix1, model1;
    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.13f, -0.32f + fixYWhole, 0.00f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.07f, 1.25f * fixLeg, 0.07f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    ourShader.setVec4("material.ambient", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // Leg 2
    glm::mat4 identityMatrix2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix2, scaleMatrix2, model2;
    translateMatrix2 = glm::translate(identityMatrix2, glm::vec3(0.13f, -0.32f + fixYWhole, 0.45f));
    scaleMatrix2 = glm::scale(identityMatrix2, glm::vec3(0.07f, 1.25f * fixLeg, 0.07f));
    model2 = translateMatrix2 * scaleMatrix2;
    ourShader.setMat4("model", moveMatrix * model2);
    /*ourShader.setVec4("material.ambient", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);*/
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //// Leg 3
    //glm::mat4 translateMatrix1, rotateXMatrix1, rotateYMatrix1, rotateZMatrix1, scaleMatrix1, model1;
    translateMatrix1 = glm::translate(identityMatrix1, glm::vec3(0.43f, -0.32f + fixYWhole, 0.01f));
    scaleMatrix1 = glm::scale(identityMatrix1, glm::vec3(0.07f, 1.25f * fixLeg, 0.07f));
    model1 = translateMatrix1 * scaleMatrix1;
    ourShader.setMat4("model", moveMatrix * model1);
    /*ourShader.setVec4("material.ambient", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);*/
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // Leg 4
    //glm::mat4 translateMatrix2, rotateXMatrix2, rotateYMatrix2, rotateZMatrix2, scaleMatrix2, model2;
    translateMatrix2 = glm::translate(identityMatrix2, glm::vec3(0.43f, -0.32f + fixYWhole, 0.45f));
    scaleMatrix2 = glm::scale(identityMatrix2, glm::vec3(0.07f, 1.25f * fixLeg, 0.07f));
    model2 = translateMatrix2 * scaleMatrix2;
    ourShader.setMat4("model", moveMatrix * model2);
    /*ourShader.setVec4("material.ambient", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);*/
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    ////Left up 
    //translateMatrix2 = glm::translate(identityMatrix2, glm::vec3(0.17f, 0.01f - fixY + fixYWhole, 0.29f));
    //scaleMatrix2 = glm::scale(identityMatrix2, glm::vec3(0.07f, 0.25f, 0.07f));
    //model2 = translateMatrix2 * scaleMatrix2;
    //ourShader.setMat4("model", moveMatrix * model2);
    //ourShader.setVec4("material.ambient", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    ////Right up
    //translateMatrix2 = glm::translate(identityMatrix2, glm::vec3(0.39f, 0.01f - fixY + fixYWhole, 0.29f));
    //scaleMatrix2 = glm::scale(identityMatrix2, glm::vec3(0.07f, 0.25f, 0.07f));
    //model2 = translateMatrix2 * scaleMatrix2;
    //ourShader.setMat4("model", moveMatrix * model2);
    //ourShader.setVec4("material.ambient", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(0.9f, 0.9f, 1.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    ////Back support
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15f, 0.09f - fixY + fixYWhole, 0.28f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 0.5f, 0.1f));
    //model = translateMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", glm::vec4(0.9f, 0.3f, 1.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(0.9f, 0.3f, 1.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Floor(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.9f, 1.10f, -6.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(43.3f, 1.2f, 40.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}


void doc_chair(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 0.30f, 1.20f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //choto
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20f, 0.65f, 1.20f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //helen
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15f, 0.27f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20f, 1.65f, 1.20f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(10.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = rotateZMatrix * translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // handles

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.33f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.4f, 0.1f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.7f, 0.13f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.5f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.33f, 0.54f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.4f, 0.1f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.7f, 0.13f, 0.54f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.5f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //nicher part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.4f, -0.26f, 0.28f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.7f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, -0.3f, 0.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2f, 0.2f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.42f, -0.3f, 0.05f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.2f, 1.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



}


void doc_table(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;
    //upper part
    glBindTexture(GL_TEXTURE_2D, texture10);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.2f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.5f, 0.2f, 2.5f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //lower part
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, -0.5f, 0.05f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 1.5f, 2.3f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



}

void pat_chair(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture11);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 0.10f, 1.20f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //danda
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.10f, 0.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.10f, 0.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // leg danda

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, -0.50f, 0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.10f, 1.00f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, -0.50f, 0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.10f, 1.00f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //nicer support
    //danda
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, -0.45f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.10f, 0.10f, 1.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, -0.45f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.10f, 0.10f, 1.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, -0.45f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 0.10f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.42f, 0.45f, 0.65f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //bach support

    glBindTexture(GL_TEXTURE_2D, texture11);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.2f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, 0.70f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


}


void mri_bed(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //upor part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 6.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.27f, 0.0f, 1.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.80f, 0.7f, 0.80f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.22f, -0.3f, 1.2f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.7f, 1.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.3f, 0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 4.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //upper part first of blue
    glBindTexture(GL_TEXTURE_2D, texture15);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.35f, 0.0f + movemribed));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 6.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);




}

void xray_danda(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.5f, 0.0f, 0.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.50f, 0.50f, 0.50f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.2f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 0.7f, 0.7f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture5);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05f, -0.02f, 0.25f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5f, 0.5f, 0.5f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05f, 0.015f, 0.4f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 0.2f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture5);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05f, 0.02f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.1f, 1.5f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void xray_bed(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {
    //glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    ////upor part
    //glBindTexture(GL_TEXTURE_2D, texture0);
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.3f, 0.0f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 6.00f));
    //model = translateMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", color);
    //ourShader.setVec4("material.diffuse", color);
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    ////last main part
    //glBindTexture(GL_TEXTURE_2D, texture0);
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.27f, 0.0f, 1.3f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.80f, 0.7f, 0.80f));
    //model = translateMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", color);
    //ourShader.setVec4("material.diffuse", color);
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //glBindTexture(GL_TEXTURE_2D, texture0);
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.22f, -0.3f, 1.2f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.7f, 1.1f));
    //model = translateMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", color);
    //ourShader.setVec4("material.diffuse", color);
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //glBindTexture(GL_TEXTURE_2D, texture0);
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.3f, 0.5f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 4.00f));
    //model = translateMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", color);
    //ourShader.setVec4("material.diffuse", color);
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    ////upper part first of blue
    //glBindTexture(GL_TEXTURE_2D, texture15);
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.35f, 0.0f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 6.00f));
    //model = translateMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", color);
    //ourShader.setVec4("material.diffuse", color);
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //upor part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 6.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.27f, 0.0f, 1.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.80f, 0.7f, 0.80f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.22f, -0.3f, 1.2f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.7f, 1.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.3f, 0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 4.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //upper part first of blue
    glBindTexture(GL_TEXTURE_2D, texture15);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.35f, 0.0f + movemribed));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 6.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);





}

void sofa(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;


    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.2f, -3.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.4f, 6.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture11);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.4f, -2.8f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.4f, 5.65f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //upor part
    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 1.7f, .30f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.005f, 0.355f, -01.8f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.5f, .05f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.005f, 0.355f, -00.8f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.5f, .05f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture6);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.001f, 0.0f, -2.84f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.10f, 1.7f, 5.65f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 1.7f, .30f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}


void AC_1(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //upor part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.00f, 0.7f, 2.50f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.90f, 0.1f, 2.50f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.1f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.00f, 0.1f, 2.50f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void pat_bed(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //upor part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 6.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.27f, 0.0f, 1.3f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.80f, 0.7f, 0.80f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.22f, -0.3f, 1.2f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.7f, 1.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.3f, 0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 4.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //upper part first of blue
    glBindTexture(GL_TEXTURE_2D, texture15);

    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.35f, 0.0f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 2.00f));
    //model = translateMatrix * glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f)) * scaleMatrix;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.35f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, -2.00f));
    model = translateMatrix * glm::rotate(glm::mat4(1.0f), glm::radians(patbedangle), glm::vec3(1.0f, 0.0f, 0.0f)) * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //upper part first of blue
    glBindTexture(GL_TEXTURE_2D, texture15);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.35f, 1.1f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 0.150f, 3.60f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);




}

void hospital(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //H----------------
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.2f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //0------------

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.2f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, 0.6f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    //s-----------------

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.55f, 0.6f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.55f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.55f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.55f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 0.8f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.91f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 0.8f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    //p-------------------------

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.2f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.2f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.2f, 0.6f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.55f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 0.8f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //I----------------------------

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.85f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //T----------------

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.15f, 0.6f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.35f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //A--------------------

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.9f, 0.6f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 1.0f, 0.0f, 0.5f)); // Green
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 1.0f, 0.0f, 0.5f)); // Green
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f)); // Specular remains same
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.9f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 1.0f, 0.0f, 0.5f)); // Green
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 1.0f, 0.0f, 0.5f)); // Green
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.9f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 1.0f, 0.0f, 0.5f)); // Green
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 1.0f, 0.0f, 0.5f)); // Green
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.3f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 1.0f, 0.0f, 0.5f)); // Green
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 1.0f, 0.0f, 0.5f)); // Green
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //L-------------------------

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.6f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.30f, 1.50f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.6f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.1f, 0.30f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix* model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);




}
void book_self(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //thak
    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.50f, .10f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //books

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05f, 0.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15f, 0.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 0.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.25f, 0.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.3f, 0.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //books upore
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 1.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05f, 1.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15f, 1.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 1.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.25f, 1.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.3f, 1.05f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //thak
    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, .5f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.50f, .10f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //thak
    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.50f, .10f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //thak
    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 1.45f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.50f, .10f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    //side
    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.10f, 3.00f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //side
    glBindTexture(GL_TEXTURE_2D, texture12);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.25f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.10f, 3.00f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //books




    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.2f, 0.55f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.15f, 0.55f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.10f, 0.55f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.05f, 0.55f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.0f, 0.55f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.14f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.95f, 0.55f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .70f, 1.00f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.38f, 0.11f, 0.18f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void stool(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)

{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //thak
    glBindTexture(GL_TEXTURE_2D, texture10);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05f, 0.1f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, .10f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //thak
    glBindTexture(GL_TEXTURE_2D, texture10);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05f, 0.3f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, .10f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //thak
    glBindTexture(GL_TEXTURE_2D, texture10);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05f, 0.55f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5f, .10f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //side
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.8f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.10f, 1.50f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //side
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.10f, 1.50f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void entrancegate(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    //if ((13.5f - camera.Position.z) <= 2.0f && (13.5f - camera.Position.z) >= 0 && camera.Position.x > 10.1 && camera.Position.x < 1.0)
    if (camera.Position.z >= 13.593 && camera.Position.z <= 17.6216 && camera.Position.x > 7.2 && camera.Position.x < 8.3)
    {
        isgateOpening = true;
    }
    else
    {
        isgateOpening = false;
    }

    if (isgateOpening)
    {
        gateOpenCurrent += gateOpeningSpeed;
        gateOpenCurrent = min(gateOpenCurrent, 2.7f);
    }
    else
    {
        gateOpenCurrent -= gateOpeningSpeed;
        gateOpenCurrent = max(gateOpenCurrent, 0.0f);
    }
    //cout << gateOpenCurrent << ' ' << camera.Position.x << ' ' << camera.Position.z << endl;
   /* if (isLiftGoingUp)
    {
        liftUpCurrent += liftUpSpeed;
        liftUpCurrent = min(liftUpCurrent, 2.35f);
    }*/
    //main part
    glBindTexture(GL_TEXTURE_2D, texture10);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.7f - gateOpenCurrent, 0.0f, 13.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.95f, 5.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindTexture(GL_TEXTURE_2D, texture10);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.7f + gateOpenCurrent, 0.0f, 13.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-2.95f, 5.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //choto glass
    glBindTexture(GL_TEXTURE_2D, texture9);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(4.7f - gateOpenCurrent, 1.0f, 13.45f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.95f, 1.5f, 0.38f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindTexture(GL_TEXTURE_2D, texture9);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.7f + gateOpenCurrent, 1.0f, 13.45f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-0.95f, 1.5f, 0.38f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}

void Lift(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;
    //left side
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.7f, 0.0f, 13.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 9.1f, 3.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //right side
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.7f, 0.0f, 13.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 9.1f, 3.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //open

    //cout << camera.Position.x <<"   "<< camera.Position.z << endl;
    //if((13.5f - camera.Position.z) <= 3.0f && (13.5f - camera.Position.z) >= 0 && camera.Position.x > -0.1 && camera.Position.x < 3.0)
   

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.7f, 0.0f, 13.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.95f - liftOpenCurrent, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.7f, 0.0f, 13.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-2.95f + liftOpenCurrent, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    ///////////////////

    ///////////////


    //base
    glBindTexture(GL_TEXTURE_2D, texture11);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.7f, 0.05f + liftUpCurrent, 13.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 0.4f, 3.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    ////2nd floor
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(3.7f, 3.0f, 13.5f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.97f, 3.5f - liftOpenCurrent, 0.2f));
    //model = translateMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", color);
    //ourShader.setVec4("material.diffuse", color);
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(6.7f, 3.0f, 13.5f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(-2.97f, 3.5f + liftOpenCurrent, 0.2f));
    //model = translateMatrix * scaleMatrix;
    //ourShader.setMat4("model", moveMatrix * model);
    //ourShader.setVec4("material.ambient", color);
    //ourShader.setVec4("material.diffuse", color);
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


}



void pat_lathi(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.25f, 0.0f, 0.25f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.050f, .20f, 0.050f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.25f, 0.08f, 0.25f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.050f, .050f, 1.550f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.25f, 0.0f, .5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.050f, .20f, 0.050f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.25f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.050f, .20f, 0.050f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.25f, 0.0f, 0.75f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.050f, .20f, 0.050f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void xray_lathi(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.25f, 0.0f, 0.25f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20f, 4.00f, 0.20f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.00f, 0.10f, 1.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.2f, 2.0f, 0.2f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.50f, 0.10f, 0.50f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


}


void line_strip(Shader& ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, -0.6f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.20f, .10f, 8.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



}

void sign_board(Shader& ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.6f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.00f, 1.00f, 0.10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}
/**void ambulance(Shader& ourShader, glm::mat4 moveMatrix, glm::vec4 color, Sphere& sphere)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.00f, 3.00f, 4.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    // front choto part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.79f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.00f, 1.30f, 4.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // front choto part
    //glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.25f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 2.30f, 4.00f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //tilt part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.1f, 0.9f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.30f, 0.10f, 4.00f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(40.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = rotateZMatrix * translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // red light

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.1f, 0.9f, 0.15f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.30f, 1.0f, 3.4f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    // plus

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.97f, 0.83f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 1.0f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.8f, 0.95f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2f, 0.5f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // lal danda

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.8f, 0.3f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.85f, 0.2f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // black danda

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.8f, 0.23f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.85f, 0.05f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.08f, 1.35f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.05f, 0.05f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.8f, 0.0f, -0.005f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.85f, 0.25f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // side windows
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.4f, 0.82f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.2f, 1.0f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.1f, 0.82f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 1.0f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // head lights

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.82f, 0.09f, 0.149f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.3f, 0.6f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.75f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.75f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.82f, 0.09f, 1.55f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.3f, 0.6f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 0.75f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 0.75f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // back windows

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.72f, 0.225f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 1.2f, 1.0f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.72f, 1.195f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 1.2f, 1.0f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // back black danda
    ;

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.4f, 0.95f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 1.91f, 0.05f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.4f, 1.75f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 1.91f, 0.05f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.4f, 1.95f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 1.91f, 0.05f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.4f, 0.15f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 1.91f, 0.05f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.4f, 0.02f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 1.91f, 0.05f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.961f, 0.169f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //back handle
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.62f, 0.57f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 0.09f, 0.3f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.31f, 0.62f, 1.175f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 0.09f, 0.3f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //side drivers window


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.29f, 1.0f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.85f, 0.1f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.082f, 0.253f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 1.5f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.7f, 0.253f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 0.8f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.17f, 0.65f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.4f, 0.6f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.52f, 0.80f, .98f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.17f, 0.5f, -0.015f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.05f, 4.1f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //////wheel
    //translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 0.7f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(0.0f + mriRotateAngle), glm::vec3(1.0f, 0.0f, 0.0f));
    //scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 2.5f, 0.2f));
    //ourShader.setMat4("model", moveMatrix* translateMatrix);
    //ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    //ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    //ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    //ourShader.setFloat("material.shininess", 32.0f);

    //sphere.drawSphere(ourShader);



}*/

void computer(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.1f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 1.00f, .10f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.175f, 0.05f, -0.01f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.20f, 0.80f, .05f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.43f, -0.07f, 0.02f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.15f, 0.35f, .05f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.37f, -0.1f, 0.01f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.35f, 0.1f, .25f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


}


void danda(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;
    //stick
    glBindTexture(GL_TEXTURE_2D, texture10);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.3f, 2.0f, -0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.10f, 1.5f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //upor danda

    glBindTexture(GL_TEXTURE_2D, texture5);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.3f, 2.75f, -0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.2f, 2.0f));

    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}
void slide(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last main part
    glBindTexture(GL_TEXTURE_2D, texture6);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.8f, 0.0f, -3.1f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(35.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.50f, 0.30f, 10.00f));
    model = rotateZMatrix * translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void staircase(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //big part
    glBindTexture(GL_TEXTURE_2D, texture5);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.38f, -0.5f, -0.8f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.00f, 5.04f, 0.80f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //upor part
    glBindTexture(GL_TEXTURE_2D, texture6);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.38f, 2.0f, -0.8f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.00f, 0.1f, 0.85f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //stick
    glBindTexture(GL_TEXTURE_2D, texture10);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.38f, 2.0f, -0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.10f, 1.5f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, texture10);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.3f, 2.0f, -0.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.10f, 1.5f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //upor danda

    glBindTexture(GL_TEXTURE_2D, texture5);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.3f, 1.75f, -2.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.2f, 1.3f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(40.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = rotateZMatrix * translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    glBindTexture(GL_TEXTURE_2D, texture5);

    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.375f, 1.75f, -2.5f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.2f, 1.3f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(40.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = rotateZMatrix * translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.0f, 0.0f, 0.0f, 0.5f));
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


}
void baki_floor(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last 
    glBindTexture(GL_TEXTURE_2D, texture1);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 1.10f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.00f, 1.20f, 0.50f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
void glass_window(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color) {

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //last 
    glBindTexture(GL_TEXTURE_2D, texture3);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.1f, 2.35f, -4.12f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.00f, 3.20f, 0.50f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //side 
    glBindTexture(GL_TEXTURE_2D, texture3);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.1f, 2.35f, -4.12f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.50f, 3.20f, 38.90f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //front

    glBindTexture(GL_TEXTURE_2D, texture3);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, 2.35f, 14.92f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0f, 3.20f, 0.70f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}
// Function to generate a cylinder geometry (simplified version)
void generateCylinder(std::vector<float>& vertices, std::vector<unsigned int>& indices, float radius, float height, unsigned int sectors)
{
    // Top and Bottom Circle
    float angleStep = 2 * glm::pi<float>() / sectors;

    // Vertices for top and bottom
    for (unsigned int i = 0; i < sectors; ++i)
    {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Top circle (centered at (0, height/2, 0))
        vertices.push_back(x); vertices.push_back(height / 2); vertices.push_back(z);  // Position
        vertices.push_back(x); vertices.push_back(0.0f); vertices.push_back(z);  // Normal

        // Bottom circle (centered at (0, -height/2, 0))
        vertices.push_back(x); vertices.push_back(-height / 2); vertices.push_back(z);  // Position
        vertices.push_back(x); vertices.push_back(0.0f); vertices.push_back(z);  // Normal
    }

    // Side faces (connecting top and bottom circles)
    for (unsigned int i = 0; i < sectors; ++i)
    {
        unsigned int next = (i + 1) % sectors;

        // Side vertices for each face
        indices.push_back(i * 2);     indices.push_back(next * 2);     indices.push_back(i * 2 + 1);
        indices.push_back(i * 2 + 1); indices.push_back(next * 2);     indices.push_back(next * 2 + 1);
    }
}


void pillers(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // Initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    // Last main part
    glBindTexture(GL_TEXTURE_2D, texture0);

    // First pillar (upper part)
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, -0.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 9.2f, 1.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    // Set material properties to white
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));  // White
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));  // White
    ourShader.setVec4("material.specular", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)); // White
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // Second pillar (lower part)
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-0.1f, -0.5f, -0.1f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.3f, 3.2f, 1.3f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    // Set material properties to white
    ourShader.setVec4("material.ambient", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));  // White
    ourShader.setVec4("material.diffuse", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));  // White
    ourShader.setVec4("material.specular", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)); // White
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}



void sperateWall(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(10.7f, 1.25f + 0.45f, -13.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.15f, 5.0f, 22.07f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(10.7f, 1.25f + 0.45f, -0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.15f, 8.7f, 12.07f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    translateMatrix = glm::translate(identityMatrix, glm::vec3(10.7f, 1.25f + 2.95f, -2.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.15f, 3.6f, 7.07f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void Fan1(Shader ourShader, glm::mat4 moveMatrix)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateToPivot, translateFromPivot, rotateYMatrix, scaleMatrix, model, moveModel;
    glm::vec4 translateToPivotOrg, translateFromPivotOrg;
    glm::vec3 pivot;

    //Handle
    moveModel = glm::translate(identityMatrix, glm::vec3(0.0f, 1.77f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 0.5f, 0.1f));
    model = moveModel * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    if (isRotating)
    {
        rotateAngle_Y += fanSpeed;
        rotateAngle_Y = fmod(rotateAngle_Y, 360);
    }



    //Center
    pivot = glm::vec3(0.25, 0.25, 0.25);

    translateToPivotOrg = glm::vec4(-pivot, 0.0f);
    translateFromPivotOrg = glm::vec4(pivot, 0.0f);

    moveModel = glm::translate(identityMatrix, glm::vec3(-0.1f, 1.65f, -0.1f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5f, 0.3f, 0.5f));

    translateToPivotOrg = scaleMatrix * translateToPivotOrg;
    translateFromPivotOrg = scaleMatrix * translateFromPivotOrg;
    translateToPivot = glm::translate(identityMatrix, glm::vec3(translateToPivotOrg));
    translateFromPivot = glm::translate(identityMatrix, glm::vec3(translateFromPivotOrg));

    model = moveModel * translateFromPivot * rotateYMatrix * translateToPivot * scaleMatrix;
    //model = moveModel * rotateYMatrix * scaleMatrix;
    //model =  translateFromPivot * rotateYMatrix * translateToPivot;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.2f, 1.0f, 0.2f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.2f, 1.0f, 0.2f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //One hand

    translateToPivotOrg = glm::vec4(-pivot, 0.0f);
    translateFromPivotOrg = glm::vec4(pivot, 0.0f);

    moveModel = glm::translate(identityMatrix, glm::vec3(-0.65f, 1.67f, -0.05f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.8f, 0.1f, 0.3f));

    translateToPivotOrg = scaleMatrix * translateToPivotOrg;
    translateFromPivotOrg = scaleMatrix * translateFromPivotOrg;
    translateToPivot = glm::translate(identityMatrix, glm::vec3(translateToPivotOrg));
    translateFromPivot = glm::translate(identityMatrix, glm::vec3(translateFromPivotOrg));

    model = moveModel * translateFromPivot * rotateYMatrix * translateToPivot * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.2f, 0.2f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.2f, 0.2f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //Second hand

    translateToPivotOrg = glm::vec4(-pivot, 0.0f);
    translateFromPivotOrg = glm::vec4(pivot, 0.0f);

    moveModel = glm::translate(identityMatrix, glm::vec3(-0.05f, 1.67f, -0.65f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.3f, 0.1f, 2.8f));

    translateToPivotOrg = scaleMatrix * translateToPivotOrg;
    translateFromPivotOrg = scaleMatrix * translateFromPivotOrg;
    translateToPivot = glm::translate(identityMatrix, glm::vec3(translateToPivotOrg));
    translateFromPivot = glm::translate(identityMatrix, glm::vec3(translateFromPivotOrg));

    model = moveModel * translateFromPivot * rotateYMatrix * translateToPivot * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.2f, 0.2f, 1.0f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.2f, 0.2f, 1.0f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

} 


void carpet(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    translateMatrix = glm::translate(identityMatrix, glm::vec3(3.5f, 1.25f + 0.45f, -5.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.5f, 0.1f, 35.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}


void outside_boundary(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    //Left Side
   

    //Left choto Side
    glBindTexture(GL_TEXTURE_2D, texture2);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.4f, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", color * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //Left 




    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 10.0f, -37.8f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //Right Side
    translateMatrix = glm::translate(identityMatrix, glm::vec3(18.15f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-24.0f, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //Right Wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(18.15f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, 10.0f, -37.8f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //Back
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, -0.42f, -4.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(19.2f, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(18.15f, -0.42f, -4.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-21.2f, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    //Left Side Pillar
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(2.7f, -0.42f, 14.9f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 19.2f, 0.6f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color * 0.5f);
    ourShader.setVec4("material.diffuse", color * 0.5f);
    ourShader.setVec4("material.specular", color * 0.5f * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //Right Side Pillar
    translateMatrix = glm::translate(identityMatrix, glm::vec3(5.8f, -0.42f, 14.9f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.6f, 19.2f, 0.6f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);

    ourShader.setVec4("material.ambient", color * 0.5f);
    ourShader.setVec4("material.diffuse", color * 0.5f);
    ourShader.setVec4("material.specular", color * 0.5f * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    

}
void Boundary(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    //Left Side
    glBindTexture(GL_TEXTURE_2D, texture2);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(17.2f, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", color * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //Left Wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 10.0f, -37.8f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //Right Side
    translateMatrix = glm::translate(identityMatrix, glm::vec3(18.15f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-15.4f, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //Right Wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(18.15f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-0.2f, 10.0f, -37.8f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //Back
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, -0.42f, -4.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(19.2f, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(18.15f, -0.42f, -4.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-21.2f, 10.0f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    

}

void GuardRoom(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color, unsigned int texture = texture0)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model;

    //roof
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.35f, 0.95f, 12.86f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 0.25f, 4.3f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color * 0.5f);
    ourShader.setVec4("material.diffuse", color * 0.5f);
    ourShader.setVec4("material.specular", color * 0.5f * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //back side
    glBindTexture(GL_TEXTURE_2D, texture);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.4f, -0.42f, 13.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 2.75f, 3.80f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //right side
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", color * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.5f, -0.42f, 13.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.2f, 2.75f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //left side
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.5f, -0.42f, 14.8f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.2f, 2.75f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //font side
    //1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, -0.42f, 13.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 2.75f, 0.6f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, -0.42f, 13.8f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 2.75f, 0.8f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, -0.42f, 13.25f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 1.2f, 1.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, 0.6f, 13.25f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.9f, 1.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    //5
    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, 0.7f, 14.1f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 0.6f, 1.5f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //floor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.401f, -0.42f, 13.001f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.38f, 0.1f, 3.7f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color * 0.1f);
    ourShader.setVec4("material.diffuse", color * 0.1f);
    ourShader.setVec4("material.specular", color * 0.5f * 0.1f);
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);



}

void Shop(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color, unsigned int texture = texture0)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;


    //roof
    glBindTexture(GL_TEXTURE_2D, texture0);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.7f, 0.95f, 12.86f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-4.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.8f, 0.29f, 6.0f));
    model = translateMatrix * rotateZMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", color * 0.5f);
    ourShader.setVec4("material.diffuse", color * 0.5f);
    ourShader.setVec4("material.specular", color * 0.5f * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //back side
    glBindTexture(GL_TEXTURE_2D, texture);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(8.4f, -0.42f, 13.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 2.75f, 5.5f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //right side
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", color * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.99f, -0.419f, 12.99f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 2.75f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //left side
    ourShader.setVec4("material.ambient", color);
    ourShader.setVec4("material.diffuse", color);
    ourShader.setVec4("material.specular", color * 0.5f);
    ourShader.setFloat("material.shininess", 32.0f);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6.99f, -0.419f, 15.651f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0f, 2.75f, 0.2f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //front side
    translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0f, -0.42f, 13.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.2f, 1.2f, 4.0f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    

}

void Gate(Shader ourShader, glm::mat4 moveMatrix, glm::vec4 color)
{


}

void LampPost(Shader ourShader, glm::mat4 moveMatrix)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, scaleMatrix, model, rotateZMatrix;

    //base
    translateMatrix = glm::translate(identityMatrix, glm::vec3(8.01f, -0.42f, 15.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.7f, 0.3f, 0.7f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.3f, 0.3f, 0.3f, 1.0f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    //pillar
    translateMatrix = glm::translate(identityMatrix, glm::vec3(8.17f, -0.42f, 15.15f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 3.5f, 0.1f));
    model = translateMatrix * scaleMatrix;
    ourShader.setMat4("model", moveMatrix * model);
    ourShader.setVec4("material.ambient", glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));
    ourShader.setVec4("material.diffuse", glm::vec4(0.3f, 0.4f, 0.3f, 1.0f));
    ourShader.setVec4("material.specular", glm::vec4(0.3f, 0.4f, 0.3f, 1.0f));
    ourShader.setFloat("material.shininess", 32.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}