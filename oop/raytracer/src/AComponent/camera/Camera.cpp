/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

vector3D Camera::getRay(int x, int y)
{
    double aspectRatio = static_cast<double>(_resolution.first) / _resolution.second;
    double px = (2 * ((x + 0.5) / _resolution.first) - 1) * aspectRatio * tan(_fov / 2 * M_PI / 180);
    double py = (1 - 2 * ((y + 0.5) / _resolution.second)) * tan(_fov / 2 * M_PI / 180);
    vector3D ray(px, py, -1);
    ray.rotate(_rotation);
    ray.normalize();
    return ray;
}
