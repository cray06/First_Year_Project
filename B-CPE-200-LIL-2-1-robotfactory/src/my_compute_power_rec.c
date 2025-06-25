/*
** EPITECH PROJECT, 2024
** my_compute_power_rec.c
** File description:
** return the first argument raised to the power p,
** given as second parameter
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0){
        return 1;
    } else {
        return nb * my_compute_power_rec(nb, p - 1);
    }
}
