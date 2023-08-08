#include "parsing.h"

static void	get_line_string(t_parsing *data)

void	parse_line(t_parsing *data, t_data *all)
{
	get_line_info(data);
	check_identifier(data, all);
	get_element_information(data, all);
}

static void	get_line_info(t_parsing *data)
{
	data->line.info = ft_split(line, ' ');
	if (data->line.info == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, data);
	if (data->line.info[0] == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, data);
}
