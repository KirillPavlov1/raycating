/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:43:37 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:43:39 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_extension(char *file, char *end)
{
	int	i;

	i = -1;
	while (file[++i] && file[i] != '.')
		;
	if (ft_strlen(&file[i]) != ft_strlen(end))
		return (0);
	if (!file[i] || (ft_strncmp(&file[i], end, ft_strlen(&file[i]))))
		return (0);
	return (1);
}
