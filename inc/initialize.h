#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "ftmlx.h"
# include "mlx.h"
# include <stdio.h>

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define WIN_TITLE	"miniRT"

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_DESTROY		17
# define KEY_ESC 		53

void	put_pixel(t_mlx *mlx, int x, int y, int color);
void	put_image(t_mlx *mlx);
int		hook_close(t_mlx *mlx);
void	*init_all(t_mlx *mlx);
int		hook_keyup(int keycode, t_mlx *mlx);
#endif
