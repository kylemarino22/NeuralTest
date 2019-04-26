//
// Created by Kyle on 2019-04-21.
//

#ifndef NEURALTEST_DISPLAY_H
#define NEURALTEST_DISPLAY_H


#include <GLFW/glfw3.h>
#include "Array.h"
#include "Rectangle.h"


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


bool init();
bool close();
void update();
void terminate();
bool buildShaders();
void updateBuffers();
void render();
void loadRectangles (Array<Rectangle> * rectArray, float *& verticies, unsigned int *& indicies);


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);




#endif //NEURALTEST_DISPLAY_H
