/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** isupper
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 64 && str[i] < 92)
            ++i;
        else
        return (0);
    }
    return (1);
}