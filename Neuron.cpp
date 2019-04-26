//
// Created by Kyle on 2019-04-19.
//

#include "Neuron.h"
#include "Array.h"
#include "Array.cpp"

Neuron::Neuron() {
    this->ap_threshold = DEFAULT_AP_THRESHOLD;
    this->myelin = DEFAULT_MYELIN;
    this->ap_value = INITIAL_AP;
    this->output = new Array<Connector>({} , 0);
    this->timeStamp = 0;
}

void Neuron::addPotential(float add_AP, int timeStamp) {

    int timeDelta = timeStamp - this->timeStamp;
    this->timeStamp = timeStamp;

    //TODO: Based on timestamp update, take away AP, then add AP

    //TODO: check if AP is above threshold, then fire ap to connections
}

