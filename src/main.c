
#include "minesweeper.h"

void	free_cells(t_map *map)
{
	int	i;
	int	j;

	i = -1;

	while (++i < map->width)
		free(map->table[i]);
	free(map->table);
}

char	*get_move(t_map *map)
{
	char	*move;
	int		i;  //lines
	int		j;  //row

	move = malloc(sizeof(char) * 3);
	read(1, move, 3);
	move[2] = '\0';
	printf("move choose : %s\n", move);
	if ('a' <= move [0] && move[0] <= 'z')
		move[0] = move[0] - 32;
	i = move[0] - 'A';
	j = move[1] - '0';
	map->table[i][j].fliped = false;
	return (move);
}

int	win_test(t_map *map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->table[i][j].fliped == false)
				count++;
		}
	}
	if(count == 10)
		return (1);
	else
		return (0);
}

int main(int ac, char **av)
{
	char	choice;
	t_map	*map;
	char	*move;

	if (ac != 3)
		return (write(2, "Error : arg.\n", 13), EXIT_FAILURE);
game :
	map = malloc(sizeof(t_map));
	printf("\n\n▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▄▄▄▖▗▄▄▖ ▗▄▄▄▖▗▄▄▖ \n▐▛▚▞▜▌  █  ▐▛▚▖▐▌▐▌   ▐▌   ▐▌ ▐▌▐▌   ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌\n▐▌  ▐▌  █  ▐▌ ▝▜▌▐▛▀▀▘ ▝▀▚▖▐▌ ▐▌▐▛▀▀▘▐▛▀▀▘▐▛▀▘ ▐▛▀▀▘▐▛▀▚▖\n▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▐▙▄▄▖▗▄▄▞▘▐▙█▟▌▐▙▄▄▖▐▙▄▄▖▐▌   ▐▙▄▄▖▐▌ ▐▌\n\n\n");
	init_map(map, av);
	print_map(map);
	while (map->win == 0 && map->lose == 0)
	{
		move = NULL;
		move = get_move(map);
		if (map->turn_one == 1)
		{
			generate_map(map, move);
			map->turn_one = 0;
		}
		map = play(map, move);
		print_map(map);
		free(move);
		map->win = win_test(map);
	}
	if (map->win == 1)
		printf("You win !\n");
	if (map->lose == 1)
		printf("You lose !\n");
	free_cells(map);
	free(map);
	printf("Restart ?\n1 - Yes\n2 - No\n");
	choice = getchar();
	if (choice == '1')
		goto game;
	else if (choice == '2')
		return(0);
	return (0);
}
