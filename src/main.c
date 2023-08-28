#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "ftmlx.h"
#include "initialize.h"
#include "datasheet.h"
#include "parsing.h"
#include "viewport.h"
#include "ray_tracing.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_world	data;

	parse_data(argc, argv, &data);
	init_all(&mlx);
	mlx_hook(mlx.ptr.win_ptr, ON_KEYUP, 0, hook_keyup, &mlx);
	mlx_hook(mlx.ptr.win_ptr, ON_DESTROY, 0, hook_close, &mlx);
//	put_image(&mlx);
	get_viewport_data(&data.viewport, data.camera);
	draw_image_by_ray_tracing(&data);
	mlx_loop(mlx.ptr.mlx_ptr);
}
