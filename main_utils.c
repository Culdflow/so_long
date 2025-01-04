/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:01:17 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/31 01:59:26 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_maps(t_mlx *mlx)
{
	if (mlx->map->map)
		free_map(mlx->map->map);
	if (mlx->map->map2)
		free_map(mlx->map->map2);
	if (mlx->map->map_pathfinding)
		free_map(mlx->map->map_pathfinding);
	if (mlx->map->collectible_list)
		clear_list(mlx->map->collectible_list);
}

void	exit_game(t_mlx *mlx)
{
	del_images(mlx);
	free_maps(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx->map);
	free(mlx->player);
	free(mlx);
}
