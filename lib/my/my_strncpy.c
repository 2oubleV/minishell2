/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** function that copies a string into another
** for n character
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int l;

    l = 0;
    i = 0;
    while (src[l] != '\0')
        ++l;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    if (n > l)
        dest[i] = '\0';
    return (dest);
}
