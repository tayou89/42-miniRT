#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "ftmlx.h"
#include "initialize.h"

int	main(void)
{
	t_mlx	mlx;

	init_all(&mlx);
	mlx_hook(mlx.ptr.win_ptr, ON_KEYUP, 0, hook_keyup, &mlx);
	mlx_hook(mlx.ptr.win_ptr, ON_DESTROY, 0, hook_close, &mlx);
	put_image(&mlx);
	mlx_loop(mlx.ptr.mlx_ptr);
}
