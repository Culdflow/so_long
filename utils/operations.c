/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:27:52 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/22 20:16:56 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clamp(int *nb, int min, int max)
{
	if (min > max)
		return ;
	if (*nb < min)
		*nb = min;
	else if (*nb > max)
		*nb = max;
}

int	biggest_nb(int a, int b, int c, int d)
{
	int	tmp;
	int	result;

	if (a >= b)
		result = 1;
	else
		result = 2;
	if (c >= d)
		tmp = 3;
	else
		tmp = 4;
	if (result <= tmp)
		result = tmp;
	return (result);
}
