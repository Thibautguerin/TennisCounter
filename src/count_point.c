/*
** EPITECH PROJECT, 2018
** count_point.c
** File description:
** count point in tennis
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void advantage(int *player1, int *player2)
{
	int i = 1;

	if (player1[0] == 40)
		write(1, "AV  |   ", 8);
	else
		write(1, "    |   ", 8);
	display_player(player1, player2, i);
	write(1, "\n", 1);
	i = 1;
	display_player2(player2);
	if (player2[0] == 40)
		write(1, "AV  |   ", 8);
	else
		write(1, "    |   ", 8);
	display_player(player2, player1, i);
	write(1, "\n", 1);
}

int set_tie_break(int *player, int *player1, int i)
{
	if (player[0] >= 7 && player1[0] <= player[0] - 2) {
		player[i] = player[i] + 1;
		return (1);
	}
	return (0);
}

void tie_break(int *player, int *player1, int i)
{
	char *strr = malloc(sizeof(char) * 100);

	while (player[i] != 7 && player1[i] != 7
	&& my_strcmp(strr, "exit\n") != 0) {
		free(strr);
		strr = malloc(sizeof(char) * 100);
		read(0, strr, 100);
		choise_player(strr, player, player1, i);
	}
}

int *add_jeu(int *player, int *player1, int i, char *str)
{
	player[i] = player[i] + 1;
	if (player[i] == 6 && player1[i] == 6) {
		if (my_strcmp(str, "1\n") == 0) {
			display_score(player, player1, 0);
			tie_break(player, player1, i);
		}
		else if (my_strcmp(str, "2\n") == 0) {
			display_score(player1, player, 0);
			tie_break(player1, player, i);
		}
		player[0] = 0;
		player1[0] = 0;
	}
	if ((player[i] == 6 && player1[i] <= 4)
	|| (player1[i] == 6 && player[i] <= 4) || player[i] == 7)
		player[6] = player[6] + 1;
	else if (player1[i] == 7)
		player1[6] = player1[6] + 1;
	return (player);
}

int i_plus(int *player, int *player1, int i)
{
	if (player[i] == 7 || player1[i] == 7 || (player[i] == 6
	&& player1[i] <= 4) || (player1[i] == 6 && player[i] <= 4))
		i++;
	return (i);
}
