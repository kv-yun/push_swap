/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:21:17 by yun               #+#    #+#             */
/*   Updated: 2021/03/11 15:38:30 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

int	ft_strcmp(char *s1, char *s2)
{
	int					i;
	unsigned char		c1;
	unsigned char		c2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s2[i] || s1[i])
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*r;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	r = malloc((sizeof(char) * i) + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	**free_dtab(char **tab)
{
	int	size;

	size = size_dtab(tab);
	while (size >= 0)
	{
		free(tab[size]);
		size--;
	}
	free(tab);
	return (NULL);
}
