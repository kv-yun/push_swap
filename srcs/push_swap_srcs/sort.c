/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:10:45 by yun               #+#    #+#             */
/*   Updated: 2021/03/30 11:11:13 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_pivot(t_pile *pile, int	size, char *pivot)
{
	int	i;

	if (!pivot)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		if (compare_nb_value(pivot, pile->a[0]) > 0)
		{
			ft_putstr_fd(1, "pb\n");
			if (ft_push_b(pile))
				return (1);
			i++;
		}
		else
		{
			ft_putstr_fd(1, "ra\n");
			ft_rotate_a(pile, 0);
		}
	}
	return (0);
}

static int	ft_sort_big(t_pile *pile, char **lst_sort, int size_lst, int max)
{
	int		ct;
	int		pivot_pos;
	char	*pivot;

	ct = 1;
	while (ct < max + 1)
	{
		pivot_pos = (size_lst / max) * ct;
		pivot = return_pivot(lst_sort, pivot_pos);
		if (ft_sort_pivot(pile, size_lst / max, pivot))
			return (1);
		free(pivot);
		ct++;
	}
	while (pile->a[0])
	{
		ft_putstr_fd(1, "pb\n");
		if (ft_push_b(pile))
			return (1);
	}
	return (0);
}

static void	road_to_nb_b(t_pile *pile, int nb_pos)
{
	int	nb_move;
	int	i;

	i = 0;
	if (nb_pos > size_dtab(pile->b) / 2)
	{
		nb_move = size_dtab(pile->b) - nb_pos;
		while (i < nb_move)
		{
			ft_putstr_fd(1, "rrb\n");
			ft_rotate_b(pile, 1);
			i++;
		}
	}
	else
	{
		while (i < nb_pos)
		{
			ft_putstr_fd(1, "rb\n");
			ft_rotate_b(pile, 0);
			i++;
		}
	}
}

static int	ft_sort_end(t_pile *pile)
{
	int	next_nb;

	while (pile->b[0] != NULL)
	{
		next_nb = big_nb_pos(pile->b);
		road_to_nb_b(pile, next_nb);
		ft_putstr_fd(1, "pa\n");
		if (ft_push_a(pile))
			return (1);
	}
	return (0);
}

int	ft_sort(t_pile *pile, int ac)
{
	char	**lst_sort;
	int		swap;
	int		i;

	lst_sort = ft_dup_lst(pile->a, size_dtab(pile->a));
	swap = 1;
	i = 0;
	while (i < size_dtab(lst_sort))
	{
		swap = found_nb_swap(lst_sort, i);
		ft_swap(&lst_sort[swap], &lst_sort[i]);
		i++;
	}
	if (!lst_sort)
		return (1);
	if (ac - 1 > 100 && ft_sort_big(pile, lst_sort, size_dtab(pile->a), 11))
		return (1);
	else if (ac - 1 <= 100
		&& ft_sort_big(pile, lst_sort, size_dtab(pile->a), 5))
		return (1);
	if (ft_sort_end(pile))
		return (1);
	free_dtab(lst_sort);
	return (0);
}
