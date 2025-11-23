#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


char    *ft_strjoin(char *s1, char *s2);
int		 found(char *str);
static		char *buffer;
char *join_and_free(char *dest, char *src);

int main(void)
{
	// // read the first line!
	// char buffer[256];
	// int fd = open("test.txt", O_RDWR);
	// if (fd == -1)
	// 	return (1);

	// int index = 0;
	// char c;
	// while(read(fd, &c, 1) > 0 && c != '\n' && index < 255)
	// {
	// 	buffer[index] = c;
	// 	index++;
	// }
	// buffer[index] = '\0';

	// write(1, buffer, index);
	// write(1, "\n", 1); 

	// close(fd);
	// return (0);

	// //read the secand line with using BUFFER_SIZE!
	int fd = open("test.txt", O_RDWR);
	if(fd == -1)
		return (1);

	size_t BUFFER_SIZE = 3;
	char token;
	char *tmp = malloc(BUFFER_SIZE + 1);
	char *buffer = malloc(1024);
	buffer[0] = '\0';
	int count = 0;
	while(read(fd, &token, 1) > 0)
	{
		tmp[count] = token;
		count++;
		if (count < BUFFER_SIZE)
		{
			tmp[count] = '\0';
		}
		if (found(tmp) == 0)
		{
			buffer = join_and_free(buffer, tmp);
			break;
		}
		buffer = join_and_free(buffer, tmp);
		count = 0;
	}
	close(fd);
	int index = 0;
	while(buffer[index])
	{
		write(1, &buffer[index], 1);
		index++;
	}
	free(tmp);
	free(buffer);
	return (0);
}