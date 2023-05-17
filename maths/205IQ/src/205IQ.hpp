/*
** EPITECH PROJECT, 2022
** 205IQ
** File description:
** 205IQ.hpp
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

namespace IQ205 {
    class IQ {
            int _argc;
            char **_argv;
            double _mean;
            double _stddev;
            double _iq1;
            double _iq2;
        public:
            IQ(int argc, char **argv);
            ~IQ();
            int errorHandling();
            double normal_pdf(double x);
            void run();
            void plot();
            void inferior();
            void between();
    };
}