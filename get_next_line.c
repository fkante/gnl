#include <stdio.h> 
#include "libft.h"

/*
** includes for linux needed for Open, Read and Write 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE_1 1

int	ft_size_of_file(int fd)
{
	int	size_file;
	char	buf[BUF_SIZE_1 + 1];

	size_file = 0;
	while (read(fd, buf, BUF_SIZE_1))
		size_file++;
	printf("size of the file = %d\n", size_file);
	return (0);

}

int	get_next_line(const int fd, char **line)
{
	return (0);
}

int	main(int ac, char **av)
{
	int fd;
	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDWR);
	ft_size_of_file(fd);
	return (0);
}
