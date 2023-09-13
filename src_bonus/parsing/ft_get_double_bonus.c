#include "parsing_bonus.h"

static double	get_int(char *s, int *i, int *digit, t_parsing *parsing);
static double	get_decimal(char *s, int *i, int digit, t_parsing *parsing);
static int		check_decimal_form(char *string, int *index);

double	get_double(char *string, t_parsing *parsing)
{
	double	double_number;
	double	decimal;
	int		integer_digit;
	int		sign;
	int		i;

	if (string == (void *) 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	i = 0;
	sign = get_sign(&i, string);
	double_number = get_int(string, &i, &integer_digit, parsing);
	decimal = get_decimal(string, &i, integer_digit, parsing);
	double_number += decimal;
	double_number *= sign;
	if (double_number == 0)
		return (0);
	return (double_number);
}

static double	get_int(char *s, int *i, int *digit, t_parsing *parsing)
{
	double	integer;

	if (ft_isdigit(s[*i]) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	integer = 0;
	while (ft_isdigit(s[*i]) == TRUE)
	{
		integer = integer * 10 + (s[*i] - '0');
		(*i)++;
	}
	*digit = *i;
	if (*digit > DOUBLE_DIGIT_MAX)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	return (integer);
}

static double	get_decimal(char *s, int *i, int digit, t_parsing *parsing)
{
	double	decimal;
	double	divisor;
	int		valid_digit;
	double	devisor_limit;

	if (s[*i] == '\0')
		return (0);
	if (check_decimal_form(s, i) == FALSE)
		ft_parsing_error(DATA_ERROR, 0, parsing);
	valid_digit = DOUBLE_DIGIT_MAX - digit;
	devisor_limit = pow(10, valid_digit);
	decimal = 0;
	divisor = 10;
	while (divisor <= devisor_limit && ft_isdigit(s[*i]) == TRUE)
	{
		decimal = decimal + (s[*i] - '0') / divisor;
		divisor *= 10;
		(*i)++;
	}
	if (ft_isdigit(s[*i]) == TRUE && s[*i] >= '5')
		decimal += 1 / devisor_limit;
	return (decimal);
}

static int	check_decimal_form(char *string, int *index)
{
	int	i;

	if (string[*index] == '.' && ft_isdigit(string[*index + 1]) == TRUE)
	{
		(*index)++;
		i = *index;
		while (ft_isdigit(string[i]) == TRUE)
			i++;
		if (string[i] == '\0')
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}
