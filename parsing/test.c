#include "parsing.h"

t_data	get_parsing_data(void)
{
	t_parsing	parsing;

	parsing.data.sphere = (t_sphere *) malloc(sizeof(t_sphere));
	parsing.data.sphere->radius = 20;
	parsing.data.sphere->next = (t_sphere *) malloc(sizeof(t_sphere));
	parsing.data.sphere->next->radius = 30;
	parsing.data.sphere->next->next = (void *) 0;
	return (parsing.data);
}

int	main(void)
{
	t_data	data;

	data = get_parsing_data();
	if (data.sphere == (void *) 0)
		printf("data.sphere is NULL.\n");
	if (data.sphere->next == (void *) 0)
		printf("data.sphere->next is NULL.\n");
	printf("data.sphere->raidus: %.f\n", data.sphere->radius);
	printf("data.sphere->next->raidus: %.f\n", data.sphere->next->radius);
	return (0);
}
