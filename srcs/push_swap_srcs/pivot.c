/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:52:38 by yun               #+#    #+#             */
/*   Updated: 2021/03/30 11:04:19 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*return_pivot(char **lst, int pos_pivot)
{
	if (!lst || pos_pivot < 0)
		return (NULL);
	return (ft_strdup(lst[pos_pivot]));
}

char	**ft_dup_lst(char **src, int size)
{
	char	**ret;
	int		i;

	ret = malloc((size + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = ft_strdup(src[i]);
		if (!ret[i])
		{
			free(ret);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
