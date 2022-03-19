/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:14:09 by yun               #+#    #+#             */
/*   Updated: 2021/03/30 14:22:02 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_start(const char *s, int start)
{
	char	*copy;
	int		i;

	i = 0;
	while (s[start + i])
		i++;
	copy = malloc((i + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[start + i])
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_calloc(int nmemb, int size)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(nmemb * size);
	if (!cpy)
		return (NULL);
	while (i < (nmemb * size))
	{
		cpy[i] = '\0';
		i++;
	}
	return (cpy);
}
