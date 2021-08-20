/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] == '-')
        ++i;
    k = i;
    while (str[i] != '\0')
    {
        if (str[i] >= 48 && str[i] <= 57) {
            j = j * 10;
            j += str[i] - 48;
            ++i;
        } else
            break;
    }
    if (k % 2 != 0)
        j = -j;
    return (j);
}
