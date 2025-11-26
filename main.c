#include "get_next_line.h"

int main(void)
{
	int fd;
	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (1);
	char *str;
	while((str = get_next_line(fd))) {
		printf("%s", str);
		free(str);
	}
	str = get_next_line(fd);
	printf("%s", str);
	// printf("%s\n", str);
	// printf("%s\n", str);
	system("leaks a.out");
	close(fd);
}