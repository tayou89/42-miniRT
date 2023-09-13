/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:31:53 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:31:55 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	parse_line(t_parsing *parsing)
{
	classify_element_information(parsing->file.line, parsing);
	get_element_data(&parsing->info, parsing);
}
