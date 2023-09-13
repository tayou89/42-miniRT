/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:41:41 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 19:41:42 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_backup(char *backup)
{
	if (backup != NULL)
		free(backup);
	return (NULL);
}
