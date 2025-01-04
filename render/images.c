/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:35:56 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/28 00:19:18 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_imgs(t_mlx *mlx)//Puts all 'layers' to screen
{
	int	i;

	i = 0;
	while (i < count_images(mlx) && mlx->imgs[i].img)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs[i].img,
			mlx->imgs[i].pos.x, mlx->imgs[i].pos.y);
		i++;
	}
}

int	xpm_file_to_img(t_mlx *mlx, char *path,
				t_vector pos)//Creates t_img from xpm image
{
	t_img	img;
	void	*temp;

	temp = mlx_xpm_file_to_image(mlx->mlx, path, &img.size.x, &img.size.y);
	if (temp == NULL)
		return (-1);
	mlx_destroy_image(mlx->mlx, temp);
	img.img = mlx_xpm_file_to_image(mlx->mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.pos = pos;
	add_image(mlx, img);
	return (count_images(mlx) - 1);
}

int	new_image(t_mlx *mlx, t_vector size, t_vector pos)//Creates new t_img
{
	t_img	img;

	img.img = mlx_new_image(mlx->mlx, size.x, size.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.pos = pos;
	add_image(mlx, img);
	return (count_images(mlx) - 1);
}
