/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sphere.hpp
*/

#pragma once

#include "../../IComponent/IComponent.hpp"
#include "../../../Vector/Vector.hpp"

#include <cmath>

class Sphere : public IComponent {
    Coord3D _coord;
    double _radius;
    Vector _color;
    public:
        Sphere(double cx, double cy, double cz, double radius, int r, int g, int b) {
            _coord.x = cx;
            _coord.y = cy;
            _coord.z = cz;
            _radius = radius;
            _color.x() = r;
            _color.y() = g;
            _color.z() = b;
        };
        ~Sphere() override {};
        DistancePos getIntersection(vector3D ray) override;
};