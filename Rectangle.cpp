//
// Created by Kyle on 2019-04-21.
//

#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
Rectangle::Rectangle() {
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
}