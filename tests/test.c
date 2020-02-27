/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** test criterion
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strcmp, retour)
{
	cr_assert(my_strcmp("1\n", "1\n") == 0);
	cr_assert(my_strcmp("1\nret", "1\nret") == 0);
	cr_assert(my_strcmp("1\nge", "1\ndzef") != 0);
}

Test(count_point, retour)
{
	int i = 1;
	char *str = "1\n";
	int player[7];
	int player1[7];

	player[0] = 40;
	player1[0] = 40;
	cr_assert(count_point(player, player1, i, str) == 1);
	player[0] = 30;
	player1[0] = 15;
	cr_assert(count_point(player, player1, i, str) == 0);
}

Test(i_plus, retour)
{
	int i = 1;
	int player[7];
	int player1[7];

	player[i] = 7;
	player1[i] = 5;
	cr_assert(i_plus(player, player1, i) == 2);
	i = 1;
	player[i] = 4;
	player1[i] = 3;
	cr_assert(i_plus(player, player1, i) == 1);
	i = 1;
	player[i] = 6;
	player1[i] = 4;
	cr_assert(i_plus(player, player1, i) == 2);
}

Test(set_tie_break, retour)
{
	int i = 1;
	int player[7];
	int player1[7];

	player[0] = 6;
	player1[0] = 4;
	cr_assert(set_tie_break(player, player1, i) == 0);
	player[0] = 7;
	player1[0] = 4;
	cr_assert(set_tie_break(player, player1, i) == 1);
	player[0] = 7;
	player1[0] = 6;
	cr_assert(set_tie_break(player, player1, i) == 0);
	player[0] = 10;
	player1[0] = 9;
	cr_assert(set_tie_break(player, player1, i) == 0);
	player[0] = 11;
	player1[0] = 9;
	cr_assert(set_tie_break(player, player1, i) == 1);
}

Test(add_jeu, retour)
{
	int player[7] = {0, 5, 0, 0, 0, 0, 0};
	int player1[7] = {0, 4, 0, 0, 0, 0, 0};
	int play1[7] = {0, 6, 0, 0, 0, 0, 1};
	int *play = add_jeu(player, player1, 1, "1\n");
	int i = 0;

	while (i != 7) {
		cr_assert(play[i] == play1[i]);
		i++;
	}
}

Test(add_jeu2, retour)
{
	int i = 0;
	int player11[7] = {0, 5, 0, 0, 0, 0, 0};
	int playerr[7] = {0, 6, 0, 0, 0, 0, 0};
	int play11[7] = {0, 7, 0, 0, 0, 0, 1};
	int *playy = add_jeu(playerr, player11, 1, "1\n");

	while (i != 7) {
		cr_assert(playy[i] == play11[i]);
		i++;
	}
}

Test(init_tab, retour)
{
        int i = 0;
        int player[7] = {0, 0, 0, 0, 0, 0, 0};
	int *play = init_tab();

        while (i != 7) {
                cr_assert(play[i] == player[i]);
                i++;
        }
}
