
#include "minesweeper.h"


int main (int ac, char **av)
{
	char	*choice;
	t_map	*map;

	if (ac != 3)
		return (write(2, "Error : arg.\n", 13), EXIT_FAILURE);
	map = malloc(sizeof(t_map));
	printf("\n\n▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖ ▗▄▄▖▗▖ ▗▖▗▄▄▄▖▗▄▄▄▖▗▄▄▖ ▗▄▄▄▖▗▄▄▖ \n▐▛▚▞▜▌  █  ▐▛▚▖▐▌▐▌   ▐▌   ▐▌ ▐▌▐▌   ▐▌   ▐▌ ▐▌▐▌   ▐▌ ▐▌\n▐▌  ▐▌  █  ▐▌ ▝▜▌▐▛▀▀▘ ▝▀▚▖▐▌ ▐▌▐▛▀▀▘▐▛▀▀▘▐▛▀▘ ▐▛▀▀▘▐▛▀▚▖\n▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▐▙▄▄▖▗▄▄▞▘▐▙█▟▌▐▙▄▄▖▐▙▄▄▖▐▌   ▐▙▄▄▖▐▌ ▐▌\n\n\n");
	// print_map_choice();
	// read(1, choice, 1);
	choice = "1";
	// print_map(map);
	init_map(map, choice, av);
	generate_map(map);
	print_map(map);
	free(map);
	free(map->cells);
	// while (1)
	// {
	// 	read(1, choice, 1);

	// }
}
