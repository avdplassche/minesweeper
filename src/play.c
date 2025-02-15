

#include "minesweeper.h"


void	flood(t_map *map, int index)
{
	int	i;
	int	j;

	i = index / map->height;
	j = index % map->width;
	map->table[i][j].fliped = true;
	// printf("i = %d, j = %d\n", i, j);
	if (i > 0 && j > 0 && map->table[i - 1][j - 1].fliped == false)
	{
		if (map->table[i - 1][j - 1].value == ' ')
			flood(map, map->table[i - 1][j - 1].index);
		else
			map->table[i - 1][j - 1].fliped = true;
	}  //nw
	if (i > 0 && map->table[i - 1][j].fliped == false) //n
	{
		if (map->table[i - 1][j].value == ' ')
			flood(map, map->table[i - 1][j].index);
		else
			map->table[i - 1][j].fliped = true;
	}
	if (i > 0 && j < map->width - 1 && map->table[i - 1][j + 1].fliped == false) //ne
	{
		if (map->table[i - 1][j + 1].value == ' ')
			flood(map, map->table[i - 1][j + 1].index);
		else
			map->table[i - 1][j + 1].fliped = true;
	}
	if (j > 0 && map->table[i][j - 1].fliped == false)  //w
	{
		if (map->table[i][j - 1].value == ' ')
			flood(map, map->table[i][j - 1].index);
		else
			map->table[i][j - 1].fliped = true;
	}
	if (j < map->width - 1 && map->table[i][j + 1].fliped == false)    //e
	{
		if (map->table[i][j + 1].value == ' ')
			flood(map, map->table[i][j + 1].index);
		else
			map->table[i][j + 1].fliped = true;
	}
	if (j > 0 && i < map->height - 1 && map->table[i + 1][j - 1].fliped == false)     //sw
	{
		if (map->table[i + 1][j - 1].value == ' ')
			flood(map, map->table[i + 1][j - 1].index);
		else
			map->table[i + 1][j - 1].fliped = true;
	}
	if (i < map->height - 1 && map->table[i + 1][j].fliped == false)      //s
	{
		if (map->table[i + 1][j].value == ' ')
			flood(map, map->table[i + 1][j].index);
		else
		map->table[i + 1][j].fliped = true;
	}
	if (i < map->height - 1 && j < map->width - 1 && map->table[i + 1][j + 1].fliped == false)    //se
	{
		if (map->table[i + 1][j + 1].value == ' ')
			flood(map, map->table[i + 1][j + 1].index);
		else
			map->table[i + 1][j + 1].fliped = true;
	}
}


t_map	*play(t_map *map, char *move)
{
	int	i;
	int	j;

	i = move[0] - 'A';
	j = move[1] - '0';
	if (map->table[i][j].value == ' ')
		flood(map, map->table[i][j].index);
	else if (map->table[i][j].value == 'o')
	{
		map->lose = 1;
		map->table[i][j].fliped = true;
	}
	else
		map->table[i][j].fliped = true;
	return (map);
}
