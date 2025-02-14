
#include "minesweeper.h"

bool	g_fliped = true;


//faire tests voir conditions ipad


int	check_border(t_map *map, int index, int index_side)
{
	if (0 <= index && index < map->width);

	return (index_side);
}


t_cell	fill_cell_borders(t_map *map, t_cell cell, int i, int j)
{
	cell.index = i / 10 + j;
	cell.n_cell = check_border(map, cell.index, cell.index - map->width);
	printf("N  : %d\n", cell.n_cell);
	// cell.ne_cell = check_border(map, index, index - map->width + 1);
	// printf("Ne : %d\n", cell.ne_cell);
	// cell.w_cell = check_border(map, index, index - 1);
	// printf("W  : %d\n", cell.w_cell);
	// cell.e_cell = check_border(map, index, index + 1);
	// printf("E  : %d\n", cell.e_cell);
	// cell.sw_cell = check_border(map, index, index + map->width - 1);
	// printf("Sw : %d\n", cell.sw_cell);
	// cell.s_cell = check_border(map, index, index + 1);
	// printf("S  : %d\n", cell.s_cell);
	// cell.se_cell = check_border(map, index, index + map->width + 1);
	// printf("Se : %d\n", cell.se_cell);
	return (cell);
}

void	fill_table_borders(t_map *map, t_cell **cells)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height)
		{
			cells[i][j] = fill_cell_borders(map, cells[i][j], i, j);
		}
	}
	// return (cells[i][j].border);
}

void init_map(t_map *map, char *choice, char **av)
{
	int	i;
	int	j;
	t_cell **cells;

	i = -1;
	if (atoi(choice) == 1)
	{
		map->height = atoi(av[1]);
		map->width = atoi(av[2]);
		map->cell_amount = map->width * map->height;
		map->mine_number = map->width * map->height / 10;
	}
	cells = (t_cell **)malloc(sizeof(t_cell *) * (map->height));
	while (++i < map->width)
	{
		j = -1;
		cells[i] = (t_cell *)malloc(sizeof(t_cell) * (map->width));
		while (++j < map->height)
		{
			cells[i][j].value = '-';
			cells[i][j].fliped = g_fliped;
			fill_table_borders(map, cells);
		}
	}
	// cells = fill_table_borders(map, cells);
	map->cells = cells;
	// print_cells
}

char	*first_move(t_map *map)
{
	char	*move;
	int		i;  //lines
	int		j;  //row

	move = malloc(sizeof(char) * 3);
	printf("Chose move.\n");
	read(1, move, 2);
	printf("Move :  %s\n", move);
	if ('a' <= move [0] && move[0] <= 'z')
		move[0] = move[0] - 32;
	i = move[0] - 'A';
	j = move[1] - '0';
	map->cells[i][j].value = 'i';
	map->cells[i][j].fliped = true;
	return (move);
}

int	move_to_index(char *move)
{
	return ((move[0] - 'A') * 10 + move[1] - '0');
}

// int	mine_check(t_map *map, char *move, int mine)
// {
// 	t_border	cell;

// 	cell = map->cells[move[0] - 'A'][move[1] - '0'].border;
// 	if (mine == cell.center)
// 		return (1);
// 	if (mine == cell.nw_cell || mine == cell.n_cell || mine == cell.ne_cell)
// 		return (1);
// 	if (mine == cell.n_cell || mine == cell.s_cell)
// 		return (1);
// 	if (mine == cell.sw_cell || mine == cell.s_cell || mine == cell.se_cell)
// 		return (1);
// 	return (0);
// }


int	fill_mine_cell(t_map *map, int mine_pos)
{
	int	i;

	if (map->cells[mine_pos / 10][mine_pos % 10].value != 'o')
	{
		map->cells[mine_pos / 10][mine_pos % 10].value = 'o';
		return (0);
	}
	else
		return (-1);
}

void	mine_generator(t_map *map, char *move)
{
	int	mine_pos;
	int	i;
	struct timeval	tv;

	i = 0;
	while (i < map->mine_number)
	{
		gettimeofday(&tv, NULL);
		mine_pos = abs(rand() - tv.tv_usec) % (map->height * map->width + 1);
		if (mine_check(map, move, mine_pos) == 0 && fill_mine_cell(map, mine_pos) == 0)
			i++;
	}
	// while ()
	// return (mine_pos);
}

void	fill_cells_numbers(t_map *map, int *mine_pos)
{
	int	i;


}


void	generate_map(t_map *map)
{
	int			i;
	char		*move;
	// int			*mine_pos;

	i = -1;
	move = malloc(sizeof(char) * 3);
	move = first_move(map);
	mine_generator(map, move);
	print_map(map);

}

