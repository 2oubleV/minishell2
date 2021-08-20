/*
** EPITECH PROJECT, 2020
** int_my_is_prime
** File description:
** refelchir critere de nb premier
*/

int my_is_prime(int nb)
{
    int i;

    for (i = 2; i < nb; ++i) {
        if (nb % i == 0) {
        return (0);
        }
    }
    return (0);
}
