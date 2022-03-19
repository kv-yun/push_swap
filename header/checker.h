/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:09:32 by yun               #+#    #+#             */
/*   Updated: 2021/04/03 14:52:37 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_pile
{
	char	**a;
	char	**b;
}		t_pile;

int		size_dtab(char **tab);
int		ft_strlen(char *str);
void	ft_putstr_fd(int fd, char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);
char	**free_dtab(char **tab);
void	ft_swap(char **s_1, char **s_2);
void	ft_swap_all(t_pile *pile);
void	ft_rotate_a(t_pile *pile, int type);
void	ft_rotate_b(t_pile *pile, int type);
void	ft_rotate_all(t_pile *pile, int type);
char	**ft_split(char *str, char c);
int		ft_push_a(t_pile *pile);
int		ft_push_b(t_pile *pile);
int		check_lst(char **lst);
int		disp_error(void);
int		checker_exec(t_pile *pile, char **cmd, int ac);
int		verif_order(char **lst, int init_size);

#endif
