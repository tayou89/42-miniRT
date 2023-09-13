/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:31:27 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:31:29 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datasheet_bonus.h"
#include <stdlib.h>

t_list	*create_node(void *elem, int type)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->type = type;
	node->element = elem;
	node->next = NULL;
	return (node);
}

void	push_back(t_list **world, t_list *node)
{
	t_list	*now;

	if (*world == NULL)
		*world = node;
	else
	{
		now = *world;
		while (now->next != NULL)
			now = now->next;
		now->next = node;
	}
}

void	free_list(t_list *world)
{
	t_list	*del;

	while (world != NULL)
	{
		del = world;
		world = world->next;
		free(del->element);
		free(del);
	}
}
