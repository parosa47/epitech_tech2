/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Main.cpp
*/

#include "namespace/nts.hpp"
#include "parsing/parsing.hpp"

int main()
{
    nts::glb gl;
    nts::open_file("example.txt", gl);
    return 0;
}