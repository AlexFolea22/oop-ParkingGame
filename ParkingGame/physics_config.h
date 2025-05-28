#pragma once
#ifndef PHYSICS_CONFIG_H
#define PHYSICS_CONFIG_H
struct PhysicsConfig {
    float friction = 0.08f;
    float acceleration = 50.0f;
    float maxSpeed = 6.0f;
    float turnSpeed = 180.0f;
    float drag = 2.0f;
    float lateralFriction = 0.2f;

    PhysicsConfig operator+(float increment) const {
        PhysicsConfig result = *this;
        result.friction += increment*0.01;
        result.acceleration += increment*10;
        result.maxSpeed += increment;
        result.turnSpeed += increment*10;
        result.drag += increment;
        result.lateralFriction += increment*0.1;
        return result;
    }

    PhysicsConfig operator+(int increment_int) const {
        return *this + static_cast<float>(increment_int);
    }

};
#endif