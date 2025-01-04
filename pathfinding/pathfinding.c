/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:27:10 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/23 19:28:42 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinding.h"

static int	check_move(t_map *map, t_vector pos)
{
	if (pos.x >= (map->size.x - 1) || pos.y >= (map->size.y - 1)
		|| pos.x < 0 || pos.y < 0)
		return (-1);
	if (map->map[pos.y][pos.x] == '1'
		|| map->map_pathfinding[pos.y][pos.x] == 'F'
		|| map->map[pos.y][pos.x] == 'E')
		return (-1);
	map->map_pathfinding[pos.y][pos.x] = 'F';
	return (0);
}

int	pathfinding(t_map *map, t_vector start, t_vector end)
{
	int			val;
	t_vector	next_pos;

	val = 0;
	if (compare_vec2(start, end))
		return (1);
	if (check_move(map, start) == -1)
		return (0);
	next_pos = add_vec2(start, vec2(1, 0));
	val += pathfinding(map, next_pos, end);
	next_pos = add_vec2(start, vec2(0, 1));
	val += pathfinding(map, next_pos, end);
	next_pos = add_vec2(start, vec2(-1, 0));
	val += pathfinding(map, next_pos, end);
	next_pos = add_vec2(start, vec2(0, -1));
	val += pathfinding(map, next_pos, end);
	if (val > 0)
		return (1);
	return (0);
}

static void	reset_pathfinding_map(t_map *map)
{
	t_vector	cursor;

	cursor = vec2(0, 0);
	while (map->map[cursor.y])
	{
		cursor.x = 0;
		while (map->map[cursor.y][cursor.x])
		{
			map->map_pathfinding[cursor.y][cursor.x]
				= map->map[cursor.y][cursor.x];
			cursor.x++;
		}
		cursor.y++;
	}
}

static int	check_pathfinding_coll(t_map *map, t_collectible *end)
{
	if (pathfinding(map, map->start_pos, end->pos) != 1)
		return (0);
	if (end->next_collectible == NULL)
		return (1);
	reset_pathfinding_map(map);
	return (check_pathfinding_coll(map, end->next_collectible));
}

int	check_pathfinding(t_map *map)
{
	t_vector	door_pos;

	door_pos = get_door_pos(map);
	if (check_pathfinding_coll(map, map->collectible_list) != 1)
		return (0);
	reset_pathfinding_map(map);
	if (pathfinding(map, map->start_pos, door_pos) != 1)
		return (0);
	return (1);
}
