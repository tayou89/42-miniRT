#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "datasheet.h"
# include "initialize.h"
# include "utils_vec.h"
# include "utils_viewport.h"

# define FOCAL_LENGTH	1

typedef struct s_diff
{
	t_vec3	vector;
	t_vec3	point;
}	t_diff;

void	get_viewport_data(t_data *data);
void	calculate_viewport_data(t_data *data, t_viewport normal, t_camera temp);

#endif
