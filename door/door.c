/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:21:41 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/22 20:03:41 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door.h"

static void	replace_door(t_map *map)
{
	t_vector	cursor;

	cursor = vec2(0, 0);
	while (map->map[cursor.y])
	{
		cursor.x = 0;
		while (map->map[cursor.y][cursor.x])
		{
			if (map->map[cursor.y][cursor.x] == 'E')
				map->map[cursor.y][cursor.x] = 'B';
			cursor.x++;
		}
		cursor.y++;
	}
}

void	check_door(t_map *map, t_player *player)
{
	if (collectible_len(map->collectible_list) == player->collectibles)
		replace_door(map);
}

t_vector	get_door_pos(t_map *map)
{
	t_vector	cursor;

	cursor = vec2(0, 0);
	while (map->map[cursor.y])
	{
		cursor.x = 0;
		while (map->map[cursor.y][cursor.x])
		{
			if (map->map[cursor.y][cursor.x] == 'E'
					|| map->map[cursor.y][cursor.x] == 'B')
				return (cursor);
			cursor.x++;
		}
		cursor.y++;
	}
	return (vec2(-1, -1));
}
