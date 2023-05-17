/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** printIMG.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "../Struct/PixelStruct.hpp"
#include "../../scenes/scene.hpp"
#include "../AComponent/camera/Camera.hpp"

class SFML {
    public:
        SFML() {};
        ~SFML() {};
        void printIMG(std::vector<Pixel> pixelsList, Camera camera);
};