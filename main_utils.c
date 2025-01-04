/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:01:17 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/26 22:58:09 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_mlx *mlx)
{
	del_images(mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free_map(mlx->map->map);
	free_map(mlx->map->map2);
	free_map(mlx->map->map_pathfinding);
	clear_list(mlx->map->collectible_list);
	free(mlx->map);
	free(mlx->player);
	free(mlx);
}
