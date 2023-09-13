/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmlx_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang <jhwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:36:44 by jhwang            #+#    #+#             */
/*   Updated: 2023/09/13 18:36:46 by jhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMLX_BONUS_H
# define FTMLX_BONUS_H
# include "parsing_bonus.h"

typedef struct s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*texture_ptr;
	void	*normal_ptr;
}t_ptr;

typedef struct s_image
{
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}t_img;

typedef struct s_tex
{
	t_img	info;
	int		width;
	int		height;
}t_tex;

typedef struct s_mlx
{
	t_ptr	ptr;
	t_img	img;
	t_tex	texture;
	t_tex	normal;
}t_mlx;

typedef struct s_rt
{
	t_mlx	*mlx;
	t_data	*data;
}t_rt;
#endif
