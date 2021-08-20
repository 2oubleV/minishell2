/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sort an integer array
*/

int my_put_nbr(int nb);

void my_sort_int_array(int *tab, int size)
{
    int tmp;

    for (int i = 0; tab[i] != size; ++i) {
        if (tab[i] > tab[i + 1]) {
            tmp = tab[i + 1];
            tab[i + 1] = tab[i];
            tab[i] = tmp;
            i = 0;
        }
    }
    for (int i = 0; tab[i] != size; ++i) {
        my_put_nbr(tab[i]);
    }
}
