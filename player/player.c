/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 04:32:47 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/28 00:39:53 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	draw_player(t_mlx *mlx, t_player *player)
{
	xpm_file_to_img(mlx, "../sprites/mc.xpm", player->pos);
}

t_player	*setup_player(t_map *map)
{
	t_player	*result;
	t_vector	index;

	result = malloc(sizeof(t_player));
	index = vec2(0, 0);
	result->collectibles = 0;
	result->nb_moves = 0;
	while (map->map[index.y])
	{
		index.x = 0;
		while (map->map[index.y][index.x])
		{
			if (map->map[index.y][index.x] == 'P')
				result->pos = index;
			index.x++;
		}
		index.y++;
	}
	result->collectibles = 0;
	return (result);
}

void	remove_player(t_map *map, t_vector val, t_vector new_pos)
{
	while (map->map2[val.y])
	{
		val.x = 0;
		while (map->map2[val.y][val.x])
		{
			if (map->map2[val.y][val.x] == 'P' && !compare_vec2(val, new_pos)
					&& map->map[new_pos.y][new_pos.x] != '1'
					&& map->map[new_pos.y][new_pos.x] != 'E')
			{
				map->map[val.y][val.x] = '0';
				map->map2[val.y][val.x] = '0';
				break ;
			}
			val.x++;
		}
		val.y++;
	}
}

void	move_player(t_player *player, t_map *map, t_vector dir, t_mlx *mlx)
{
	t_vector	new_pos;
	t_vector	val;

	val = vec2(0, 0);
	new_pos = add_vec2(player->pos, dir);
	clamp_vec2(&new_pos, vec2(0, 0), map->size);
	remove_player(map, val, new_pos);
	if (map->map[new_pos.y][new_pos.x] != '1'
		&& map->map[new_pos.y][new_pos.x] != 'E')
	{
		player->nb_moves++;
		ft_printf("number of moves: %d\n", player->nb_moves);
		if (map->map[new_pos.y][new_pos.x] == 'C')
		{
			player->collectibles += 1;
			check_door(map, player);
		}
		if (map->map[new_pos.y][new_pos.x] == 'B')
			mlx_loop_end(mlx->mlx);
		map->map[new_pos.y][new_pos.x] = 'P';
		map->map2[new_pos.y][new_pos.x] = 'P';
		player->pos = new_pos;
	}
}
