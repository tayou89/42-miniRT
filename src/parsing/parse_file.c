/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:52 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 19:54:25 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*remove_newline(char *line);
static int	check_line_if_substance_exist(char *line);
static void	check_data_count(t_count count, t_parsing *parsing);

void	parse_file(t_parsing *parsing)
{
	parsing->file.line = get_next_line(parsing->file.fd, 0);
	if (parsing->file.line == (void *) 0)
		ft_parsing_error(MALLOC_ERROR, 1, parsing);
	while (parsing->file.line != (void *) 0)
	{
		parsing->file.line = remove_newline(parsing->file.line);
		if (check_line_if_substance_exist(parsing->file.line) == TRUE)
			parse_line(parsing);
		free(parsing->file.line);
		parsing->file.line = get_next_line(parsing->file.fd, 0);
	}
	close(parsing->file.fd);
	check_data_count(parsing->data.count, parsing);
}

static char	*remove_newline(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}

static int	check_line_if_substance_exist(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (FALSE);
	else
		return (TRUE);
}

static void	check_data_count(t_count count, t_parsing *parsing)
{
	if (count.ambient == 0 || count.camera == 0 || count.light == 0)
		ft_parsing_error(DATA_ERROR, 0, parsing);
}
