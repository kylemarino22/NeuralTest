//
// Created by Kyle on 2019-04-19.
//

#include <stdlib.h>

#include "NeuronGrid.h"
#include "Array.h"
#include "Array.cpp"


NeuronGrid::NeuronGrid (int height, int width) {

    //populate grid with neurons
    grid = new Neuron*[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new Neuron[width];
    }
    this->height = height;
    this->width = width;
}

void NeuronGrid::generateStructure() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            //individual neuron
            Neuron currentNeuron = grid[i][j];

            int coords[2] = {i, j};
            int oldDirection = -1;
            bool repeat;
            do {
                repeat = false;
                int direction = rand() % 4;

                if (direction == oldDirection) {
                    repeat = true;
                    continue;
                }

                if (i == 0 && direction == 2) {
                    repeat = true;
                    continue;
                }

                if (i == this->height - 1 && direction == 0) {
                    repeat = true;
                    continue;
                }

                if (j == 0 && direction == 3) {
                    repeat = true;
                    continue;
                }

                if (j == this->width - 1 && direction == 1) {
                    repeat = true;
                    continue;
                }

                if (direction == 0) {
                    coords[0] ++;
                }
                else if (direction == 1) {
                    coords[1] ++;
                }
                else if (direction == 2) {
                    coords[0] --;
                }
                else if (direction == 3) {
                    coords[1] --;
                }


                oldDirection = direction;

            } while (repeat || rand() % 8 < 4);

            Neuron * neuronToAdd = &(grid[coords[0]][coords[1]]);

            float randomInit = (float)(rand() % 100) / 100;

            currentNeuron.output->push(Connector(randomInit,neuronToAdd));


        }
    }
}



Neuron **NeuronGrid:: getGrid() const {
    return grid;
}

void NeuronGrid::setGrid(Neuron **grid) {
    NeuronGrid::grid = grid;
}

int NeuronGrid::getHeight() const {
    return height;
}

void NeuronGrid::setHeight(int height) {
    NeuronGrid::height = height;
}

int NeuronGrid::getWidth() const {
    return width;
}

void NeuronGrid::setWidth(int width) {
    NeuronGrid::width = width;
}
