/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** cmp
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int ret = 0;

    if (my_strlen(s1) != my_strlen(s2))
        ret = 1;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            ret = 1;
    }
    return (ret);
}