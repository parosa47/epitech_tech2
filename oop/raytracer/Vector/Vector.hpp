/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Vector
*/

#pragma once

/**
 * Vector for 3D math
 * implements basic operands, as well as dot product with '*'
 */
class Vector {
    protected:
        double _x;
        double _y;
        double _z;
    public:
        Vector() : _x(0), _y(0), _z(0) {};
        Vector(double x, double y, double z) : _x(x), _y(y), _z(z) {};
        Vector(const Vector&) = default;

        Vector& operator=(const Vector&) = default;

        /**
         * per component multiplication
         */
        Vector scale(const Vector& rhs) const;

        /**
         * Compare magnitude
        */
        // auto operator<=>(const Vector& rhs) const;
        bool operator<(const Vector& rhs) const;
        // bool operator<=(const Vector& rhs) const = default;
        // bool operator>(const Vector& rhs) const = default;
        // bool operator>=(const Vector& rhs) const = default;
        Vector &operator+=(const Vector& rhs);
        Vector &operator-=(const Vector& rhs);

        /**
         * Compare exact
         */
        bool operator==(const Vector& rhs) const;

        Vector operator+(const Vector& rhs) const;
        Vector operator-(const Vector& rhs) const;

        /**
         * Cheaply evaluate magnitude squared
         */
        double eval() const;

        /**
         * Length of vector
         */
        double magnitude() const;

        /**
         * Returns a vector of magnitude 1 or 0
         */
        Vector normalize() const;

        /**
         * ensure each component is between 0 and 1
         */
        Vector saturate() const;

        /**
         * ensure each component is between \p min and \p max
         */
        Vector clamp(double min, double max) const;

        /**
         * Scalar product
         */
        Vector operator*(double k) const;

        /**
         * Dot product
         */
        double operator*(const Vector& rhs) const;

        double x() const { return _x; }
        double y() const { return _y; }
        double z() const { return _z; }
        double& x() { return _x; }
        double& y() { return _y; }
        double& z() { return _z; }
};
