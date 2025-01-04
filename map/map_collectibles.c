/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_collectibles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:51:40 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/28 00:43:11 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_collectible	*new_collectible(t_vector pos)
{
	t_collectible	*result;

	result = malloc(sizeof(t_collectible));
	result->pos = pos;
	result->next_collectible = NULL;
	return (result);
}

t_collectible	*get_last_collectible(t_collectible *start)
{
	if (!start->next_collectible)
		return (start);
	return (get_last_collectible(start->next_collectible));
}

int	collectible_len(t_collectible *el)
{
	if (el->next_collectible == NULL)
		return (1);
	return (1 + collectible_len(el->next_collectible));
}

t_collectible	*add_collectible(t_map *map, t_collectible *el)
{
	t_collectible	*cursor;

	if (map->collectible_list == NULL)
		map->collectible_list = el;
	else
	{
		cursor = get_last_collectible(map->collectible_list);
		cursor->next_collectible = el;
	}
	return (el);
}

void	clear_list(t_collectible *start)
{
	t_collectible	*tmp;

	tmp = start->next_collectible;
	if (!start)
		return ;
	free(start);
	if (tmp == NULL)
		return ;
	clear_list(tmp);
}
