/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a string
*/

void my_swap(char *a, char *b);

char *my_revstr(char *str)
{
    int length = 0;
    int a;
    int i;

    while (str[length] != '\0')
        ++length;
    a = length - 1;
    for (i = 0; i < a; ++i) {
        my_swap(&str[i], &str[a]);
        --a;
    }
    return (str);
}
