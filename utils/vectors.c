/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:00:16 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/22 20:16:13 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector	vec2(int x, int y)//Returns vector2 with values x and y
{
	t_vector	result;

	result.x = x;
	result.y = y;
	return (result);
}

t_vector	vec2_make_start(t_vector start, t_vector end)
{
	t_vector	result;

	result.x = start.x;
	if (start.x > end.x)
		result.x = end.x;
	result.y = start.y;
	if (start.y > end.y)
		result.y = end.y;
	return (result);
}

t_vector	vec2_make_end(t_vector start, t_vector end)//Reverse vec2_make_start
{
	t_vector	result;

	result.x = end.x;
	if (start.x > end.x)
		result.x = start.x;
	result.y = end.y;
	if (start.y > end.y)
		result.y = start.y;
	return (result);
}

t_vector	add_vec2(t_vector vec1, t_vector vec2)//returns vec1 + vec2
{
	t_vector	result;

	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	return (result);
}

t_vector	sub_vec2(t_vector vec1, t_vector vec2)//Returns vec1 - vec2
{
	t_vector		result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	return (result);
}
