#include "get_next_line.h"

int main(void)
{
	int fd;
	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (1);
	char *str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);
	str = get_next_line(fd);
	printf("%s\n", str);
	// printf("%s\n", str);

	close(fd);
}