#include "parsing.h"

double	ft_atod(char *string)
{
	double	number;
	int		sign;
	int		i;

	if (string == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0);
	i = 0;
	sign = get_sign(&i, string);

	return (number);
}

static int	get_sign(int *i, char *string)
{
	if (string[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (string[*i] = '+')
	{
		(*i)++;
		return (1);
	}
	else
		return (1);
}


