#include "parsing.h"

int	main(void)
{
	t_parsing	data;
	char		*string;

	string = "255,255,255";
	data.info.rgb = ft_split(string, ',');
	if (data.info.rgb == (void *) 0)
		perror("");
	data.info.rgb = 
	return (0);
}
