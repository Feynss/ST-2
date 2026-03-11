#include <stdexcept>
#include "circle.h"
#include "tasks.h"

namespace {
    constexpr double earthRadius = 6378100;
    constexpr double ropeAddedLength = 1.0;

    constexpr double poolRadius = 3.0;
    constexpr double pathWidth = 1.0;
    constexpr double concretePrice = 1000.0;
    constexpr double fencePrice = 2000.0;
}

double earthRope() {
    Circle earth(earthRadius);

    double oldRadius = earth.getRadius();
    double rope = earth.getFerence();
    rope += ropeAddedLength;

    earth.setFerence(rope);

    double newRadius = earth.getRadius();

    return newRadius - oldRadius;
}

double poolTask() {
    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    double pathArea = outer.getArea() - pool.getArea();
    
    return pathArea * concretePrice + outer.getFerence() * fencePrice;
}
