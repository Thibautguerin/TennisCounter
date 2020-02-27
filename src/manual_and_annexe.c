/*
** EPITECH PROJECT, 2018
** manual_and_annexe.c
** File description:
** man and my_strcmp
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void manual(void)
{
	write(1, "<<<<<<<<<<<<<<<<<<< Manual >>>>>>>>>>>>>>>>>>>\n", 47);
	write(1, "| This program count the tennis score        |\n", 47);
	write(1, "| Enter 1 to add one point to the 1st player |\n", 47);
	write(1, "| Enter 2 to add one point to the 2nd player |\n", 47);
	write(1, "| Enter exit to close the program            |\n", 47);
	write(1, "<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>\n", 47);
}

void choise_player(char *strr, int *player, int *player1, int i)
{
	if (my_strcmp(strr, "1\n") == 0) {
		player[0] = player[0] + 1;
		if (set_tie_break(player, player1, i) == 0)
			display_score(player, player1, 0);
	}
	else if (my_strcmp(strr, "2\n") == 0) {
		player1[0] = player1[0] + 1;
		if (set_tie_break(player1, player, i) == 0)
			display_score(player, player1, 0);
	}
	else if (my_strcmp(strr, "exit\n") != 0)
		manual();
}

char *get_str(char *str)
{
	int k;

	write(1, "\nQuel joueur a marqué le point?\n", 33);
	k = read(0, str, 100);
	str[k] = '\0';
	return (str);
}
