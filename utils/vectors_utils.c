/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:31:44 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/22 20:16:29 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector	mul_vec2(t_vector vec1, t_vector vec2)//Returns vec1 * vec2
{
	t_vector	result;

	result.x = vec1.x * vec2.x;
	result.y = vec1.y * vec2.y;
	return (result);
}

void	clamp_vec2(t_vector *vec, t_vector min, t_vector max)
{
	clamp(&vec->x, min.x, max.x);
	clamp(&vec->y, min.y, max.y);
}

int	compare_vec2(t_vector vec1, t_vector vec2)
{
	return (vec1.x == vec2.x && vec1.y == vec2.y);
}
