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

void	*free_data(void *data)
{
	t_sphere	*sphere;
	t_sphere	*head;

	sphere = (t_sphere *) data;
	while (sphere != (void *) 0)
	{
		head = sphere;
		sphere = sphere->next;
		free(head);
		head = (void *) 0;
	}
	return ((void *) 0);
}

void	leaks(void)
{
	system("leaks a.out");
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
	data.sphere = free_data((void *) data.sphere);
	if (data.sphere == (void *) 0)
		printf("data.sphere is NULL.\n");
	else
		printf("data.sphere is not NULL.\n");
 	atexit(leaks);
	return (0);
}
