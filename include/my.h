/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** 
*/

#ifndef MY_H
# define MY_H

int count_point(int *player, int *player1, int i, char *str);
void delete_all(int *player1, int *player2, char *str);
int *init_tab(void);
void tennis(int *player1, int *player2, int i, int check);
int main(int ac, char **av);
void my_put_nbr(int nb);
void verif_point(int *player1);
void display_player2(int *player2);
void display_player(int *player, int *player1, int i);
void display_score(int *player1, int *player2, int check);
void advantage(int *player1, int *player2);
int set_tie_break(int *player, int *player1, int i);
void tie_break(int *player, int *player1, int i);
int *add_jeu(int *player, int *player1, int i, char *str);
int i_plus(int *player, int *player1, int i);
int my_strcmp(char *s1, char *s2);
void manual(void);
void my_putchar(char c);
void choise_player(char *strr, int *player, int *player1, int i);
char *get_str(char *str);

#endif /* !MY_H_ */
