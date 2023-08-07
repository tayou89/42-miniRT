#include "parsing.h"

static int	get_identifier(char *identifier);
static void	count_element(int identifier, t_data *all);
static void	check_element_exception(t_data *all);
static void	check_information_count(int	identifier, char **split);

void	parse_line(char *line, t_data *all)
{
	char	**split;
	int		identifier;

	split = ft_split(line, ' ');
	if (split == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1);
	if (split[0] == (void *) 0)
		split = free_2d_array(split);
	if (split == (void *) 0)
		return ;
	identifier = get_identifier(split[0]);
	count_element(identifier, all);
	check_element_exception(all);
	check_information_count(identifier, split);
	get_element_information(identifier, split, all);
	split = free_2d_array(split);
}

static int	get_identifier(char *identifier)
{
	int	identifier_size;

	identifier_size = ft_strlen(identifier);
	if (ft_strncmp("A", identifier, identifier_size) == 0)
		return (AMBIENT);
	else if (ft_strncmp("C", identifier, identifier_size) == 0)
		return (CAMERA);
	else if (ft_strncmp("L", identifier, identifier_size) == 0)
		return (LIGHT);
	else if (ft_strncmp("sp", identifier, identifier_size) == 0)
		return (SPHERE);
	else if (ft_strncmp("pl", identifier, identifier_size) == 0)
		return (PLANE);
	else if (ft_strncmp("cy", identifier, identifier_size) == 0)
		return (CYLINDER);
	else
		ft_parsing_error(DATA_ERROR, 0);
}

static void	count_element(int identifier, t_data *all)
{
	if (identifier == AMBIENT)
		all->count.ambient++;
	else if (identifier == CAMERA)
		all->count.camera++;
	else if (identifier == LIGHT)
		all->count.light++;
	else if (identifier == SPHERE)
		all->count.sp++;
	else if (identifier == PLANE)
		all->count.pl++;
	else if (identifier == CYLINDER)
		all->count.cy++;
}

static void	check_element_exception(t_data *all)
{
	if (all->count.ambient > 1 || all->count.camera > 1
		|| all->count.light > 1)
		ft_parsing_error(DATA_ERROR, 0);
	if (all->count.sp < 0 || all->count.pl < 0
		|| all->count.cy < 0)
		ft_parsing_error(DATA_ERROR, 0);
}

static void	check_information_count(int	identifier, char **split)
{
	int	array_count;
	int	i;

	i = 0;
	while (split[i] != (void *) 0)
		i++;
	array_count = i;
	if ((identifier == AMBIENT || identifier == CAMERA) && array_count != 3)
		ft_parsing_error(DATA_ERROR, 0);
	else if ((identifier == LIGHT || identifier == SPHERE
			|| identifier == PLANE) && array_count != 4)
		ft_parsing_error(DATA_ERROR, 0);
	else if (identifier == CYLINDER && array_count != 6)
		ft_parsing_error(DATA_ERROR, 0);
}
