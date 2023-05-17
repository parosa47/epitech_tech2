/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** sphere.cpp
*/

#include "sphere.hpp"
#include "../../../Vector/Vector.hpp"

DistancePos Sphere::getIntersection(vector3D ray)
{
    double a = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
    double b = 2.0 * (ray.x * (_coord.x) + ray.y * (_coord.y) + ray.z * (_coord.z));
    double c = (_coord.x) * (_coord.x) + (_coord.y) * (_coord.y) + (_coord.z) * (_coord.z) - _radius * _radius;
    double delta = b * b - 4.0 * a * c;
    if (delta < 0) {
        return {0, 0, 0};
    } else if (delta == 0) {
        double t = -b / (2.0 * a);
        double x = ray.x * t;
        double y = ray.y * t;
        double z = ray.z * t;
        double dist = std::sqrt((x * x) + (y * y) + (z * z));
        return {dist , {_coord.x + x, _coord.y + y, _coord.z + z}, _color};
    } else {
        double t1 = (-b + std::sqrt(delta)) / (2.0 * a);
        double t2 = (-b - std::sqrt(delta)) / (2.0 * a);
        double x1 = ray.x * t1;
        double y1 = ray.y * t1;
        double z1 = ray.z * t1;
        double x2 = ray.x * t2;
        double y2 = ray.y * t2;
        double z2 = ray.z * t2;
        double dist1 = std::sqrt((x1 * x1) + (y1 * y1) + (z1 * z1));
        double dist2 = std::sqrt((x2 * x2) + (y2 * y2) + (z2 * z2));
        if (dist1 <= dist2) {
            return {dist1 ,{_coord.x + x1, _coord.y + y1, _coord.z + z1}, _color};
        } else {
            return {dist2 ,{_coord.x + x2, _coord.y + y2, _coord.z + z2}, _color};
        }
    }
}
