/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cube.hpp
*/

#pragma once

#include "../../IComponent/IComponent.hpp"
#include "../../../Vector/Vector.hpp"
#include <cfloat>
#include <cmath>

class Parallélépipède : public IComponent {
    Coord3D _coord;
    double _width;
    double _height;
    double _depth;
    Vector _color;
    public:
        Parallélépipède(double cx, double cy, double cz, double width, double height, double depth, int r, int g, int b) {
            _coord.x = cx;
            _coord.y = cy;
            _coord.z = cz;
            _width = width;
            _height = height;
            _depth = depth;
            _color.x() = r;
            _color.y() = g;
            _color.z() = b;
        };
        ~Parallélépipède() override {};
        DistancePos getIntersection(vector3D ray) override;
};