#include "datasheet_bonus.h"

int	double_equal(double x, double y)
{
	if (fabs(x - y) <= EPSILON)
		return (TRUE);
	return (FALSE);
}
