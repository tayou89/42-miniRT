#include "parsing.h"

static int		get_number(char *string, int sign, t_parsing *data);
static int		check_string_is_real_number(char *string, int index);
static double	get_decimal(char *string);

int	get_integer(char *string, t_parsing *parsing)
{
	int	integer;
	int	sign;
	int	index;

	if (string == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	index = 0;
	sign = get_sign(&index, string);
	if (ft_isdigit(string[index]) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	integer = get_number(&string[index], sign, parsing);
	return (integer);
}

static int	get_number(char *string, int sign, t_parsing *parsing)
{
	int	after_number;
	int	before_number;
	int	i;

	before_number = 0;
	i = 0;
	while (ft_isdigit(string[i]) == TRUE)
	{
		after_number = before_number * 10 + ((string[i] - '0') * sign);
		if (after_number / 10 != before_number)
			ft_parsing_error(DATA_ERROR, 0, parsing);
		before_number = after_number;
		i++;
	}
	return (after_number);
}

double	get_double(char *string, t_parsing *parsing)
{
	double	double_number;
	int		integer;
	double	decimal;
	int		sign;
	int		i;

	if (string == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	i = 0;
	sign = get_sign(&i, string);
	if (check_string_is_real_number(string, i) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	integer = get_integer(&string[i], parsing);
	while (ft_isdigit(string[i]) == TRUE)
		i++;
	if (string[i++] == '\0')
		return ((double) integer * sign);
	decimal = get_decimal(&string[i]);
	double_number = (integer + decimal) * sign;
	if (double_number == 0)
		return (0);
	return (double_number);
}

static int	check_string_is_real_number(char *string, int index)
{
	int	integer_digit;
	int	dot_count;

	if (ft_isdigit(string[index]) == FALSE)
		return (FALSE);
	integer_digit = 0;
	dot_count = 0;
	while (string[index] != '\0')
	{
		if (ft_isdigit(string[index]) == TRUE || string[index] == '.')
		{
			if (ft_isdigit(string[index]) == TRUE && dot_count == 0)
				integer_digit++;
			if (string[index] == '.')
				dot_count++;
			if (string[index] == '.' && ft_isdigit(string[index + 1]) == FALSE)
				return (FALSE);
			if (integer_digit > 10 || dot_count > 1)
				return (FALSE);
		}
		else
			return (FALSE);
		index++;
	}
	return (TRUE);
}

static double	get_decimal(char *string)
{
	double	decimal;
	double	divisor;
	int		i;

	decimal = 0;
	divisor = 10;
	i = 0;
	while (divisor < 1000 && ft_isdigit(string[i]) == TRUE)
	{
		decimal = decimal + (string[i++] - '0') / divisor;
		divisor *= 10;
	}
	if (ft_isdigit(string[i]) == TRUE && string[i] >= '5')
		decimal += 0.01;
	return (decimal);
}
