#include "parsing.h"

void	parse_line(t_parsing *parsing)
{
	classify_element_information(parsing->file.line, parsing);
	get_element_data(&parsing->info, parsing);
}
