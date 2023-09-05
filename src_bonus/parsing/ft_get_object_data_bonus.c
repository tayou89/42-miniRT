#include "parsing_bonus.h"

void	get_sphere_data(t_data *data, t_info *info, t_parsing *parsing)
{
	t_sp	*new_sphere;
	t_list	*node;

	new_sphere = make_sphere_node(info, parsing);
	if (new_sphere == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	node = create_node(new_sphere, SPHERE);
	if (node == NULL)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	push_back(&data->obj, node);
}

void	get_plane_data(t_data *data, t_info *info, t_parsing *parsing)
{
	t_pl	*new_plane;
	t_list	*node;

	new_plane = make_plane_node(info, parsing);
	if (new_plane == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	node = create_node(new_plane, PLANE);
	if (node == NULL)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	push_back(&data->obj, node);
}

void	get_cylinder_data(t_data *data, t_info *info, t_parsing *parsing)
{
	t_cy	*new_cylinder;
	t_list	*node;

	new_cylinder = make_cylinder_node(info, parsing);
	if (new_cylinder == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	node = create_node(new_cylinder, CYLINDER);
	if (node == NULL)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	push_back(&data->obj, node);
}
