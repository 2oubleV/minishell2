/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** disp a number
*/

char my_putchar(char c);

int my_put_nbr(int nb)
{
    int nb2 = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10 || nb <= -10) {
        nb2 = nb % 10;
        nb = (nb - nb2) / 10;
        my_put_nbr(nb);
        my_putchar(nb2 + 48);
    } else
        my_putchar(nb + 48);
    return (0);
}
