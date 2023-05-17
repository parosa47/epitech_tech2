/*
** EPITECH PROJECT, 2023
** 206
** File description:
** main.cpp
*/
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>

int main(int argc, char *argv[]) 
{

    double n = std::atof(argv[1]);
    double a = std::atof(argv[2]);
    double h = std::atof(argv[3]);
    double sd = std::atof(argv[4]);

    double sum_sq = n * sd * sd + n * a * a;
    double sum = n * a;

    while (true) {
        std::string input;
        std::cout << "Enter next value: ";
        if (!std::getline(std::cin, input)) {
            std::cerr << "Error: could not read input\n";
            return 84;
        }
        if (input == "END") {
            break;
        }

        double value;
        try {
            value = std::stod(input);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: input is not a number\n";
            return 84;
        }

        int new_n = n + 1;
        double delta = value - a;
        double new_a = a + delta / new_n;
        double new_sd = std::sqrt((n * sd * sd + delta * delta + 2 * delta * (new_a - a)) / new_n);
        sum_sq += value * value;
        sum += value;
        double new_rms = std::sqrt((sum_sq + sum*sum/new_n) / new_n - new_a*new_a);
        double new_h = (n + 1) / (((1 / h) * n) + (1 / value));

        std::cout << "\tNumber of values:\t" << new_n << std::endl;
        std::cout << std::fixed << std::setprecision(2) << "\tStandard deviation:\t" << new_sd << std::endl;
        std::cout << std::fixed << std::setprecision(2) << "\tArithmetic mean:\t" << new_a << std::endl;
        std::cout << std::fixed << std::setprecision(2) << "\tRoot mean square:\t" << new_rms << std::endl;
        std::cout << std::fixed << std::setprecision(2) << "\tHarmonic mean:\t\t" << new_h << "\n" << std::endl;

        n = new_n;
        a = new_a;
        h = new_h;
        sd = new_sd;
    }

    return 0;
}
