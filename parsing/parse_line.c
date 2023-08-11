#include "parsing.h"

static void	get_line_string(t_parsing *data)

void	parse_line(t_parsing *parsing)
{
	parsing->line.info = get_splitted_array(parsing->file.line, ' ', parsing);
	check_identifier(parsing);
	get_element_information(parsing);
}
