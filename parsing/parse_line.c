#include "parsing.h"

static void	get_line_string(t_parsing *data)

void	parse_line(t_parsing *data, t_data *all)
{
	data->line.info = get_splitted_array(data->file.line, ' ', data);
	check_identifier(data, all);
	get_element_information(data, all);
}
