/*
** EPITECH PROJECT, 2022
** 205IQ
** File description:
** 205IQ.cpp
*/

#include "205IQ.hpp"

IQ205::IQ::IQ(int argc, char **argv) : _argc(argc), _argv(argv)
{
    _mean = std::atof(_argv[1]);
    _stddev = std::atof(_argv[2]);
    _iq1 = 0;
    _iq2 = 0;
    if (_argc >= 4)
        _iq1 = std::atof(_argv[3]);
    if (_argc == 5)
        _iq2 = std::atof(_argv[4]);
}

IQ205::IQ::~IQ()
{}

double IQ205::IQ::normal_pdf(double x)
{
    return std::exp(-(x - _mean)*(x - _mean) / (2 * _stddev*_stddev)) / (_stddev * std::sqrt(2 * M_PI));
}

void help()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./205IQ u s [IQ1] [IQ2]" << std::endl;
    std::cout << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tu\tmean" << std::endl;
    std::cout << "\ts\tstandard deviation" << std::endl;
    std::cout << "\tIQ1\tminimum IQ" << std::endl;
    std::cout << "\tIQ2\tmaximum IQ" << std::endl;
}

int IQ205::IQ::errorHandling()
{
    if (_argc < 3 || _argc > 5) {
        std::cerr << "USAGE: " << _argv[0] << " u s [IQ1] [IQ2]" << std::endl;
        return 84;
    }
    return 0;
}

void IQ205::IQ::plot()
{
    if (_argc == 3) {
        for (int i = 0; i <= 200; i++) {
            std::cout << i << " " << std::fixed << std::setprecision(5) << normal_pdf(i) << std::endl;
        }
    }
}

void IQ205::IQ::inferior()
{
    if (_argc == 4) {
        double cdf = 0.5 * (1 + std::erf((_iq1 - _mean) / (_stddev * std::sqrt(2))));
        std::cout << std::fixed << std::setprecision(1) << cdf * 100 << "% of people have an IQ inferior to " << (int)_iq1 << std::endl;
    }
}

void IQ205::IQ::between()
{
    if (_argc == 5) {
        double cdf1 = 0.5 * (1 + std::erf((_iq1 - _mean) / (_stddev * std::sqrt(2))));
        double cdf2 = 0.5 * (1 + std::erf((_iq2 - _mean) / (_stddev * std::sqrt(2))));
        std::cout << std::fixed << std::setprecision(1) << (cdf2 - cdf1) * 100 << "% of people have an IQ between " << (int)_iq1 << " and " << (int)_iq2 << std::endl;
    }
}

void IQ205::IQ::run()
{
    plot();
    inferior();
    between();
}

int main(int argc, char* argv[])
{
    if (argc == 2 && std::string(argv[1]) == "-h") {
        help();
        return 0;
    }
    IQ205::IQ Iq = IQ205::IQ(argc, argv);
    if (Iq.errorHandling() == 84)
        return 84;

    Iq.run();
    return 0;
}