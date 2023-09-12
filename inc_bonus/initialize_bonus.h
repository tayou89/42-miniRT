#ifndef INITIALIZE_BONUS_H
# define INITIALIZE_BONUS_H

# include "ftmlx_bonus.h"
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

void	*init_all(t_mlx *mlx);
int		hook_close(t_rt *scene);
int		hook_keyup(int keycode, t_rt *scene);
void	exit_program(t_rt *scene);
#endif
