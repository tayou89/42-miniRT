#include "parsing.h"

static void	check_argc(int argc);
static void	check_file_extension(char *file_name);
static char	*get_file_extension(char *file_name);
static void	open_file(char *file_name, t_parsing *data);

void	parse_data(int argc, char **argv, t_data *all)
{
	t_parsing	data;

	check_argc(argc);
	check_file_extension(argv[1]);
	open_file(argv[1], &data);
	parse_file_data(&data, all);
}

static void	check_argc(int argc)
{
	if (argc != 2)
		ft_parsing_error(ARGC_ERROR, 0);
}

static void	check_file_extension(char *file_name)
{
	char	*file_extension;
	char	*right_extension;
	int		file_extension_size;
	
	file_extension = get_file_extension(file_name);
	if (file_extension == (void *) 0)
		ft_parsing_error(EXTENSION_ERROR, 0);
	file_extension_size = ft_strlen(file_extension);
	right_extension = ".rt";
	if (ft_strncmp(right_extension, file_extension, file_extension_size) != 0)
		ft_parsing_error(EXTENSION_ERROR, 0);
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

static void	open_file(char *file_name, t_parsing *data)
{
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		ft_parsing_error(OPEN_ERROR, 1);
}
