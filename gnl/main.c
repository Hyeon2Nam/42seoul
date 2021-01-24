#include "../libft/libft.h"
#include <fcntl.h>
int		get_next_line(int fd, char **line);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	fd;
	char *line;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
        ft_putstr(line);
        ft_putchar('\n');
        free(line);
        line = NULL;
	}
	if (argc == 2)
		close(fd);
}
