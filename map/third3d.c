/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:40:50 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 16:40:53 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	nswe(t_mlx *lib)
{
	if (lib->s_dot.y - (int)lib->s_dot.y == 0)
		lib->state = 0;
	else
		lib->state = 1;
}

void	make_unvisible(t_mlx *lib)
{
	t_sprite	*tmp;

	tmp = lib->item;
	while (tmp)
	{
		tmp->visible = 0;
		tmp = tmp->next;
	}
}
