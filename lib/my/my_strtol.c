/*
** EPITECH PROJECT, 2020
** my_strtol
** File description:
** Bootstrap EvalExpr
*/

int my_strtol(char *str, char **endptr)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0' && str[i] >= 48 && str[i] <= 57; i++) {
            nbr = (nbr * 10) + (str[i] - 48);
            *endptr = &str[i + 2];
    }
    return (nbr);
}
