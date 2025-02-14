
#include "minesweeper.h"



// void	print_cells(t_cell *cells)
// {
// 	int	i;
// 	int	j;


// 	while


// }

/*
Print Table Letter on the right side
*/

void	print_row_letter(t_map *map)
{
	char a = '0';
	char b = '0';

	printf("\n");
	printf("  ");
	while (a < b + map->height)
	{
		printf("%c", a);
		if (a != b - 1 + map->height)
			printf("  ");
		a++;
	}
	printf("\n");
}

/*
Print whole map, visible or not can be changed with variable g_flipped in map_generation.c
*/

void print_map(t_map *map)
{
	int		i;
	int		j;
	t_cell **cell;
	char	line_letter;

	line_letter  = 'A';
	cell = map->cells;
	print_row_letter(map);
	i = -1;
	while (++i < map->height)
	{
		printf("%c ", line_letter);
		j = 0;
		while (j < map->width)
		{
			if (cell[i][j].fliped == true)
				printf("%c", cell[i][j].value);
			else
				printf("-");
			if (j != map->width - 1)
				printf("  ");
			j++;
		}
		line_letter++;
		printf("\n");
	}
	printf("\n");
}
