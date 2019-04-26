//
// Created by Kyle on 2019-04-19.
//

#include "Connector.h"

Connector::Connector(float strength, Neuron *neuron){
    this->strength = strength;
    this->neuron = neuron;
}

Connector::Connector() {}

void Connector::fire(int timeStamp) {
    int timeDelta = timeStamp - this->timeStamp;
    this->timeStamp = timeStamp;
}
