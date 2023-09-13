/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:54 by tayou             #+#    #+#             */
/*   Updated: 2023/09/13 18:28:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_line(t_parsing *parsing)
{
	classify_element_information(parsing->file.line, parsing);
	get_element_data(&parsing->info, parsing);
}
