#include <iostream>
#include "NeuronGrid.h"
#include "Array.h"
#include "Array.cpp"
#include "Display.h"

#include <stdio.h>
#include <zconf.h>


int main() {
    std::cout << "Hello, World!" << std::endl;


    init();

    NeuronGrid mainGrid(3,3);
    mainGrid.generateStructure();

    while (!close())
    {
        printf("running");
        sleep(1);


    }
    terminate();
    return 0;
}

