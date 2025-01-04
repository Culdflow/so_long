/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:55:37 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/31 02:02:38 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error(char *text, t_mlx *mlx)
{
	perror(text);
	if (mlx)
		exit_game(mlx);
	exit(0);
}
