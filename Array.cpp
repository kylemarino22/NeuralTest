//
// Created by Kyle on 2019-04-21.
//

#include "Array.h"

template <class T>
Array<T>::Array (T *arr, int size) {
    this->arr = arr;
    this->size = size;
}

template <class T>
void Array<T>::push(T elem) {

    if (size == 0) {
        arr = new T[1] {elem};
    }

    T outArray[size + 1];

    for (int i = 0; i < size; i++) {
        outArray[i] = arr[i];
    }

    outArray[size] = elem;
    size++;
    arr = outArray;
}

template <class T>
int Array<T>::getSize() {
    return this->size;
}
template <class T>
T * Array<T>::getArr() {
    return arr;
}