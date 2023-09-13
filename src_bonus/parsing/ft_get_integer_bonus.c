/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_integer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:31:08 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:31:14 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

static int		get_number(char *string, int sign, t_parsing *data);

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
	if (string[i] != '\0')
		ft_parsing_error(DATA_ERROR, 0, parsing);
	return (after_number);
}
