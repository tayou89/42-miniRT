#include "parsing.h"

char	**get_splitted_array(char *array, char seperator, t_parsing *data)
{
	char	**splitted_array;

	splitted_array = ft_split(array, seperator);
	if (splitted_array == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, data);
	if (splitted_array[0] == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, data);
	return (splitted_array);
}

int	get_array_count(void **array)
{
	int	array_count;
	int	i;

	if (array == (void *) 0)
		return (0);
	i = 0;
	while (array[i] != (void *) 0)
		i++;
	array_count = i;
	return (array_count);
}
