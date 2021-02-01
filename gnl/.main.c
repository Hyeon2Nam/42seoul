#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *line;

	get_next_line(0, &line);
	printf("%s\n", line);
	getchar();

	return (0);
}