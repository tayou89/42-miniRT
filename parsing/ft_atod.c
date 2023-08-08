#include "parsing.h"

static int		get_sign(int *i, char *string);
static int		check_number_form(char *string, int index);
static double	get_double_number(char *string);

double	ft_atod(char *string, t_parsing *data)
{
	double	number;
	int		sign;
	int		i;

	if (string == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, data);
	i = 0;
	sign = get_sign(&i, string);
	if (check_number_form(string, i) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, data);
	number = get_double_number(&string[i]) * sign;
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
	int	integer_digit;
	int	dot_count;

	if (ft_isdigit(string[index]) == FALSE)
		return (FALSE);
	integer_digit = 0;
	dot_count = 0;
	while (string[index] != '\0')
	{
		if (ft_isdigit(string[index]) == TRUE)
		{
			if (dot_count == 0)
				integer_digit++;
		}
		else if (string[index] == '.')
		{
			dot_count++;
			if (ft_isdigit(string[index + 1]) == FALSE)
				return (FALSE);
		}
		else
			return (FALSE);
		index++;
	}
	if (integer_digit > 10 || dot_count > 1)
		return (FALSE);
	return (TRUE);
}

static double	get_double_number(char *string)
{
	double		number;
	double		decimal;
	double		divisor;
	int			i;

	number = 0;
	i = 0;
	while (ft_isdigit(string[i]) == TRUE)
		number = number * 10 + (string[i++] - '0');
	if (string[i++] == '\0')
		return (number);
	decimal = 0;
	divisor = 10;
	while (divisor < 1000 && ft_isdigit(string[i]) == TRUE)
	{
		decimal = decimal + (string[i++] - '0') / divisor;
		divisor *= 10;
	}
	if (ft_isdigit(string[i]) == TRUE && string[i] >= '5')
		decimal += 0.01;
	number += decimal;
	return (number);
}
