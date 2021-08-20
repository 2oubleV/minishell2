/*
** EPITECH PROJECT, 2020
** _square_root
** File description:
** task05
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    int i = 0;
    int j;

    if (nb <= 0)
        return (0);
    while (j != nb) {
        j = i*i;
        if (j > nb)
            return (0);
        ++i;
    }
    return (i - 1);
}