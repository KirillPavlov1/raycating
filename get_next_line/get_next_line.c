/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:24:48 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:37:52 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1000

int		free_mem(char **str, char *a, char *buf)
{
	if (a)
	{
		free(buf);
		return (1);
	}
	if (buf)
		return (0);
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
		return (0);
	}
	return (0);
}

char	*install_mem(int n)
{
	char *str;

	if (!(str = (char*)malloc(n * sizeof(char))))
		return (NULL);
	str[0] = '\0';
	return (str);
}

int		checking(char **line, char *old, char **a)
{
	char *s;

	*a = NULL;
	if (old)
		if ((*a = ft_strchr2(old, '\n')))
		{
			**a = '\0';
			if (!(*line = ft_strdup(old)))
				return (-1);
			ft_strcpy(old, ++*a);
		}
		else
		{
			if (!(*line = install_mem(1)))
				return (-1);
			s = *line;
			if (!(*line = ft_strjoin(*line, old)))
				return (-1);
			free(s);
			return (0);
		}
	else if (!(*line = install_mem(1)))
		return (-1);
	return (1);
}

int		gnl_join(char *buf, char **line, char **a, char **old)
{
	char *c;

	if ((*a = ft_strchr2(buf, '\n')))
	{
		**a = '\0';
		*old = ft_strdup(++*a);
	}
	c = *line;
	if (!(*line = ft_strjoin(*line, buf)))
		return (0);
	free_mem(&c, NULL, NULL);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	char		*a;
	static char *old;
	int			i;
	int			k;

	i = 0;
	if (fd < 0 || read(fd, old, 0) == -1 || BUFFER_SIZE < 1 ||
		!line || !(buf = install_mem(BUFFER_SIZE + 1)) ||
		(k = checking(line, old, &a) == -1))
		return (-1);
	if (free_mem(NULL, a, buf))
		return (1);
	if (!k)
		free_mem(&old, NULL, NULL);
	while (!a && (i = read(fd, buf, BUFFER_SIZE)))
	{
		if (i < 0 || BUFFER_SIZE < 1 || fd < 0)
			return (-1);
		buf[i] = '\0';
		if (!(gnl_join(buf, line, &a, &old)))
			return (-1);
	}
	free_mem(&buf, NULL, NULL);
	return (i ? 1 : 0);
}
