
#ifndef MINESWEEPER_H
# define MINESWEEPER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>

typedef struct s_cell		t_cell;

typedef struct s_cell
{
	bool		fliped;
	char		value;
	int			index;
	int			nw_cell;
	int			n_cell;
	int			ne_cell;
	int			w_cell;
	int			e_cell;
	int			sw_cell;
	int			s_cell;
	int			se_cell;
}				t_cell;

typedef struct s_map
{
	int			mine_number;
	int			width;
	int			height;
	int			cell_amount;
	t_cell		**cells;
}				t_map;



void	init_map(t_map *map, char *choice, char **av);
void	generate_map(t_map *map);
void	print_map(t_map *map);

void	print_map_choice();

#endif
