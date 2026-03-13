// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
 private:
  double radius;
  double ference;
  double area;

 public:
  Circle();
  explicit Circle(double radius_);
  void setRadius(double radius_);
  void setFerence(double ference_);
  void setArea(double area_);
  double getRadius();
  double getFerence();
  double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
