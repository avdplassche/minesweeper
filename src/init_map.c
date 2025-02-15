
#include "minesweeper.h"

bool	g_fliped = true;

t_cell	check_cell_borders(t_map *map, t_cell cell, int i, int j)
{
	if (cell.index < map->width)
	{
		cell.nw_cell = -1;
		cell.n_cell = -1;
		cell.ne_cell= -1;
	}
	if (cell.index % map->width == 0)
	{
		cell.nw_cell = -1;
		cell.w_cell = -1;
		cell.sw_cell = -1;
	}
	if (cell.index < map->cell_amount && (cell.index + 1) % map->width == 0)
	{
		cell.ne_cell = -1;
		cell.e_cell = -1;
		cell.se_cell = -1;
	}
	if (cell.index >= map->cell_amount - map->width)
	{
		cell.sw_cell = -1;
		cell.s_cell = -1;
		cell.se_cell = -1;
	}
	return (cell);
}

t_cell	fill_cell_borders(t_map *map, t_cell cell, int i, int j)
{
	cell.index = i * 10 + j;
	cell.nw_cell = cell.index - map->width - 1;
	cell.n_cell = cell.index - map->width;
	cell.ne_cell = cell.index - map->width + 1;
	cell.w_cell = cell.index - 1;
	cell.e_cell = cell.index + 1;
	cell.sw_cell = cell.index + map->width - 1;
	cell.s_cell = cell.index + map->width;
	cell.se_cell = cell.index + map->width + 1;
	cell = check_cell_borders(map, cell, i, j);
	return (cell);
}

void	fill_table_borders(t_map *map, t_cell **cells)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = -1;
		while (++j < map->height)
			cells[i][j] = fill_cell_borders(map, cells[i][j], i, j);
		i++;
	}
}

void init_map(t_map *map, char **av)
{
	int	i;
	int	j;
	t_cell **table;

	i = -1;
	map->height = atoi(av[1]);
	map->width = atoi(av[2]);
	map->cell_amount = map->width * map->height;
	map->mine_amount = map->cell_amount / 10;
	table = (t_cell **)malloc(sizeof(t_cell *) * map->height);
	print_map_datas(map);
	while (++i < map->width)
	{
		j = -1;
		table[i] = (t_cell *)malloc(sizeof(t_cell) * (map->width));
		while (++j < map->height)
		{
			table[i][j].value = '-';
			table[i][j].fliped = g_fliped;
		}
	}
	fill_table_borders(map, table);
	map->table = table;
}
