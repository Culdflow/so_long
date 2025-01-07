/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:31:51 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/07 01:39:30 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "utils/utils.h"
# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct s_collectible
{
	t_vector				pos;
	struct s_collectible	*next_collectible;
}	t_collectible;

typedef struct s_map//map structure
{
	char				**map;
	char				**map2;
	char				**map_pathfinding;
	t_vector			size;
	t_vector			exit_pos;
	t_vector			start_pos;
	t_collectible		*collectible_list;
}	t_map;

//--------------------

typedef struct s_img//image structure
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_vector	pos;
	t_vector	size;
}	t_img;

typedef struct s_player
{
	t_vector	pos;
	int			collectibles;
	int			nb_moves;
}	t_player;

typedef struct s_mlx//mlx structure
{
	void		*mlx;
	void		*win;
	t_img		imgs[50000];
	t_map		*map;
	t_player	*player;
	int			framerate;
}	t_mlx;

//--------------------MAIN------------------------

void			exit_game(t_mlx *mlx);
t_mlx			*init_mlx(void);

//--------------------ERROR-----------------------

void			error(char	*text, t_mlx *mlx);

//--------------------render-----------------------

void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			put_imgs(t_mlx *mlx);
int				count_images(t_mlx *mlx);
void			add_image(t_mlx *mlx, t_img img);
int				new_image(t_mlx *mlx, t_vector size, t_vector pos);
void			del_images(t_mlx *mlx);
int				xpm_file_to_img(t_mlx *mlx, char *path, t_vector pos);
void			draw_rectangle(t_img *data, t_vector start,
					t_vector end, int color);

//--------------------pathfinding-----------------------

int				pathfinding(t_map *map, t_vector start, t_vector end);
int				check_pathfinding(t_map *map);

//--------------------MAP-------------------------

void			free_map(char **map);
void			draw_map(t_img *data, t_map map, t_vector size, int offset);
void			put_map(t_mlx *mlx, t_map *map);
char			**copy_map(t_map *map);
int				collectible_len(t_collectible *el);
void			clear_list(t_collectible *start);
void			check_map(t_map *map, t_mlx *mlx);
int				check_map_surrounded(t_map *map);
t_map			*read_map(char *src, t_mlx *mlx);
t_map			*map_null(void);
t_collectible	*add_collectible(t_map *start, t_collectible *el);
t_collectible	*new_collectible(t_vector pos);
t_collectible	*get_last_collectible(t_collectible *start);

//--------------------player-----------------------
t_player		*setup_player(t_map *map);
void			move_player(t_player *player, t_map *map,
					t_vector dir, t_mlx *mlx);
void			draw_player(t_mlx *mlx, t_player *player);

//----------------------door----------------------------

void			check_door(t_map *map, t_player *player);
t_vector		get_door_pos(t_map *map);
#endif