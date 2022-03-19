/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:42:40 by yun               #+#    #+#             */
/*   Updated: 2021/04/01 10:32:33 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	first_zero_valid(char *str, int first_nb)
{
	if (str[first_nb] == '0' && str[first_nb + 1] != '\0')
		return (1);
	return (0);
}

static int	is_nb_neg_valid(char *str)
{
	int			i;
	long int	nb_check;

	nb_check = 0;
	if (ft_strlen(str) > 11 || first_zero_valid(str, 1))
		return (1);
	i = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		nb_check = nb_check * 10 + str[i] - '0';
		i++;
	}
	nb_check = nb_check * -1;
	if (i == 1 || nb_check < -2147483648)
		return (1);
	return (0);
}

static int	is_nb_pos_valid(char *str)
{
	int					i;
	unsigned long long	nb_check;

	nb_check = 0;
	i = 0;
	if (ft_strlen(str) > 10 || first_zero_valid(str, 0))
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		nb_check = nb_check * 10 + str[i] - '0';
		i++;
	}
	if (i == 0 || nb_check > 2147483647)
		return (1);
	return (0);
}

static int	duplicate_int(char **lst)
{
	int	i;
	int	j;

	i = 0;
	while (lst[i])
	{
		j = i + 1;
		while (lst[j])
		{
			if (ft_strcmp(lst[i], lst[j]) == 0)
			{
				free_dtab(lst);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_lst(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		if (lst[i][0] == '-' && is_nb_neg_valid(lst[i]))
		{
			free_dtab(lst);
			return (1);
		}
		else if (lst[i][0] != '-' && is_nb_pos_valid(lst[i]))
		{
			free_dtab(lst);
			return (1);
		}
		i++;
	}
	return (duplicate_int(lst));
}
