/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** 
*/

int my_put_nbr(int nbr)
{
    int i = 0;
    int result = 1;
    int save = 0;
    int count = 0;

    for (int c = nbr; c > 0; c = c/10, i++, save++);
    for (; i != 1; i--)
        result = result * 10;
    for (char a; nbr > 0; a++) {
        int chiffre = nbr / result;
        a = chiffre + 48;
        write (1, &a, 1);
        nbr = nbr % result;
        result = result / 10;
        count++;
    }
    for (; count != save; count++)
        write (1, "0", 1);
}
