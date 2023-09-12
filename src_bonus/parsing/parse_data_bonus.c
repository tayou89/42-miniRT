#include "parsing_bonus.h"

static void	initialize_data(t_parsing *parsing);
static void	check_file_extension(char *file_name, t_parsing *parsing);
static char	*get_file_extension(char *file_name);
static void	open_file(char *file_name, t_parsing *parsing);

void	parse_data(int argc, char **argv, t_data *data)
{
	t_parsing	parsing;

	initialize_data(&parsing);
	if (argc != 2)
		ft_parsing_error(ARGC_ERROR, 0, &parsing);
	check_file_extension(argv[1], &parsing);
	open_file(argv[1], &parsing);
	parse_file(&parsing);
	*data = parsing.data;
}

static void	initialize_data(t_parsing *parsing)
{
	parsing->data.count.ambient = 0;
	parsing->data.count.camera = 0;
	parsing->data.count.light = 0;
	parsing->data.obj = (void *) 0;
	parsing->data.light = (void *) 0;
	parsing->file.line = (void *) 0;
	parsing->line.info = (void *) 0;
	parsing->info.color = (void *) 0;
	parsing->info.coordinate = (void *) 0;
	parsing->info.vector = (void *) 0;
	parsing->info.ratio = (void *) 0;
	parsing->info.diameter = (void *) 0;
	parsing->info.height = (void *) 0;
	parsing->info.fov = (void *) 0;
	parsing->info.width = (void *) 0;
	parsing->info.length = (void *) 0;
}

static void	check_file_extension(char *file_name, t_parsing *parsing)
{
	char	*file_extension;
	char	*right_extension;
	int		file_extension_size;

	file_extension = get_file_extension(file_name);
	if (file_extension == (void *) 0)
		ft_parsing_error(EXTENSION_ERROR, 0, parsing);
	file_extension_size = ft_strlen(file_extension);
	right_extension = ".rt";
	if (ft_strncmp(right_extension, file_extension, file_extension_size) != 0)
		ft_parsing_error(EXTENSION_ERROR, 0, parsing);
}

static char	*get_file_extension(char *file_name)
{
	int	dot_index;
	int	i;

	dot_index = -1;
	i = 0;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '.')
			dot_index = i;
		i++;
	}
	if (dot_index == -1)
		return ((void *) 0);
	return (&file_name[dot_index]);
}

static void	open_file(char *file_name, t_parsing *parsing)
{
	parsing->file.fd = open(file_name, O_RDONLY);
	if (parsing->file.fd < 0)
		ft_parsing_error(OPEN_ERROR, 1, parsing);
}
