#include "parsing.h"

static int	get_sign(int *i, char *string);
static int	check_number_form(char *string, int index);

double	ft_atod(char *string)
{
	double	number;
	int		sign;
	int		i;

	if (string == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0);
	i = 0;
	sign = get_sign(&i, string);
	if (check_number_form(string, i) == FALSE)
		ft_parsing_error(DATA_ERROR, 0);
	number = get_number(string, i) * sign;
	return (number);
}

static int	get_sign(int *i, char *string)
{
	if (string[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (string[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	else
		return (1);
}

static int	check_number_form(char *string, int index)
{
	int	degit_size;
	int	decimal_size;
	int	dot_count;

	if (ft_isdigit(string[index]) == FALSE)
		return (FALSE);
	degit_size = 0;
	decimal_size = 0;
	dot_count = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '.')
			dot_count++;
		else if (dot_count == 0 && ft_isdigit(string[index]) == TRUE)
			degit_size++;
		else if (dot_count == 1 && ft_isdigit(string[index]) == TRUE)
			decimal_size++;
		else
			return (FALSE);
		index++;
	}
	if (degit_size > 10 || decimal_size > 2)
		return (FALSE);
	return (TRUE);
}
