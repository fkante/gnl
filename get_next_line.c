#include "libft.h"
#include <stdio.h> 

#define BUF_SIZE_1 1

int	ft_size_of_file(const char *file)
{
	int	fd;
	int	size_file;
	char	buf[BUF_SIZE_1 + 1];

	size_file = 0;
	fd = open(file, O_RDWR);
	while (read(fd, buf, BUF_SIZE_1))
		size_file++;
	printf("size of the file = %d\n", size_file);
	return (0);

}

int	get_next_line(const int fd, char **line)
{
	return (0);
}
