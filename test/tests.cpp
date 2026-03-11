// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include "circle.h"
#include "tasks.h"

namespace {
    constexpr double PI = 3.1415926535897932;
}

TEST(CircleTests, Case1) {
    Circle circle;
    EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
    EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleTests, Case2) {
    Circle circle(0.0);
    EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
    EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleTests, Case3) {
    Circle circle(5.0);
    EXPECT_DOUBLE_EQ(5.0, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * 5.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * 5.0 * 5.0, circle.getArea());
}

TEST(CircleTests, Case4) {
    EXPECT_THROW(Circle circle(-5.0), std::invalid_argument);
}

TEST(CircleTests, Case5) {
    Circle circle(5.0);
    circle.setRadius(20.0);
    EXPECT_DOUBLE_EQ(20.0, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * 20.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * 20.0 * 20.0, circle.getArea());
}

TEST(CircleTests, Case6) {
    Circle circle(5.0);
    EXPECT_THROW(circle.setRadius(-20.0), std::invalid_argument);
}

TEST(CircleTests, Case7) {
    Circle circle(5.0);
    circle.setFerence(20.0);
    double expectedRadius = 20.0 / (2 * PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(20.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * (expectedRadius * expectedRadius), circle.getArea());
}

TEST(CircleTests, Case8) {
    Circle circle(5.0);
    EXPECT_THROW(circle.setFerence(-10.0), std::invalid_argument);
}

TEST(CircleTests, Case9) {
    Circle circle(5.0);
    circle.setArea(20.0);
    double expectedRadius = sqrt(20.0 / PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * expectedRadius, circle.getFerence());
    EXPECT_DOUBLE_EQ(20.0, circle.getArea());
}

TEST(CircleTests, Case10) {
    Circle circle(5.0);
    EXPECT_THROW(circle.setArea(-5.0), std::invalid_argument);
}

TEST(CircleTests, Case11) {
    Circle circle(10.0);
    circle.setRadius(5.0);
    EXPECT_DOUBLE_EQ(5.0, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * 5.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * 5.0 * 5.0, circle.getArea());

    circle.setFerence(7.0);
    double expectedRadius = 7.0 / (2 * PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(7.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * (expectedRadius * expectedRadius), circle.getArea());
}

TEST(CircleTests, Case12) {
    Circle circle(10.0);
    circle.setFerence(5.0);
    double expectedRadius = 5.0 / (2 * PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(5.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * (expectedRadius * expectedRadius), circle.getArea());

    circle.setArea(15.0);
    expectedRadius = sqrt(15.0 / PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * expectedRadius, circle.getFerence());
    EXPECT_DOUBLE_EQ(15.0, circle.getArea());
}

TEST(CircleTests, Case13) {
    double rad = 1e-15;
    Circle circle(rad);
    EXPECT_DOUBLE_EQ(rad, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * rad, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * rad * rad, circle.getArea());
}

TEST(CircleTests, Case14) {
    double rad = 1e15;
    Circle circle(rad);
    EXPECT_DOUBLE_EQ(rad, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * rad, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * rad * rad, circle.getArea());
}

TEST(CircleTests, Case15) {
    Circle circle(7.0);
    circle.setFerence(0.0);
    double expectedRadius = 0.0 / (2 * PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * (expectedRadius * expectedRadius), circle.getArea());
}

TEST(CircleTests, Case16) {
    Circle circle(7.0);
    circle.setArea(0.0);
    double expectedRadius = sqrt(0.0 / PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * expectedRadius, circle.getFerence());
    EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleTests, Case17) {
    Circle circle(10.0);
    circle.setFerence(5.0);
    circle.setArea(15.0);
    circle.setRadius(5.0);
    EXPECT_DOUBLE_EQ(5.0, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * 5.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * 5.0 * 5.0, circle.getArea());
}

TEST(CircleTests, Case18) {
    Circle circle;
    circle.setArea(15.0);
    circle.setFerence(5.0);
    circle.setRadius(10.0);
    EXPECT_DOUBLE_EQ(10.0, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * 10.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * 10.0 * 10.0, circle.getArea());
}

TEST(CircleTests, Case19) {
    Circle circle;
    circle.setFerence(0.0);
    circle.setArea(0.0);
    circle.setRadius(5.0);
    EXPECT_DOUBLE_EQ(5.0, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * 5.0, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * 5.0 * 5.0, circle.getArea());
}

TEST(CircleTests, Case20) {
    Circle circle(50.0);
    circle.setFerence(50.0);
    circle.setRadius(20.0);
    circle.setArea(0.0);
    double expectedRadius = sqrt(0.0 / PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * expectedRadius, circle.getFerence());
    EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(CircleTests, Case21) {
    double fer = 1e-15;
    Circle circle;
    circle.setFerence(fer);
    double expectedRadius = fer / (2 * PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(fer, circle.getFerence());
    EXPECT_DOUBLE_EQ(PI * (expectedRadius * expectedRadius), circle.getArea());
}

TEST(CircleTests, Case22) {
    double ar = 1e-15;
    Circle circle;
    circle.setArea(ar);
    double expectedRadius = sqrt(ar / PI);
    EXPECT_DOUBLE_EQ(expectedRadius, circle.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * expectedRadius, circle.getFerence());
    EXPECT_DOUBLE_EQ(ar, circle.getArea());
}

TEST(EarthTest, Case23) {
    Circle earth(6378100);
    double oldRadius = earth.getRadius();
    double rope = earth.getFerence();
    rope += 1.0;
    earth.setFerence(rope);
    double newRadius = earth.getRadius();
    double expected = newRadius - oldRadius;

    EXPECT_DOUBLE_EQ(earthRope(), expected);
}

TEST(PoolTest, Case24) {
    Circle pool(3.0);
    Circle outer(4.0);
    double pathArea = outer.getArea() - pool.getArea();
    double expected = pathArea * 1000.0 + outer.getFerence() * 2000.0;

    EXPECT_DOUBLE_EQ(poolTask(), expected);
}
