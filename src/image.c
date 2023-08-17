#include "initialize.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < WIN_WIDTH) && (0 <= y && y < WIN_HEIGHT))
	{
		dst = mlx->img.addr + (y * mlx->img.size_line \
							+ x * (mlx->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_image(t_mlx *mlx)
{
	int	i;
	int	k;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		k = -1;
		while (++k < WIN_WIDTH)
			put_pixel(mlx, k, i, 0x00000000);
	}
	mlx_put_image_to_window(
		mlx->ptr.mlx_ptr,
		mlx->ptr.win_ptr,
		mlx->ptr.img_ptr,
		0,
		0);
}
