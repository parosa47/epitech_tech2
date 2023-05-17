/*
** EPITECH PROJECT, 2022
** base_cpp_project
** File description:
** main.cpp
*/
#include <iostream>
#include <vector>
#include <fstream>
#include "Struct/PixelStruct.hpp"
#include "SFML/printIMG.hpp"
#include "../scenes/scene.hpp"
#include "AComponent/camera/Camera.hpp"
#include "AComponent/sphere/sphere.hpp"

std::vector<Pixel> simulate(scene Scene)
{
    std::vector<Pixel> allPixels;
    std::map<std::string, IComponent*> components = Scene.getComponents();
    Camera camera = Scene.getCamera();
    std::map<std::string, IComponent*>::iterator it;
    for (int y = 0; y < camera.getResolution().second; y++) {
        for (int x = 0; x < camera.getResolution().first; x++) {
            vector3D ray = camera.getRay(x, y);
            for (it = components.begin(); it != components.end(); it++) {
                DistancePos distancePos = it->second->getIntersection(ray);
                if (distancePos.distance != 0) {
                    Pixel pixel;
                    pixel.coord.x = x;
                    pixel.coord.y = y;
                    pixel.color.x = distancePos.color.x();
                    pixel.color.y = distancePos.color.y();
                    pixel.color.z = distancePos.color.z();
                    allPixels.push_back(pixel);
                }
            }
        }
    }
    return allPixels;
}

int main(void) {
    scene Scene(0, 0, 0, 0, 0, 0, 70, 1920, 1080);
    //scene Scene(0, 0, 10, 0, 1, 0, 100, 1920, 1080);
    SFML SFML;
    Sphere sphere(0, 0, 13, 5, 0, 255, 0);
    Sphere sphere1(5, -3, 10, 3, 255, 0, 0);
    Sphere sphere2(0, 0, 10, 2, 0, 0, 255);
    Scene.addComponent("sphere1", sphere);
    Scene.addComponent("sphere2", sphere1);
    Scene.addComponent("sphere3", sphere2);
    std::vector<Pixel> pixelsList = simulate(Scene);
    SFML.printIMG(pixelsList, Scene.getCamera());
    return 0;
}
