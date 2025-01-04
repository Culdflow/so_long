/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:14:28 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/28 00:23:45 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	count_images(t_mlx *mlx)//counts number of 'Layers' AKA images
{
	int	count;

	count = 0;
	while (mlx->imgs[count].img)
		count++;
	return (count);
}

void	add_image(t_mlx *mlx, t_img img)//Adds a t_img as 'Layer'
{
	int	nb_images;

	nb_images = count_images(mlx);
	mlx->imgs[nb_images] = img;
	mlx->imgs[nb_images + 1].img = NULL;
}

void	del_images(t_mlx *mlx)//Deletes all layers
{
	int	nb_imgs;

	nb_imgs = count_images(mlx) - 1;
	if (nb_imgs == -1)
		return ;
	while (nb_imgs >= 0 && mlx->imgs[nb_imgs].img)
	{
		mlx_destroy_image(mlx->mlx, mlx->imgs[nb_imgs].img);
		mlx->imgs[nb_imgs].img = NULL;
		nb_imgs--;
	}
}
