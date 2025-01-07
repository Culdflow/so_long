/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:01:17 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/07 01:39:11 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->framerate = 0;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->player = NULL;
	mlx->map = NULL;
	return (mlx);
}

void	exit_game(t_mlx *mlx)
{
	if (count_images(mlx) > 0)
		del_images(mlx);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	if (mlx->map && mlx->map->map)
		free_map(mlx->map->map);
	if (mlx->map && mlx->map->map2)
		free_map(mlx->map->map2);
	if (mlx->map && mlx->map->map_pathfinding)
		free_map(mlx->map->map_pathfinding);
	if (mlx->map && mlx->map->collectible_list)
		clear_list(mlx->map->collectible_list);
	if (mlx->map)
		free(mlx->map);
	if (mlx->player)
		free(mlx->player);
	if (mlx)
		free(mlx);
}
