/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:31:40 by dfeve             #+#    #+#             */
/*   Updated: 2024/11/26 22:35:53 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	result;

	result = 0;
	while (str && str[result])
		result++;
	return (result);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		size;
	char	*result;

	i = 0;
	size = (int)ft_strlen(s);
	result = malloc((size * sizeof(char)) + 1);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while ((size_t)i < size - 1 && dst && src[i])
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	if (i == 0)
	{
		dst[i] = '\0';
		return (ft_strlen(src));
	}
	if (dst[i - 1])
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	size_t	len_s1;
	size_t	len_s2;
	size_t	result_len;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result_len = len_s1 + len_s2 + 1;
	result = malloc(result_len);
	i = 0;
	if (!result)
		return (NULL);
	while (i < (int)result_len - 1)
	{
		if (i < (int)len_s1 && s1[i])
			result[i] = s1[i];
		else
			result[i] = s2[i - (int)len_s1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		size;
	char	*result;

	if (!s)
		return (NULL);
	if ((int)(start) > ft_strlen(s))
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
	}
	else
	{
		if ((int)(start + len) > ft_strlen(s))
			size = ft_strlen(s) - start + 1;
		else
			size = len + 1;
		result = malloc(size);
		ft_strlcpy(result, s + start, size);
	}
	return (result);
}
