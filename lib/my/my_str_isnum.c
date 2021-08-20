/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** isnum
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 47 && str[i] < 58 || str[i] == '-')
            ++i;
        else
        return (1);
    }
    return (0);
}