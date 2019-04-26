//
// Created by Kyle on 2019-04-21.
//

#include <glad/glad.h>
#include <iostream>
#include "Display.h"
#include "Array.h"
#include "Array.cpp"
#include "Rectangle.h"

GLFWwindow* displayWindow;
int shaderProgram;
unsigned int VAO, VBO, EBO;

//Fragment and vertex shader
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\n\0";

bool init () {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    displayWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Window", NULL, NULL);
    if (displayWindow == NULL)
    {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(displayWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return false;
    }
    buildShaders();
    updateBuffers();
    return true;
}

bool close () {
    if (glfwWindowShouldClose(displayWindow)) {
        return true;
    }
    update();
    return false;
}

void update () {
    render();
    processInput(displayWindow);
    glfwSwapBuffers(displayWindow);
    glfwPollEvents();
}

void terminate() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
}


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void framebuffer_size_callback(GLFWwindow* displayWindow, int width, int height)
{
    glViewport(0, 0, width, height);
}


bool buildShaders() {
    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // -----------------------------------------------------------------
}

void updateBuffers() {
    float vertices[] = {
            0.25f,  0.25f, 0.0f,  // top right
            0.25f, -0.25f, 0.0f,  // bottom right
            -0.25f, -0.25f, 0.0f,  // bottom left
            -0.25f,  0.25f, 0.0f,

    };
    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3,

    };


//    float * vertices;
//    unsigned int * indices;
//    Rectangle rArray[1];
//    rArray[0] = Rectangle(10, 10, 10, 10);
//    Array<Rectangle> * rectArray = new Array<Rectangle>(rArray, 1);
//
//    loadRectangles(rectArray, vertices, indices);


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

}

void render () {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // draw our first triangle
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
}

void loadRectangles (Array<Rectangle> * rectArray, float *& verticies, unsigned int *& indicies) {
    int length = rectArray->getSize();

    //Two triangles and 4 verticies per rectangle
    //3 Points per vertex
    verticies = new float[length * 4*3];

    indicies = new unsigned int[length * 6];

    Rectangle * rectVerticies = rectArray->getArr();

    //tr --> br --> bl --> tl
    for (int i = 0; i < length; i++) {
        Rectangle currentRect = rectVerticies[i];


        //vertex calculation
        verticies[i*12]     = (float) 2*(currentRect.x + currentRect.width) / SCR_WIDTH - 1;
        verticies[i*12 + 1] = (float) 2*currentRect.y / SCR_HEIGHT - 1;
        verticies[i*12 + 2] = 0;
        verticies[i*12 + 3] = (float) 2*(currentRect.x + currentRect.width) / SCR_WIDTH - 1;
        verticies[i*12 + 4] = (float) 2*(currentRect.y + currentRect.height) / SCR_HEIGHT - 1;
        verticies[i*12 + 5] = 0;
        verticies[i*12 + 6] = (float) 2*(currentRect.x) / SCR_WIDTH - 1;
        verticies[i*12 + 7] = (float) 2*(currentRect.y + currentRect.height) / SCR_HEIGHT - 1;
        verticies[i*12 + 8] = 0;
        verticies[i*12 + 9] = (float) 2*(currentRect.x) / SCR_WIDTH - 1;
        verticies[i*12 + 10] = (float) 2*(currentRect.y) / SCR_HEIGHT - 1;
        verticies[i*12 + 11] = 0;

        //index calculation
        indicies[i*6] = (i*3);
        indicies[i*6 + 1] = (i*3) + 1;
        indicies[i*6 + 2] = (i*3) + 3;
        indicies[i*6 + 3] = (i*3) + 1;
        indicies[i*6 + 1] = (i*3) + 2;
        indicies[i*6 + 2] = (i*3) + 3;


    }
}