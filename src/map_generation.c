
#include "minesweeper.h"

char	*first_move(t_map *map)
{
	char	*move;
	int		i;  //lines
	int		j;  //row

	move = malloc(sizeof(char) * 3);
	read(1, move, 2);
	move[2] = '\0';
	printf("move choose : %s\n", move);
	if ('a' <= move [0] && move[0] <= 'z')
		move[0] = move[0] - 32;
	i = move[0] - 'A';
	j = move[1] - '0';
	map->table[i][j].value = 'i';
	map->table[i][j].fliped = true;
	return (move);
}

int	move_to_index(char *move)
{
	return ((move[0] - 'A') * 10 + move[1] - '0');
}

int	mine_check(t_map *map, char *move, int mine)
{
	// t_cell	cell;
	int	i;
	int	j;

	i = move[0] - 'A';
	j = move[1] - '0';
	if (mine == map->table[i][j].index)
		return (1);
	if (mine == map->table[i][j].nw_cell
		|| mine == map->table[i][j].n_cell
		|| mine == map->table[i][j].ne_cell)
		return (1);
	if (mine == map->table[i][j].e_cell
		|| mine == map->table[i][j].w_cell)
		return (1);
	if (mine == map->table[i][j].sw_cell
		|| mine == map->table[i][j].s_cell
		|| mine == map->table[i][j].se_cell)
		return (1);
	return (0);
}


int	fill_mine_cell(t_map *map, int mine_pos)
{
	int	i;

	if (map->table[mine_pos / 10][mine_pos % 10].value != 'o')
		return (0);
	else
		return (printf("loop\n"), -1);
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
		// printf("<pos>\n");
		k = (abs(rand() - (int)tv.tv_usec / 10000));
		// printf("k : %d\n", k);
		mine_pos = k % map->cell_amount;
		printf("pos[%d] : %d\n", i, mine_pos);
		if (mine_check(map, move, mine_pos) == 0 && fill_mine_cell(map, mine_pos) == 0)
		{
			i++;
			map->table[mine_pos / 10][mine_pos % 10].value = 'o';
		}
	}
	return (map->table);
	// while ()
	// return (mine_pos);
}

t_cell	**fill_cells_numbers(t_map *map)
{
	int	i;
	int j;

	while (i < map->height)
	{
		j = 0;
		while(j < map->width)
		{


			j++;
		}
		i++;
	}
	return(map->table);
}


void	generate_map(t_map *map)
{
	int			i;
	char		*move;
	// int			*mine_pos;

	i = -1;
	print_map(map);
	move = first_move(map);
	map->table = mine_generator(map, move);
	map->table = fill_cells_numbers(map);
	// printf("%d\n", map->cells[0][1].value);
	free(move);
}

