/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:56:36 by yun               #+#    #+#             */
/*   Updated: 2021/03/23 15:08:00 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_all_b(t_pile *pile)
{
	while (pile->b[0] != NULL)
	{
		ft_putstr_fd(1, "pa\n");
		if (ft_push_a(pile))
			return (1);
	}
	return (0);
}

int	push_x_b(t_pile *pile, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_putstr_fd(1, "pa\n");
		if (ft_push_a(pile))
			return (1);
		i++;
	}
	return (0);
}

int	small_nb_pos(char **lst)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (lst[i])
	{
		if (compare_nb_value(lst[pos], lst[i]) > 0)
			pos = i;
		i++;
	}
	return (pos);
}

int	big_nb_pos(char **lst)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (lst[i])
	{
		if (compare_nb_value(lst[pos], lst[i]) < 0)
			pos = i;
		i++;
	}
	return (pos);
}

int	found_nb_swap(char **lst, int nb_pos)
{
	int	i;
	int	small;

	small = nb_pos;
	i = nb_pos;
	while (lst[i])
	{
		if (compare_nb_value(lst[i], lst[small]) <= 0)
			small = i;
		i++;
	}
	return (small);
}
