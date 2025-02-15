
#include "minesweeper.h"


void	print_cells(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			// if (map->table[i][j].fliped == true)
			printf("%c ", map->table[i][j].value);
			// else
				// printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	print_map_datas(t_map *map)
{
	printf("Width : %d\n", map->width);
	printf("Height : %d\n", map->height);
	printf("Cells : %d\n", map->cell_amount);
	printf("Mines : %d\n", map->mine_amount);
	printf("\n");
}
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
	cell = map->table;
	print_row_letter(map);
	i = 0;
	while (i < map->height)
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
		i++;
		line_letter++;
		printf("\n");
	}
	printf("\n");
}

void	print_borders(t_cell cell)
{
	printf("%d ", cell.nw_cell);
	printf("%d ", cell.n_cell);
	printf("%d\n", cell.ne_cell);
	printf("%d ", cell.w_cell);
	printf("%d ", cell.index);
	printf("%d\n", cell.e_cell);
	printf("%d ", cell.sw_cell);
	printf("%d ", cell.s_cell);
	printf("%d\n", cell.se_cell);
	printf("\n");
}
