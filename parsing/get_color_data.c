#include "parsing.h"

void	get_color_data(char *color, t_parsing *data)
{
	if (color == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, data);
	data->info.rgb = get_splitted_array(color, ',', data);
	check_rgb_form(data->info.rgb, data);
}

char **split_color_by_comma(char *color, t_parsing *data)
{
	char **splitted_array;

	splitted_array = ft_split(color, ',');
	if (splitted_array == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, data);
	return (splitted_array);
}

void	check_rgb_form(char **rgb, t_parsing *data)
{
	check_rgb_count(rgb, data);
}

void	check_rgb_count(char **rgb
