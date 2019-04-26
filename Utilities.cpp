//
// Created by Kyle on 2019-04-21.
//

#include "Utilities.h"

//template <class elem>
template <class elem>
elem arrayPush(elem *arr, int size, elem T ) {
    elem outArray[size + 1];

    for (int i = 0; i < size; i++) {
        outArray[i] = arr[i];
    }

    outArray[size] = T;
    delete arr;
    return *outArray;
}