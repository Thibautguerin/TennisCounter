/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display in tennis
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void my_put_nbr(int nb)
{
	int i;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * (- 1);
	}
	if (nb >= 10) {
		i = (nb % 10);
		nb = (nb - i) / 10;
		my_put_nbr(nb);
		my_putchar(48 + i);
	} else
		my_putchar(48 + nb % 10);
}

void verif_point(int *player1)
{
	if (player1[0] >= 0 && player1[0] <= 9)
		write(1, "        | point | set1 | \
set2 | set3 | set4 | set5 | sets\nPlayer1 |    ", 72);
	else
		write(1, "        | point | set1 | \
set2 | set3 | set4 | set5 | sets\nPlayer1 |   ", 71);
}

void display_player2(int *player2)
{
	if (player2[0] >= 0 && player2[0] <= 9)
		write(1, "Player2 |    ", 13);
	else
		write(1, "Player2 |   ", 12);
}

void display_player(int *player, int *player1, int i)
{
	if (player[0] == 40 && player1[0] == 40) {
		write (1, "DC  |   ", 8);
		i++;
	}
	while (i != 7) {
		my_put_nbr(player[i]);
		write(1, "  |   ", 6);
		i++;
	}
}

void display_score(int *player1, int *player2, int check)
{
	int i = 0;

	verif_point(player1);
	if (check == 1)
		advantage(player1, player2);
	else {
		display_player(player1, player2, i);
		write(1, "\n", 1);
		i = 0;
		display_player2(player2);
		display_player(player2, player1, i);
		write(1, "\n", 1);
	}
}
