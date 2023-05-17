/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Icomponent.hpp
*/

#pragma once

#include "../Struct/ComponentStruct.hpp"

class IComponent {
   public:
      virtual ~IComponent() = default;
      virtual DistancePos getIntersection(vector3D ray) = 0;
};