/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 03:35:20 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/28 00:40:29 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_input(int keycode, t_mlx *mlx)//Manage keyboard input
{
	if (keycode == K_ESC)
		mlx_loop_end(mlx->mlx);
	else if (keycode == K_A)
		move_player(mlx->player, mlx->map, vec2(-1, 0), mlx);
	else if (keycode == K_D)
		move_player(mlx->player, mlx->map, vec2(1, 0), mlx);
	else if (keycode == K_W)
		move_player(mlx->player, mlx->map, vec2(0, -1), mlx);
	else if (keycode == K_S)
		move_player(mlx->player, mlx->map, vec2(0, 1), mlx);
	return (1);
}

int	game_loop(t_mlx *mlx)
{
	mlx->framerate += 1;
	if (mlx->framerate >= 10000)
	{
		mlx->framerate = 0;
		del_images(mlx);
		put_map(mlx, mlx->map);
		put_imgs(mlx);
	}
	return (1);
}

void	read_map_file(char *src)
{
	char	*src_extension;

	src_extension = src + (ft_strlen(src) - 4);
	printf("%s\n", src_extension);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		error("wrong number of arguments (must be 1)");
	mlx = malloc(sizeof(t_mlx));
	mlx->framerate = 0;
	mlx->map = read_map(argv[1]);
	mlx->map->map_pathfinding = copy_map(mlx->map);
	check_map(mlx->map);
	if (check_pathfinding(mlx->map) != 1)
		error("not possible to finish map");
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1010, "fenetre de con");
	mlx->player = setup_player(mlx->map);
	mlx->imgs[0].img = NULL;
	mlx_hook(mlx->win, ON_KEYDOWN, 1L << 0, _input, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, mlx_loop_end, mlx->mlx);
	mlx_loop_hook(mlx->mlx, game_loop, mlx);
	mlx_loop(mlx->mlx);
	exit_game(mlx);
}
