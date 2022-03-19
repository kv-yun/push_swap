/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:25:36 by yun               #+#    #+#             */
/*   Updated: 2021/03/30 14:31:02 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_pile
{
	char	**a;
	char	**b;
}		t_pile;

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void	ft_putstr_fd(int fd, char *str);
void	ft_swap(char **s_1, char **s_2);
void	ft_swap_all(t_pile *pile);
void	ft_rotate_a(t_pile *pile, int type);
void	ft_rotate_b(t_pile *pile, int type);
int		ft_push_a(t_pile *pile);
int		ft_push_b(t_pile *pile);
int		check_lst(char **lst);
char	**free_dtab(char **tab);
char	**ft_split(char *str, int c);
int		verif_order(char **lst, int init_size);
int		compare_nb_value(char *s1, char *s2);
int		ft_sort(t_pile *pile, int ac);
int		disp_error(void);
int		size_dtab(char **tab);
int		check_lst(char **lst);
int		ft_strcmp(char *s1, char *s2);
int		pos_pivot(t_pile *pile);
int		ft_sort_short(t_pile *pile, int ac);
int		push_all_b(t_pile *pile);
int		push_x_b(t_pile *pile, int x);
int		big_nb_pos(char **lst);
int		small_nb_pos(char **lst);
char	*return_pivot(char **lst, int pos_pivot);
char	**ft_dup_lst(char **src, int size);
int		found_nb_swap(char **lst, int i);

#endif
