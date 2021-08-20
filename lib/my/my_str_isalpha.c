/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** convert my_str in alpa
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123)
            ++i;
        else
        return (0);
    }
    return (1);
}