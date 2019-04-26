//
// Created by Kyle on 2019-04-19.
//

#ifndef NEURALTEST_CONNECTOR_H
#define NEURALTEST_CONNECTOR_H

class Connector {
private:
    float strength;
    class Neuron *neuron;
    int timeStamp;

public:
    Connector(float strength, Neuron *neuron);
    Connector();
    void fire(int timeStamp);
};


#endif //NEURALTEST_CONNECTOR_H
