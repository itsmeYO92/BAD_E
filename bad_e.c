#include "main.h"

/**
 * main - Entry point.
 * Return: 0
*/

int main(void)
{
	char **level = malloc(sizeof(char *) * MAX_HIGHT);
	player_t player = {0, 0, 'V'};
	char mv;
	int stage = 1;

	if (!level)
		return (0);
	system("/bin/stty --file=/dev/tty -icanon");
	init_level(level, stage, player);
	if (!level)
		return (0);
	print_level(level, player);
	while (1)
	{
		mv = getchar();
		player = move_player(mv, level, player);
		print_level(level, player);
	}
	free_mem(level);
	return (0);

}

/**
 * init_level - Initialize the game level with level data from a file and
 *              place the player's avatar on the level
 *
 * @level: A pointer to the array representing the game level
 * @n: The level number
 * @player: The player_t structure representing the player
 *
 * Return: The initialized game level, or NULL on failure
 */

char **init_level(char **level, int n, player_t player)
{
	FILE *maze;
	char lev[30];
	char line[200];
	int i;

	sprintf(lev, "levels/level%d.txt", n);
	maze = fopen(lev, "r");

	for (i = 0; i < 32; i++)
	{
		fgets(line, sizeof(line), maze);
		level[i] = malloc(sizeof(line));
		if (!level[i])
			return (NULL);
		strcpy(level[i], line);

	}

	level[player.position_y][player.position_x] = player.avatar;
	fclose(maze);
	return (level);
}

/**
 * print_level - Prints the game level with the player's avatar highlighted
 *
 * @level: A pointer to the array representing the game level
 * @player: The player_t structure representing the player
 */
void print_level(char **level, player_t player)
{
	system("clear");
	for (int i = 0; i < 32; i++)
	{
		if (i != player.position_y)
			printf("%s", level[i]);
		else
		{
			for (int j = 0; j < strlen(level[i]); j++)
			{
				if (j != player.position_x)
					printf("%c", level[i][j]);
				else
				{
					printf("%s", KRED);
					printf("%c", player.avatar);
					printf("%s", KNOR);
				}
			}
		}

	}

}

/**
 * free_mem - Frees the memory allocated for the game level
 *
 * @level: A pointer to the array representing the game level
 */

void free_mem(char **level)
{
	int i;

	if (!level)
		return;

	for (i = 0; i < 32; i++)
		free(level[i]);
	free(level);
}


player_t move_player(char mv, char **level, player_t player)
{
	if ('q' == mv)
	{
		if (player.position_x > 0)
		{
			if (level[player.position_y][player.position_x - 1] == ' ')
				player.position_x--;
		}
	}
	else if ('s' == mv)
	{
		if (player.position_x < 60)
		{
			if (level[player.position_y][player.position_x + 1] == ' ')
				player.position_x++;
		}
	}

	if ('z' == mv)
	{
		if (player.position_y > 0)
		{
			if (level[player.position_y - 1][player.position_x] == ' ')
				player.position_y--;
		}
	}
	else if ('w' == mv)
	{
		if (player.position_y < 40)
		{
			if (level[player.position_y + 1][player.position_x] == ' ')
				player.position_y++;
		}
	}
printf("%d %d", player.position_y, player.position_x);
	return (player);
}

