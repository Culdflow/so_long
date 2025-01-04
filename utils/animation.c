/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:40:37 by dfeve             #+#    #+#             */
/*   Updated: 2024/11/28 03:23:19 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	count_frame_nb(t_anim *anim)//Counts frame number
{
	int	result;

	result = 0;
	while (anim->frames[result])
		result++;
	return (result);
}

t_anim	new_anim(char *frames)//Create new anim struct
{
	t_anim	result;

	result.frames = frames;
	result.current_frame = 0;
	result.frame_nb = count_frame_nb(&result);
	return (result);
}
