/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:12:41 by yun               #+#    #+#             */
/*   Updated: 2021/03/30 14:25:17 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(int fd, char **str)
{
	char	buff[BUFFER_SIZE + 1];
	int		size;
	char	*tmp;

	size = 1;
	while (size && (ft_strchr(*str, '\n') == 0))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 0 || str == NULL)
			return (-1);
		if (fd >= 0)
		{
			buff[size] = '\0';
			tmp = ft_strdup_start(*str, 0);
			free(*str);
			*str = ft_strjoin(tmp, buff);
			free(tmp);
		}
	}
	return (size);
}

char	*ft_get_line(char **str, char *line)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	tmp = ft_strdup_start(*str, 0);
	while (j < i)
	{
		line[j] = (*str)[j];
		j++;
	}
	line[j] = '\0';
	free(*str);
	*str = NULL;
	if (tmp && tmp[i] != '\0')
		*str = ft_strdup_start(tmp, i + 1);
	if (tmp)
		free(tmp);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int			size;
	static char	*str;

	if (BUFFER_SIZE == 0 || fd < 0 || !line)
		return (-1);
	if (str == NULL)
		str = ft_calloc(1, sizeof(char));
	size = ft_check(fd, &str);
	if (size < 0)
	{
		free(str);
		str = NULL;
		return (-1);
	}
	*line = ft_get_line(&str, *line);
	if (size == 0)
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (0);
	}
	return (1);
}
