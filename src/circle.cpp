// Copyright 2022 UNN-CS
#include "circle.h"
#include <cstdint>
#include <stdexcept>
#include <cmath>

namespace {
constexpr double PI = 3.1415926535897932;
}

Circle::Circle() {
    this->radius = 0;
    this->ference = 0;
    this->area = 0;
}

Circle::Circle(double radius_) {
    this->setRadius(radius_);
}

void Circle::setRadius(double radius_) {
    if (radius_ < 0.0) {
        throw std::invalid_argument("negative argument");
    }
    this->radius = radius_;
    this->ference = 2 * PI * this->radius;
    this->area = PI * (this->radius * this->radius);
}

void Circle::setFerence(double ference_) {
    if (ference_ < 0.0) {
        throw std::invalid_argument("negative argument");
    }
    this->ference = ference_;
    this->radius = this->ference / (2 * PI);
    this->area = PI * (this->radius * this->radius);
}

void Circle::setArea(double area_) {
    if (area_ < 0.0) {
        throw std::invalid_argument("negative argument");
    }
    this->area = area_;
    this->radius = sqrt(this->area / PI);
    this->ference = 2 * PI * this->radius;
}

double Circle::getRadius() {
    return this->radius;
}

double Circle::getFerence() {
    return this->ference;
}

double Circle::getArea() {
    return this->area;
}
