/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:29:30 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/26 22:51:53 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	**ft_upscale_map(char **map, char *new_line)
{
	char	**result;
	int		i;

	i = 0;
	while (map && map[i])
		i++;
	result = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (map && map[i])
	{
		result[i] = map[i];
		i++;
	}
	result[i] = new_line;
	result[i + 1] = 0;
	free(map);
	return (result);
}

static int	parse_map(t_map *map, char *map_line, int i)//Parses line from map
{
	if (i == 0)
		map->size.x = ft_strlen(map_line);
	else if (ft_strlen(map_line) != map->size.x)
		error("map not rectangular");
	map->map[i] = malloc(sizeof(char) * (map->size.x + 1));
	ft_strlcpy(map->map[i], map_line, ft_strlen(map_line) + 1);
	map->map[i + 1] = NULL;
	return (1);
}

void	check_map_extension(char *src)
{
	char	*src_extension;

	src_extension = src + (ft_strlen(src) - 4);
	if (strncmp(src_extension, ".ber", ft_strlen(src_extension)) != 0)
		error("map extension not valid");
}

static void	read_map_loop(char *map_buf, t_map *result, int fd)
{
	int	i;

	i = 0;
	while (map_buf)
	{
		free(map_buf);
		map_buf = get_next_line(fd);
		if (map_buf)
		{
			if (ft_strchr(map_buf, '\n') != NULL)
				*ft_strchr(map_buf, '\n') = 0;
			result->map = ft_upscale_map(result->map, map_buf);
			parse_map(result, map_buf, i);
			i++;
		}
	}
	free(map_buf);
	result->size.y = i;
	result->map[i] = NULL;
}

t_map	*read_map(char *src)
{
	t_map	*result;
	char	*map_buf;
	int		fd;

	check_map_extension(src);
	result = map_null();
	map_buf = malloc(1);
	map_buf[0] = 0;
	fd = open(src, O_RDONLY);
	if (fd < 0)
		error("file nonexistant");
	result->map = malloc(sizeof(char *));
	result->map[0] = 0;
	read_map_loop(map_buf, result, fd);
	close(fd);
	result->map2 = copy_map(result);
	return (result);
}
