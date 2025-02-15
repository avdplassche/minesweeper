
#include "minesweeper.h"

void	free_cells(t_map *map)
{
	int	i;
	int	j;

	i = 0;

	while (i < map->width)
	{
		free(map->table[i]);
		i++;
	}
	free(map->table);
}

int main(int ac, char **av)
{
	// char	*choice;
	t_map	*map;

	if (ac != 3)
		return (write(2, "Error : arg.\n", 13), EXIT_FAILURE);
	map = malloc(sizeof(t_map));
	printf("\n\n▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▄▄▄▖▗▄▄▖ ▗▄▄▄▖▗▄▄▖ \n▐▛▚▞▜▌  █  ▐▛▚▖▐▌▐▌   ▐▌   ▐▌ ▐▌▐▌   ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌\n▐▌  ▐▌  █  ▐▌ ▝▜▌▐▛▀▀▘ ▝▀▚▖▐▌ ▐▌▐▛▀▀▘▐▛▀▀▘▐▛▀▘ ▐▛▀▀▘▐▛▀▚▖\n▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▐▙▄▄▖▗▄▄▞▘▐▙█▟▌▐▙▄▄▖▐▙▄▄▖▐▌   ▐▙▄▄▖▐▌ ▐▌\n\n\n");
	init_map(map, av);
	generate_map(map);
	print_map(map);
	free_cells(map);
	free(map);
}
