/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:44:08 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:05:34 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	cross_sprite2(t_mlx *lib, int x, t_sprite *tmp)
{
	if (lib->map[(int)lib->s_dot.y - 1][(int)lib->s_dot.x] == '2')
	{
		if (lib->s_dot.y - (int)lib->s_dot.y == 0
			&& lib->s_dot.x - (int)lib->s_dot.x != 0)
		{
			while ((tmp->x - 0.5) != (int)lib->s_dot.x
				|| (tmp->y - 0.5) != (int)lib->s_dot.y - 1)
				tmp = tmp->next;
			if (tmp->visible == 0)
			{
				tmp->visible = 1;
				tmp->startx = x;
			}
			else
				tmp->endx = x;
			return (0);
		}
	}
	return (1);
}

static int	cross_sprite3(t_mlx *lib, int x, t_sprite *tmp)
{
	if (lib->map[(int)lib->s_dot.y][(int)lib->s_dot.x - 1] == '2')
	{
		if (lib->s_dot.y - (int)lib->s_dot.y != 0
			&& lib->s_dot.x - (int)lib->s_dot.x == 0)
		{
			while ((int)(tmp->x - 0.5) != (int)lib->s_dot.x - 1
				|| (int)(tmp->y - 0.5) != (int)lib->s_dot.y)
				tmp = tmp->next;
			if (tmp->visible == 0)
			{
				tmp->visible = 1;
				tmp->startx = x;
			}
			else
				tmp->endx = x;
			return (0);
		}
	}
	return (1);
}

int			cross_sprite(t_mlx *lib, int x)
{
	t_sprite	*tmp;

	tmp = lib->item;
	if (lib->map[(int)lib->s_dot.y][(int)lib->s_dot.x] == '1')
		return (0);
	if (lib->map[(int)lib->s_dot.y][(int)lib->s_dot.x] == '2')
	{
		while ((int)(tmp->x - 0.5) != (int)lib->s_dot.x
			|| (int)(tmp->y - 0.5) != (int)lib->s_dot.y)
			tmp = tmp->next;
		if (tmp->visible == 0)
		{
			tmp->visible = 1;
			tmp->startx = x;
		}
		else
			tmp->endx = x;
		return (0);
	}
	if (!(cross_sprite2(lib, x, tmp)))
		return (0);
	if (!(cross_sprite3(lib, x, tmp)))
		return (0);
	return (1);
}
