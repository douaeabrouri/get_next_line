#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_strjoin(void *dst, const void *src, size_t n);
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
	char *tmp;
	buffer = malloc(sizeof(char) * 1024);
	int count = 0;
	while(read(fd, &token, 1) > 0)
	{
		if (count < BUFFER_SIZE)
		{
			tmp[count] = token;
			count++;
		}
		if (found(tmp) == 0)
		{
			buffer = join_and_free(buffer, tmp, BUFFER_SIZE);
			free(tmp);
			break;
		}
		buffer = join_and_free(buffer, tmp, BUFFER_SIZE);
	}
	buffer[count] = '\0';
	int index = 0;
	while(index < count)
	{
		write(1, &buffer[index], 1);
		index++;
	}
	close(fd);
	return (0);
}