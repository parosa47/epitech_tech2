/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.hpp
*/

#pragma once

#include "../../Struct/ComponentStruct.hpp"
#include <utility>
#include <cmath>

class Camera {
    Coord3D _coord;
    std::pair<int, int> _resolution;
    rotation _rotation;
    double _fov;
    public:
        Camera() = default;
        Camera(double cx, double cy, double cz, int rox, int roy, int roz, int fov, int rex, int rey) {
            _coord.x = cx;
            _coord.y = cy;
            _coord.z = cz;
            _rotation.x = rox;
            _rotation.y = roy;
            _rotation.z = roz;
            _fov = fov;
            _resolution.first = rex;
            _resolution.second = rey;
        };
        std::pair<int, int> getResolution() { return _resolution; };
        vector3D getRay(int x, int y);
        ~Camera() {};
};