/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** printable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 31 && str[i] < 128)
            ++i;
        else
        return (0);
    }
    return (1);
}
