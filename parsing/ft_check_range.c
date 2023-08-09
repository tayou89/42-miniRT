#include "parsing.h"

int	check_rgb_range(int	data)
{
	if (data >= 0 && data <= 255)
		return (TRUE);
	else
		return (FALSE);
}

int	check_fov_range(int	data)
{
	if (data > 0 && data < 180)
		return (TRUE);
	else
		return (FALSE);
}

int	check_ratio_range(double data)
{
	if (data >= 0 && data <= 1)
		return (TRUE);
	else
		return (FALSE);
}

int	check_vector_range(double data)
{
	if (data >= -1 && data <= 1)
		return (TRUE);
	else
		return (FALSE);
}
