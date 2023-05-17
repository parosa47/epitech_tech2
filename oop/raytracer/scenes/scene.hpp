/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** scene.hpp
*/

#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>

#include "../src/AComponent/camera/Camera.hpp"
#include "../src/IComponent/IComponent.hpp"

class scene {
    std::map<std::string, IComponent*> _components;
    Camera _camera;
    public:
        scene(double cx, double cy, double cz, int rox, int roy, int roz, int fov, int rex, int rey) { _camera = Camera(cx, cy, cz, rox, roy, roz, fov, rex, rey);};
        ~scene() {};
        void addComponent(std::string name, IComponent &component) { _components[name] = &component; };
        IComponent *getComponent(std::string name) { return _components[name]; };
        std::map<std::string, IComponent*> getComponents() { return _components; };
        Camera getCamera() { return _camera; };
};