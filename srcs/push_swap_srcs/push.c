/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:15:54 by yun               #+#    #+#             */
/*   Updated: 2021/03/31 14:19:19 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	size_dtab(char **tab)
{
	int	size;

	if (tab[0] == NULL)
		return (0);
	size = 0;
	while (tab[size])
		size++;
	return (size);
}

static char	**new_malloc(char **last, char *new_elem, int size)
{
	char	**new;

	new = malloc((size + 2) * sizeof(char *));
	if (!new)
		return (free_dtab(last));
	new[0] = ft_strdup(new_elem);
	if (!new)
	{
		free(new);
		return (free_dtab(last));
	}
	size = 0;
	while (last[size])
	{
		new[size + 1] = ft_strdup(last[size]);
		if (!new[size + 1])
		{
			free(new);
			return (free_dtab(last));
		}
		size++;
	}
	new[size + 1] = NULL;
	free_dtab(last);
	return (new);
}

static char	**supp_line(char **last)
{
	char	**new;
	int		size;
	int		x;

	size = size_dtab(last);
	new = malloc((size) * sizeof(char *));
	if (!new)
		return (free_dtab(last));
	x = 0;
	size = 1;
	while (last[size])
	{
		new[x] = ft_strdup(last[size]);
		if (!new)
		{
			free(new);
			return (free_dtab(last));
		}
		x++;
		size++;
	}
	new[x] = NULL;
	free_dtab(last);
	return (new);
}

int	ft_push_b(t_pile *pile)
{
	if (!pile->a || pile->a[0] == NULL)
		return (0);
	pile->b = new_malloc(pile->b, pile->a[0], size_dtab(pile->b));
	if (!pile->b)
		return (1);
	pile->a = supp_line(pile->a);
	if (!pile->a)
		return (1);
	return (0);
}

int	ft_push_a(t_pile *pile)
{
	if (!pile->b || pile->b[0] == NULL)
		return (0);
	pile->a = new_malloc(pile->a, pile->b[0], size_dtab(pile->a));
	if (!pile->a)
		return (1);
	pile->b = supp_line(pile->b);
	if (!pile->b)
		return (1);
	return (0);
}
