/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:10:10 by yun               #+#    #+#             */
/*   Updated: 2021/03/30 14:33:03 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 200

# include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);
int		ft_strlen(char *s);
int		get_next_line(int fd, char **line);
char	*ft_calloc(int nmemb, int size);
char	*ft_strdup_start(const char *str, int start);

#endif
