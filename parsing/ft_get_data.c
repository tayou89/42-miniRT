#include "parsing.h"

double	get_ratio_data(char *string, t_parsing *data)
{
	double	ratio;

	ratio = get_double(string, data);
	if (check_ratio_range(ratio) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, data);
	return (ratio);
}

t_color3	get_color_data(char *string, t_parsing *data)
{
	t_color3	color_data;

	if (string == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, data);
	data->info.rgb = get_splitted_array(string, ',', data);
	if (get_array_count((void *) rgb) != 3)
		ft_parsing_error(DATA_ERROR, 0, data);
	color_data.r = ft_atoi(data->info.rgb[0]);
	color_data.g = ft_atoi(data->info.rgb[1]);
	color_data.b = ft_atoi(data->info.rgb[2]);
	if (check_rgb_range(color_data.r) == FALSE
		|| check_rgb_range(color_data.g) == FALSE
		|| check_rgb_range(color_data.b) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, data);
	return (color_data);
}
