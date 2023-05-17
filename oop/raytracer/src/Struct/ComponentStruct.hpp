/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** ComponentStruct.hpp
*/

#pragma once

#include <cmath>
#include "../../Vector/Vector.hpp"

struct Coord3D {
    double x;
    double y;
    double z;
};

struct rotation {
    int x;
    int y;
    int z;
};

struct vector3D {
    double x, y, z;

    vector3D() : x(0), y(0), z(0) {}

    vector3D(double ix, double iy, double iz) : x(ix), y(iy), z(iz) {}

    void rotate(rotation rot) {
        double tmpy = y;
        y = cos(rot.x)*y - sin(rot.x)*z;
        z = sin(rot.x)*tmpy + cos(rot.x)*z;

        double tmpx = x;
        x = cos(rot.y)*x + sin(rot.y)*z;
        z = -sin(rot.y)*tmpx + cos(rot.y)*z;

        tmpx = x;
        x = cos(rot.z)*x - sin(rot.z)*y;
        y = sin(rot.z)*tmpx + cos(rot.z)*y;
    }

    void normalize() {
        double length = sqrt(x*x + y*y + z*z);
        if (length != 0) {
            x /= length;
            y /= length;
            z /= length;
        }
    }
};


struct DistancePos {
    double distance;
    Coord3D pos;
    Vector color;
};