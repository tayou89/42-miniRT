#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "ftmlx.h"
#include "initialize.h"
#include "datasheet.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	data;

	init_all(&mlx);
	mlx_hook(mlx.ptr.win_ptr, ON_KEYUP, 0, hook_keyup, &mlx);
	mlx_hook(mlx.ptr.win_ptr, ON_DESTROY, 0, hook_close, &mlx);
	parse_data(argc, argv, &data);
	get_viewport_data(&data);
	put_image(&mlx);
	mlx_loop(mlx.ptr.mlx_ptr);
}
