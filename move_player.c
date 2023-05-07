#include "main.h"


/**
 * move_player - Moves the player's avatar based on user input
 *
 * @mv: The character representing the user input
 * @level: A pointer to the array representing the game level
 * @player: The player_t structure representing the player
 *
 * Return: The updated player_t structure
 */


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
	return (player);
}
