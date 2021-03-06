/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:43:46 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:43:48 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!(ft_strchr("NEWS 102", line[i])))
			return (0);
	}
	if (line[0] == '\0')
		return (0);
	return (1);
}
