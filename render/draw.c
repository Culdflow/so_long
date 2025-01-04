/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:15:04 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/22 20:14:48 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	my_mlx_pixel_put(t_img *data, int x,
					int y, int color)//puts pixel on screen
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle(t_img *data, t_vector start,
					t_vector end, int color)//draws rectangle
{
	t_vector	cursor;
	t_vector	goal;
	int			x;

	cursor = vec2_make_start(start, end);
	x = cursor.x;
	goal = vec2_make_end(start, end);
	while (cursor.y <= goal.y)
	{
		cursor.x = x;
		while (cursor.x <= goal.x)
		{
			my_mlx_pixel_put(data, cursor.x, cursor.y, color);
			cursor.x++;
		}
		cursor.y++;
	}
}
