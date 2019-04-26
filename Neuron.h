//
// Created by Kyle on 2019-04-19.
//

#ifndef NEURALTEST_NEURON_H
#define NEURALTEST_NEURON_H


#include "Connector.h"
#include "Array.h"

const float DEFAULT_AP_THRESHOLD = 1.0f;
const float DEFAULT_MYELIN = 1.0f;
const float INITIAL_AP = 1.0f;

class Neuron {
private:
    //speed of action potential
    float myelin;

    //activation threshold
    float ap_threshold;

    //internal action potential value
    float ap_value;

    //time decay clock
    int timeStamp;

public:
    Neuron();
    void addPotential(float add_AP, int timeStamp);

    //Array of outputs
    Array<Connector> * output;

};



#endif //NEURALTEST_NEURON_H
