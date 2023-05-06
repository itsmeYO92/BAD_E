#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HIGHT 32

#define KRED "\x1B[31m"
#define KNOR "\x1B[37m"

/**
 * struct player - Struct player
 *
 * @position_x: position of player in x axis
 * @position_y: position of player in y axis
 * @avatar: charachter representing the player
 */
typedef struct player
{
	int position_x;
	int position_y;
	char avatar;
} player_t;

char **init_level(char **level, int n, player_t player);
void print_level(char **level, player_t player);
void free_mem(char **level);


#endif
