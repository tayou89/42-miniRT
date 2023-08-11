#include "parsing.h"

static char	*get_error_message(int error_number);

void	ft_parsing_error(int error_number, int exit_number, t_parsing *parsing)
{
	char	*error_message;

	error_message = get_error_message(error_number);
	printf("Error\n");
	printf("%s\n", error_message);
	free_every_parsing_data(parsing);
	exit(exit_number);
}

static char	*get_error_message(int error_number)
{
	if (error_number == ARGC_ERROR)
		return ("Wrong argument.");
	else if (error_number == EXTENSION_ERROR)
		return ("Wrong file extension.");
	else if (error_number == DATA_ERROR)
		return ("Wrong file data.");
	else
		return (strerror(errno));
}
