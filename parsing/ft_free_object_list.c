#include "parsing.h"

void	free_object_list(t_data *data)
{
	if (data->sphere != (void *) 0)
		data->sphere = free_sphere_list(data->sphere);
	if (data->plane != (void *) 0)
		data->plane = free_plane_list(data->plane);
	if (data->cylinder != (void *) 0)
		data->cylinder = free_cylinder_list(data->cylinder);
}

t_sp	*free_sphere_list(t_sp *sphere)
{
	t_sp	*head;
	
	while (sphere != (void *) 0)
	{
		head = sphere;
		sphere = sphere->next;
		free(head);
	}
	return (sphere);
}

t_pl	*free_plane_list(t_pl *plane)
{
	t_pl	*head;
	
	while (plane != (void *) 0)
	{
		head = plane;
		plane = plane->next;
		free(head);
	}
	return (plane);
}

t_cy	*free_cylinder_list(t_cy *cylinder)
{
	t_cy	*head;
	
	while (cylinder != (void *) 0)
	{
		head = cylinder;
		cylinder = cylinder->next;
		free(head);
	}
	return (cylinder);
}
