/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:25:34 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:24:27 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 1000

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_strchr2(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, char *src);
int		checking(char **line, char *old, char **a);
int		gnl_join(char *buf, char **line, char **a, char **old);
int		get_next_line(int fd, char **line);
char	*install_mem(int n);
int		free_mem(char **str, char *a, char *buf);
#endif
