/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:55:37 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/07 01:35:41 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error(char *text, t_mlx *mlx)
{
	if (mlx)
		exit_game(mlx);
	write(2, "\e[0;31m[ERROR] : \033[0m", 22);
	perror(text);
	exit(1);
}
