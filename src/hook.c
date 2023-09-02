#include <stdlib.h>
#include "initialize.h"

static void	exit_program(t_rt *scene)
{
	free_list(scene->data->obj);
	mlx_destroy_image(scene->mlx->ptr.mlx_ptr, scene->mlx->ptr.img_ptr);
	mlx_destroy_window(scene->mlx->ptr.mlx_ptr, scene->mlx->ptr.win_ptr);
	exit(0);
}

int	hook_close(t_rt *scene)
{
	printf("press red button\n");
	exit_program(scene);
	return (0);
}

int	hook_keyup(int keycode, t_rt *scene)
{
	if (keycode == KEY_ESC)
	{
		printf("press ESC\n");
		exit_program(scene);
	}
	return (0);
}
