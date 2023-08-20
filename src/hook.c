#include <stdlib.h>
#include <stdio.h>
#include "initialize.h"

// red button
int	hook_close(t_mlx *mlx)
{
	if (mlx->ptr.img_ptr != NULL)
		printf("");
	printf("byee\n");
	exit(0);
	//   exit_program();
	return (0);
}

int	hook_keyup(int keycode, t_mlx *mlx)
{
	if (mlx->ptr.img_ptr != NULL)
		printf("");
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		printf("ESC\n");
		exit(0);
	}
	return (0);
}
