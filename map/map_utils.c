/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:36:58 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/22 23:52:25 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_map(char **map)//frees map
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

t_map	*map_null(void)//Returns t_img NULL
{
	t_map	*result;

	result = malloc(sizeof(t_map));
	result->map = NULL;
	result->map2 = NULL;
	result->size = vec2(0, 0);
	result->collectible_list = NULL;
	result->exit_pos = vec2(-1, -1);
	result->start_pos = vec2(-1, -1);
	return (result);
}

void	render_tile(t_mlx *mlx, t_map *map,
					t_vector cursor, t_vector map_cursor)
{
	if (map->map[map_cursor.y][map_cursor.x] == '1')
		xpm_file_to_img(mlx, "sprites/wall.xpm", cursor);
	else if (map->map[map_cursor.y][map_cursor.x] == '0')
		xpm_file_to_img(mlx, "sprites/floor.xpm", cursor);
	else if (map->map[map_cursor.y][map_cursor.x] == 'P')
		xpm_file_to_img(mlx, "sprites/mc.xpm", cursor);
	else if (map->map[map_cursor.y][map_cursor.x] == 'E')
		xpm_file_to_img(mlx, "sprites/door_closed.xpm", cursor);
	else if (map->map[map_cursor.y][map_cursor.x] == 'C')
		xpm_file_to_img(mlx, "sprites/collectible.xpm", cursor);
	else if (map->map[map_cursor.y][map_cursor.x] == 'B')
		xpm_file_to_img(mlx, "sprites/door_open.xpm", cursor);
	else
		error("Invalid character in map");
}

void	put_map(t_mlx *mlx, t_map *map)
{
	t_vector	screen_size;
	t_vector	map_cursor;
	t_vector	cursor;

	mlx_get_screen_size(mlx->mlx, &screen_size.x, &screen_size.y);
	map_cursor = vec2(0, 0);
	cursor = vec2((screen_size.x - (map->size.x * 20)) / 2,
			(screen_size.y - (map->size.y * 20)) / 2);
	while (map->map[map_cursor.y])
	{
		map_cursor.x = 0;
		cursor.x = (screen_size.x - (map->size.x * 20)) / 2;
		while (map->map[map_cursor.y][map_cursor.x])
		{
			render_tile(mlx, map, cursor, map_cursor);
			cursor.x += 20;
			map_cursor.x++;
		}
		cursor.y += 20;
		map_cursor.y++;
	}
}

char	**copy_map(t_map *map)
{
	char		**result;
	t_vector	pos;

	result = malloc((map->size.y + 1) * sizeof(char *));
	pos = vec2(0, 0);
	while (map->map[pos.y])
	{
		pos.x = 0;
		result[pos.y] = malloc(map->size.x + 1);
		while (map->map[pos.y][pos.x])
		{
			result[pos.y][pos.x] = map->map[pos.y][pos.x];
			pos.x++;
		}
		result[pos.y][pos.x] = 0;
		pos.y++;
	}
	result[pos.y] = 0;
	return (result);
}
