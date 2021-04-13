/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:41:47 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:41:49 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**make_map(t_list *map, int size)
{
	char	**new_map;
	int		i;

	i = -1;
	new_map = ft_calloc(ft_lstsize(map) + 1, sizeof(char *));
	while (++i < size)
	{
		new_map[i] = map->content;
		map = map->next;
	}
	i = -1;
	return (new_map);
}
