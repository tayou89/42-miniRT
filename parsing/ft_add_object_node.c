#include "parsing.h"

t_sp	*add_sphere_node(t_sp *new, t_sp *list)
{
	t_sp	*head;

	head = list;
	while (list->next != (void *) 0)
		list = list->next;
	list->next = new;
	new->prev = list;
	return (head);
}

t_pl	*add_plane_node(t_pl *new, t_pl *list)
{
	t_pl	*head;

	head = list;
	while (list->next != (void *) 0)
		list = list->next;
	list->next = new;
	new->prev = list;
	return (head);
}

t_cy	*add_cylinder_node(t_cy *new, t_cy *list)
{
	t_cy	*head;

	head = list;
	while (list->next != (void *) 0)
		list = list->next;
	list->next = new;
	new->prev = list;
	return (head);
}
