/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:38:56 by yun               #+#    #+#             */
/*   Updated: 2021/06/26 14:28:13 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_pile_a(char **av, int ac)
{
	char	**pile;
	int		i;

	pile = malloc (ac * sizeof(char *));
	if (!pile)
		return (NULL);
	i = 1;
	while (av[i])
	{
		pile[i - 1] = ft_strdup(av[i]);
		if (!pile)
		{
			free(pile);
			return (NULL);
		}
		i++;
	}
	pile[i - 1] = NULL;
	return (pile);
}

int	main(int ac, char **av)
{
	t_pile	pile;
	int		ret;

	if (ac == 1)
		return (0);
	pile.a = create_pile_a(av, ac);
	if (!pile.a || check_lst(pile.a))
		return (disp_error());
	if (verif_order(pile.a, ac - 1) == 0)
	{
		free_dtab(pile.a);
		return (0);
	}
	pile.b = malloc(2 * sizeof(char *));
	if (!pile.b && free_dtab(pile.a) == NULL)
		return (1);
	pile.b[0] = NULL;
	pile.b[1] = NULL;
	if (ac <= 50)
		ret = ft_sort_short(&pile, ac);
	else
		ret = ft_sort(&pile, ac);
	free_dtab(pile.a);
	free_dtab(pile.b);
	return (ret);
}
