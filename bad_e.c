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
	system("/bin/stty --file=/dev/tty -icanon");
	init_level(level, stage, player);
	print_level(level, player);
	free_mem(level);
	return (0);

}

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
		strcpy(level[i], line);

	}

	level[player.position_y][player.position_x] = player.avatar;
	fclose(maze);
	return (level);
} 


void print_level(char **level, player_t player)
{
	system("clear");
	for (int i=0; i < 32; i++)
	{
		if (i != player.position_y)
			printf("%s",level[i]);
		else
		{
			for (int j = 0; j < strlen(level[i]); j++)
			{
				if (j != player.position_x)
					printf("%c",level[i][j]);
				else
				{
					printf("%s",KRED);
					printf("%c", level[i][j]);
					printf("%s", KNOR);
				}
			}
		}

	}

}

void free_mem(char **level)
{
	int i;

	if (!level)
		return;

	for (i = 0; i < 32; i++)
		free(level[i]);
	free(level);
}
