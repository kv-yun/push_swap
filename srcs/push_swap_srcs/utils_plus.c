/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:10:43 by yun               #+#    #+#             */
/*   Updated: 2021/03/30 11:09:38 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	long	nb;
	int		type;
	int		i;

	type = 1;
	nb = 0;
	i = 0;
	if (str[0] == '-')
	{
		type = -1;
		i = 1;
	}
	while (str[i])
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * type);
}

int	disp_error(void)
{
	ft_putstr_fd(2, "Error\n");
	return (1);
}

int	disp_res(int type)
{
	if (type == 0)
		return (0);
	return (1);
}

int	compare_nb_value(char *s1, char *s2)
{
	int	nb_1;
	int	nb_2;

	if (!s1 || !s2)
		return (0);
	nb_1 = ft_atoi(s1);
	nb_2 = ft_atoi(s2);
	if (nb_1 > nb_2)
		return (1);
	else if (nb_1 < nb_2)
		return (-1);
	return (0);
}

int	verif_order(char **lst, int init_size)
{
	int	i;
	int	j;

	i = 0;
	while (lst[i])
	{
		j = i + 1;
		while (lst[j])
		{
			if (compare_nb_value(lst[i], lst[j]) > 0)
				return (disp_res(1));
			j++;
		}
		i++;
	}
	if (i != init_size)
		return (disp_res(1));
	return (disp_res(0));
}
