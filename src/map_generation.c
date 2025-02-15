
#include "minesweeper.h"

// int	move_to_index(char *move)
// {
// 	return ((move[0] - 'A') * 10 + move[1] - '0');
// }

int	mine_check(t_map *map, char *move, int mine)
{
	// t_cell	cell;
	int	i;
	int	j;

	i = move[0] - 'A';
	j = move[1] - '0';
	if (mine == map->table[i][j].index)
		return (-1);
	if (mine == map->table[i][j].nw_cell
		|| mine == map->table[i][j].n_cell
		|| mine == map->table[i][j].ne_cell)
		return (-1);
	if (mine == map->table[i][j].e_cell
		|| mine == map->table[i][j].w_cell)
		return (-1);
	if (mine == map->table[i][j].sw_cell
		|| mine == map->table[i][j].s_cell
		|| mine == map->table[i][j].se_cell)
		return (-1);
	return (0);
}


int	fill_mine_cell(t_map *map, int mine_pos)
{
	int	i;

	if (map->table[mine_pos / 10][mine_pos % 10].value != 'o')
		return (0);
	else
		return (-1);
}

t_cell	**mine_generator(t_map *map, char *move)
{
	int	mine_pos;
	int	i;
	struct timeval	tv;
	int	k;

	gettimeofday(&tv, NULL);
	i = 0;
	while (i < map->mine_amount)
	{
		k = (abs(rand() - (int)tv.tv_usec / 10000));
		mine_pos = k % map->cell_amount;
		if (mine_check(map, move, mine_pos) == 0 && fill_mine_cell(map, mine_pos) == 0)
		{
			printf("pos[%d] : %d\n", i, mine_pos);
			map->table[mine_pos / 10][mine_pos % 10].value = 'o';
			i++;
		}
	}
	return (map->table);
}

int	get_value(t_map *map, int i, int j)
{
	int	n;

	n = 0;
	if (map->table[i][j].value == 'o')
		return ('o');
	if (i > 0 && j > 0
		&& map->table[i - 1][j - 1].value == 'o')  //nw
		n++;
	if (i > 0
		&& map->table[i - 1][j].value == 'o') //n
		n++;
	if (i > 0 && j < map->width - 1
		&& map->table[i - 1][j +1].value == 'o') //ne
		n++;
	if (j > 0
		&& map->table[i][j - 1].value == 'o')
		n++;
	if (j < map->width - 1
		&& map->table[i][j + 1].value == 'o')
		n++;
	if (j > 0 && i < map->height - 1
		&& map->table[i + 1][j - 1].value == 'o')
		n++;
	if (i < map->height - 1
		&& map->table[i + 1][j].value == 'o')
		n++;
	if (i < map->height - 1 && j < map->width - 1
		&& map->table[i + 1][j + 1].value == 'o')
		n++;
	if (n > 0)
		return(n + 48);
	else
		return (' ');
}

t_cell	**fill_cells_numbers(t_map *map) //number or ' '
{
	int	i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			// printf("")
			map->table[i][j].value = get_value(map, i, j);
			j++;
		}
		i++;
	}
	return(map->table);
}

void	generate_map(t_map *map, char *move)
{
	int		i;

	i = -1;
	map->table = mine_generator(map, move);
	map->table = fill_cells_numbers(map);
}

