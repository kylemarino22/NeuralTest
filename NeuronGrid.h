//
// Created by Kyle on 2019-04-19.
//

#ifndef NEURALTEST_NEURONGRID_H
#define NEURALTEST_NEURONGRID_H


#include "Neuron.h"
#include "Connector.h"

class NeuronGrid {

private:
    Neuron **grid;
    int height;
    int width;

public:
    NeuronGrid(int height, int width);

    void generateStructure();

    Neuron **getGrid() const;

    void setGrid(Neuron **grid);

    int getHeight() const;

    void setHeight(int height);

    int getWidth() const;

    void setWidth(int width);


};


#endif // NEURALTEST_NEURONGRID_H
