#include "parsing.h"

void	add_number(int number)
{
	number++;
	exit(0);
}

void	increase_number(int number)
{
	number++;
	add_number(number);
}

void	check_number(void)
{
	int	number;

	number = 0;
	increase_number(number);
}

void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	char	*string;

	string = (char *) malloc(sizeof(char) * 1000);
	atexit(leaks);
	check_number();
	return (0);
}
