//
// Created by Kyle on 2019-04-21.
//

#ifndef NEURALTEST_ARRAY_H
#define NEURALTEST_ARRAY_H

#include <cstdint>

template <class T>
class Array {
private:
    uint8_t size;
    T * arr;

public:
    Array(T *arr, int size);
    void push(T elem);
    int getSize();
    T * getArr();

};


#endif //NEURALTEST_ARRAY_H
