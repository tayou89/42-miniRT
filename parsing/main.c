#include "parsing.h"

int	main(void)
{
	long long	number;
	double		double_number;
	double		total;

	number = 99999999999;
	double_number = 0.99;
	total = number + double_number;
	printf("total: %.15f\n", total);
	printf("total: %.2f\n", total);
	return (0);
}
