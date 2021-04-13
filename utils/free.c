/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:44:28 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:44:30 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../libft/libft.h"

void	free2dem(char **str)
{
	size_t	x;
	size_t	i;

	x = -1;
	i = 0;
	while (str[++x])
		;
	while (i < x)
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

void	freemap(t_list *map)
{
	t_list	*copy;
	int		k;

	k = ft_lstsize(map);
	while (k--)
	{
		copy = map->next;
		free(map->content);
		free(map);
		map = copy;
	}
}
