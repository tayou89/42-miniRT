#include <stdlib.h>
#include "initialize.h"
#include "datasheet.h"
#include "parsing.h"
#include "viewport.h"
#include "image.h"

int	main(int argc, char **argv)
{
	t_rt	scene;
	t_mlx	mlx;
	t_data	data;

	scene.mlx = &mlx;
	scene.data = &data;
	parse_data(argc, argv, &data);
	if (init_all(&mlx) == NULL)
	{
		printf("Error\n");
		exit_program(&scene);
	}
	mlx_hook(mlx.ptr.win_ptr, ON_KEYUP, 0, hook_keyup, &scene);
	mlx_hook(mlx.ptr.win_ptr, ON_DESTROY, 0, hook_close, &scene);
	get_viewport_data(&data.viewport, data.camera);
	draw_image_by_ray_tracing(&mlx, &data);
	mlx_put_image_to_window(mlx.ptr.mlx_ptr, \
							mlx.ptr.win_ptr, mlx.ptr.img_ptr, 0, 0);
	mlx_loop(mlx.ptr.mlx_ptr);
	return (0);
}
