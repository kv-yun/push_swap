/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:31:31 by yun               #+#    #+#             */
/*   Updated: 2021/05/28 11:44:52 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(char **s_1, char **s_2)
{
	char	*tmp;

	tmp = NULL;
	if (s_1 == NULL || s_2 == NULL)
		return ;
	tmp = *s_1;
	*s_1 = *s_2;
	*s_2 = tmp;
	tmp = NULL;
}

void	ft_swap_all(t_pile *pile)
{
	if (pile->a[0] && pile->a[1])
		ft_swap(&pile->a[0], &pile->a[1]);
	if (pile->b[0] && pile->b[1])
		ft_swap(&pile->b[0], &pile->b[1]);
}

void	ft_rotate_a(t_pile *pile, int type)
{
	int	i;

	if (!pile->a || pile->a[0] == NULL || pile->a[1] == NULL)
		return ;
	i = 0;
	while (pile->a[i + 1])
	{
		if (type == 0)
			ft_swap(&pile->a[i], &pile->a[i + 1]);
		i++;
	}
	while (i > 0)
	{
		if (type == 1)
			ft_swap(&pile->a[i], &pile->a[i - 1]);
		i--;
	}
}

void	ft_rotate_b(t_pile *pile, int type)
{
	int	i;

	if (!pile->b || pile->b[0] == NULL || pile->b[1] == NULL)
		return ;
	i = 0;
	while (pile->b[i + 1])
	{
		if (type == 0)
			ft_swap(&pile->b[i], &pile->b[i + 1]);
		i++;
	}
	while (i > 0)
	{
		if (type == 1)
			ft_swap(&pile->b[i], &pile->b[i - 1]);
		i--;
	}
}

void	ft_rotate_all(t_pile *pile, int type)
{
	ft_rotate_a(pile, type);
	ft_rotate_b(pile, type);
}
