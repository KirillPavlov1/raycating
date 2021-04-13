/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:46:00 by cvirgin           #+#    #+#             */
/*   Updated: 2021/04/13 17:04:45 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_sprite	*new_sprite(double x, double y)
{
	t_sprite	*new;

	new = malloc(sizeof(t_sprite));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->visible = 0;
	new->next = NULL;
	return (new);
}

void		sprite_add_back(t_sprite **item, t_sprite *new)
{
	t_sprite	*p;

	p = *item;
	if (p == NULL)
	{
		*item = new;
		return ;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}
