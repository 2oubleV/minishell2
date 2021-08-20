/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** my str capitalize
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src);

char *my_strcapitalize(char *src)
{
    int i = 0;
    char *str = my_strdup(src);

    while (str[i] != '\0') {
        if (str[0] > 96 && str[0] < 123) {
            str[0] -= 32;
            ++i;
        } else if (str[i] == ' ' && str[i + 1] > 96 && str[i + 1] < 123) {
            str[i + 1] -= 32;
            ++i;
        } else
        ++i;
    }
    return (str);
}
