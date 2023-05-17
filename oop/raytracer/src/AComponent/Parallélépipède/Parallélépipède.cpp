/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cube.cpp
*/

#include "Parallélépipède.hpp"

DistancePos Parallélépipède::getIntersection(vector3D ray) {
    double distance = DBL_MAX;
    Coord3D pos;
    Vector color;

    vector3D invertedRay(1 / ray.x, 1 / ray.y, 1 / ray.z);
    bool inside = true;
    if (invertedRay.x < 0) {
        inside = !inside;
    }
    if (invertedRay.y < 0) {
        inside = !inside;
    }
    if (invertedRay.z < 0) {
        inside = !inside;
    }

    Coord3D minBound = _coord;
    Coord3D maxBound(_coord.x + _width, _coord.y + _height, _coord.z + _depth);

    double t1 = (minBound.x - ray.x) * invertedRay.x;
    double t2 = (maxBound.x - ray.x) * invertedRay.x;
    double t3 = (minBound.y - ray.y) * invertedRay.y;
    double t4 = (maxBound.y - ray.y) * invertedRay.y;
    double t5 = (minBound.z - ray.z) * invertedRay.z;
    double t6 = (maxBound.z - ray.z) * invertedRay.z;

    double tMin = std::max(std::max(std::min(t1, t2), std::min(t3, t4)), std::min(t5, t6));
    double tMax = std::min(std::min(std::max(t1, t2), std::max(t3, t4)), std::max(t5, t6));

    if (tMax < 0) {
        return { distance, pos, color };
    }

    if (tMin > tMax) {
        return { distance, pos, color };
    }

    if (inside) {
        distance = tMax;
        pos = Coord3D(ray.x + invertedRay.x * distance,
                      ray.y + invertedRay.y * distance,
                      ray.z + invertedRay.z * distance);
        color = _colorInside;
    } else {
        if (t1 > t3 && t1 > t5) {
            distance = t1;
            pos = Coord3D(ray.x + invertedRay.x * distance,
                          ray.y + invertedRay.y * distance,
                          ray.z + invertedRay.z * distance);
            color = _colorSide;
        } else if (t3 > t5) {
            distance = t3;
            pos = Coord3D(ray.x + invertedRay.x * distance,
                          ray.y + invertedRay.y * distance,
                          ray.z + invertedRay.z * distance);
            color = _colorSide;
        } else {
            distance = t5;
            pos = Coord3D(ray.x + invertedRay.x * distance,
                          ray.y + invertedRay.y * distance,
                          ray.z + invertedRay.z * distance);
            color = _colorSide;
        }
    }

    return { distance, pos, color };
}
