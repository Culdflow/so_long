/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:44:11 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/07 01:41:48 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_map_surrounded(t_map *map)
{
	t_vector	cursor;

	cursor = vec2(0, 0);
	while (map->map[cursor.y][cursor.x] && map->map[cursor.x])
	{
		if (map->map[cursor.y][cursor.x] != '1'
				|| map->map[cursor.x][cursor.y] != '1')
			return (0);
		cursor.x++;
	}
	cursor = vec2(0, map->size.y - 1);
	while (map->map[cursor.y][cursor.x])
	{
		if (map->map[cursor.y][cursor.x] != '1')
			return (0);
		cursor.x++;
	}
	cursor = vec2(map->size.x - 1, 0);
	while (map->map[cursor.y])
	{
		if (map->map[cursor.y][cursor.x] != '1')
			return (0);
		cursor.y++;
	}
	return (1);
}

static int	check_tile(t_map *map, char tile,
			t_vector cursor, t_vector *pos_exit)
{
	if (tile != 'P' && tile != 'E' && tile != 'C'
		&& tile != '0' && tile != '1' && tile != 'B')
		return (-1);
	if (tile == 'E')
	{
		pos_exit->y++;
		map->exit_pos = cursor;
	}
	if (tile == 'C')
		add_collectible(map, new_collectible(cursor));
	if (tile == 'P')
	{
		pos_exit->x++;
		map->start_pos = cursor;
	}
	return (0);
}

void	check_map(t_map *map, t_mlx *mlx)
{
	t_vector	cursor;
	t_vector	pos_exit;
	t_vector	open_zero;

	pos_exit = vec2(0, 0);
	open_zero = vec2(0, 0);
	cursor = vec2(0, 0);
	while (map->map[cursor.y])
	{
		cursor.x = 0;
		while (map->map[cursor.y][cursor.x])
		{
			if (check_tile(map, map->map[cursor.y][cursor.x],
								cursor, &pos_exit) == -1)
				error("unsupported character in map", mlx);
			if (map->map[cursor.y][cursor.x] == 'B')
				open_zero.x++;
			if (map->map[cursor.y][cursor.x++] == '0')
				open_zero.y++;
		}
		cursor.y++;
	}
	if (map->collectible_list == NULL || !compare_vec2(pos_exit, vec2(1, 1))
		|| open_zero.x > 0 || open_zero.y <= 0
		|| check_map_surrounded(map) == 0)
		error("map invalid", mlx);
}
