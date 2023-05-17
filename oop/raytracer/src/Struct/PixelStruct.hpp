/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PixelStruct.hpp
*/

#pragma once

struct Coord2D {
    double x;
    double y;
};

struct Color {
    int x;
    int y;
    int z;
};

struct Pixel {
    Coord2D coord;
    Color color;
};