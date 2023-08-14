#include "minirt.h"

void	leaks(void)
{
	system("leaks miniRT");
}

int	main(int argc, char **argv)
{
	t_data	data;

//	atexit(leaks);
	data = parse_data(argc, argv);
	print_data(&data);
	return (0);
}
