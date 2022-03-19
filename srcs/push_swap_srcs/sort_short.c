/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:45:33 by yun               #+#    #+#             */
/*   Updated: 2021/03/31 14:31:41 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reduce_pile_a_plus(t_pile *pile, int i, int pos)
{
	if (pos > size_dtab(pile->a) / 2)
	{
		pos = size_dtab(pile->a) - pos;
		while (i < pos)
		{
			ft_rotate_a(pile, 1);
			ft_putstr_fd(1, "rra\n");
			i++;
		}
	}
	else if (pos > 0)
	{
		while (i < pos)
		{
			ft_rotate_a(pile, 0);
			ft_putstr_fd(1, "ra\n");
			i++;
		}
	}
}

static int	reduce_pile_a(t_pile *pile, int pos)
{
	while (size_dtab(pile->a) > 3)
	{
		pos = small_nb_pos(pile->a);
		reduce_pile_a_plus(pile, 0, pos);
		ft_putstr_fd(1, "pb\n");
		if (ft_push_b(pile))
			return (1);
	}
	return (0);
}

static int	sort_a(t_pile *pile)
{
	if (size_dtab(pile->a) <= 1)
		return (0);
	if (compare_nb_value(pile->a[0], pile->a[1]) > 0)
	{
		ft_putstr_fd(1, "sa\n");
		ft_swap(&pile->a[0], &pile->a[1]);
	}
	if (size_dtab(pile->a) == 2 || verif_order(pile->a, 3) == 0)
		return (0);
	if (compare_nb_value(pile->a[0], pile->a[2]) > 0
		|| compare_nb_value(pile->a[1], pile->a[2]))
	{
		ft_putstr_fd(1, "rra\n");
		ft_rotate_a(pile, 1);
	}
	if (compare_nb_value(pile->a[0], pile->a[1]) > 0)
	{
		ft_putstr_fd(1, "sa\n");
		ft_swap(&pile->a[0], &pile->a[1]);
	}
	return (0);
}

int	ft_sort_short(t_pile *pile, int ac)
{
	if (ac - 1 > 3)
		reduce_pile_a(pile, 0);
	sort_a(pile);
	if (ac - 1 > 3)
		push_all_b(pile);
	return (verif_order(pile->a, ac - 1));
}
