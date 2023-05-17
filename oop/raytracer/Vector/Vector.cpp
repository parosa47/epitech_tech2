/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector
*/

#include "Vector.hpp"
#include <algorithm>
#include <cmath>

Vector Vector::scale(const Vector &rhs) const
{
    return {_x * rhs._x, _y * rhs._y, _z * rhs._z};
}

bool Vector::operator==(const Vector& rhs) const
{
    return _x == rhs._x && _y == rhs._y && _z == rhs._z;
}

// auto Vector::operator<=>(const Vector& rhs) const
// {
//     return eval() - rhs.eval();
// }

bool Vector::operator<(const Vector& rhs) const
{
    return eval() < rhs.eval();
}

Vector &Vector::operator+=(const Vector& rhs)
{
    _x += rhs._x;
    _y += rhs._y;
    _z += rhs._z;
    return *this;
}

Vector &Vector::operator-=(const Vector& rhs)
{
    _x -= rhs._x;
    _y -= rhs._y;
    _z -= rhs._z;
    return *this;
}
Vector Vector::operator+(const Vector& rhs) const
{
    return {_x + rhs._x, _y + rhs._y, _z + rhs._z};
}
Vector Vector::operator-(const Vector& rhs) const
{
    return {_x - rhs._x, _y - rhs._y, _z - rhs._z};
}
double Vector::eval() const
{
    return (_x * _x + _y * _y + _z * _z);
}
double Vector::magnitude() const
{
    return std::sqrt(eval());
}

Vector Vector::normalize() const
{
//     if (*this == Vector(0, 0, 0))
//         return *this;
    return *this * magnitude();
}

Vector Vector::saturate() const
{
    return this->clamp(0, 1);
}

Vector Vector::clamp(double min, double max) const
{
    return Vector(
        std::clamp(_x, min, max),
        std::clamp(_y, min, max),
        std::clamp(_z, min, max)
    );
}

Vector Vector::operator*(double k) const
{
    return { _x * k, _y * k, _z * k};
}

double Vector::operator*(const Vector& rhs) const
{
    return _x * rhs._x + _y * rhs._y + _z * rhs._z;
}
