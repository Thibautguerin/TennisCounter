/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for tennis
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int count_point(int *player, int *player1, int i, char *str)
{
	if (player[0] == 40 && player1[0] == 40) {
		player1[0] = 30;
		return (1);
	}
	else if (player[0] == 0 || player[0] == 15)
		player[0] = player[0] + 15;
	else if (player[0] == 30)
		player[0] = player[0] + 10;
	else {
		player[0] = 0;
		player1[0] = 0;
		player = add_jeu(player, player1, i, str);
	}
	return (0);
}

void delete_all(int *player1, int *player2, char *str)
{
	if (player1[6] == 3)
		write(1, "\n<<<< Player1 won! >>>>\n\n", 25);
	else if (player2[6] == 3)
		write(1, "\n<<<< Player2 won! >>>>\n\n", 25);
	free(str);
	free(player1);
	free(player2);
}

int *init_tab(void)
{
	int *player = malloc(sizeof(int) * 7);
	int i = 0;

	while (i != 7) {
		player[i] = 0;
		i++;
	}
	return (player);
}

void tennis(int *p1, int *p2, int i, int check)
{
	char *str = malloc(sizeof(char) * 101);

	str[0] = '\0';
	while (p1[6] != 3 && p2[6] != 3 && my_strcmp(str, "exit\n") != 0) {
		str = get_str(str);
		if (my_strcmp(str, "1\n") == 0) {
			check = count_point(p1, p2, i, str);
			display_score(p1, p2, check);
		}
		else if (my_strcmp(str, "2\n") == 0) {
			check = count_point(p2, p1, i, str);
			display_score(p1, p2, check);
		}
		else if (my_strcmp(str, "exit\n") != 0) {
			manual();
		}
		i = i_plus(p1, p2, i);
	}
	delete_all(p1, p2, str);
}

int main(int ac, char **av)
{
	int *player1 = init_tab();
	int *player2 = init_tab();
	int i = 1;
	int check = 0;

	if (ac == 1) {
		tennis(player1, player2, i, check);
		return (0);
	}
	else if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
		manual();
		free(player1);
		free(player2);
		return (0);
	} else {
		manual();
		free(player1);
		free(player2);
		return 84;
	}
}
