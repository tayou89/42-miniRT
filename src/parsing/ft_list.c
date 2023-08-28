#include "datasheet.h"
#include <stdlib.h>

void	push_back(t_list *world, void *elem)
{
	if (world == NULL)
		world = elem;
	else
	{
		while (world->next != NULL)
			world = world->next;
		world->element = elem;
	}
}

void	free_list(t_list *world)
{
	void	*del;

	while (world != NULL)
	{
		del = world;
		world = world->next;
		free(del);
	}
}
