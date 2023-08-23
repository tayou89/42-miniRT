#ifndef UTILS_FREE_H
# define UTILS_FREE_H

# include "datasheet.h"
# include <stdlib.h>

void	free_object_list(t_data *data);
t_sp	*free_sphere_list(t_sp *sphere);
t_pl	*free_plane_list(t_pl *plane);
t_cy	*free_cylinder_list(t_cy *cylinder);

void	*free_2d_array(void **array);
void	*free_1d_array(void *array);

#endif
