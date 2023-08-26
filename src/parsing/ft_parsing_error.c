#include "parsing.h"

static char	*get_error_message(int error_number);
static char	*get_error_identifier(int identifier);

void	ft_parsing_error(int error_number, int exit_number, t_parsing *parsing)
{
	char	*error_message;
	char	*error_identifier;

	error_message = get_error_message(error_number);
	printf("Error\n");
	printf("%s\n", error_message);
	if (error_number == DATA_ERROR)
	{
		error_identifier = get_error_identifier(parsing->info.identifier);
		printf("error_identifier: %s\n", error_identifier);
	}
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

static char	*get_error_identifier(int identifier)
{
	if (identifier == AMBIENT)
		return ("AMBIENT");
	else if (identifier == CAMERA)
		return ("CAMERA");
	else if (identifier == LIGHT)
		return ("LIGHT");
	else if (identifier == SPHERE)
		return ("SPHERE");
	else if (identifier == PLANE)
		return ("PLANE");
	else
		return ("CYLINDER");
}
