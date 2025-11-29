/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:55:52 by doabrour          #+#    #+#             */
/*   Updated: 2025/11/29 12:46:34 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_buffer(char *buffer)
{
	int		index;
	int		index2;
	char	*new_buffer;

	index = 0;
	index2 = 0;
	if (!buffer)
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (!buffer[index])
		return (free(buffer), NULL);
	index++;
	if (!buffer[index])
		return (free(buffer), NULL);
	new_buffer = malloc(ft_strlen(&buffer[index]) + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	while (buffer[index])
		new_buffer[index2++] = buffer[index++];
	new_buffer[index2] = '\0';
	free(buffer);
	return (new_buffer);
}

int	get_next_line_length(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == '\n')
		index++;
	return (index);
}

char	*line(char *buffer)
{
	char		*line;
	int			len;
	int			i;

	len = 0;
	if (!buffer[len] || !buffer[0])
		return (NULL);
	len = get_next_line_length(buffer);
	line = (char *)malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[len] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[len] = '\0';
	return (line);
}

char	*read_25_line(int fd, char *buffer)
{
	char	*new_buffer;
	int		bytes;
	char	*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (free(buffer), NULL);
	while (1337)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		tmp[bytes] = '\0';
		new_buffer = ft_strjoin(buffer, tmp);
		free(buffer);
		if (!new_buffer)
			return (free(tmp), tmp = NULL, NULL);
		buffer = new_buffer;
		if (found(buffer) == 0)
			break ;
	}
	free(tmp);
	if (bytes < 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*result;

	if (fd < 0 || fd >= OPEN_MAX || 
		BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(1);
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	buffer[fd] = read_25_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (buffer[fd][0] == '\0')
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	result = line(buffer[fd]);
	if (!result)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = update_buffer(buffer[fd]);
	return (result);
}

// #include <stdio.h>
// #include "get_next_line_bonus.h"
// #include "get_next_line.h"
// # include <fcntl.h>
// int main(void)
// {
// 	int fd = open("test.txt", O_RDWR);
// 	int fd2 = open("test2.txt", O_RDWR);
// 	int fd3 = open("test3.txt", O_RDWR);
// 	char *str;
// 	char *str2;
// 	char *str3;
// 	while (1) {
// 		str = get_next_line(fd);
// 		str2 = get_next_line(fd2);
// 		str3 = get_next_line(fd3);
// 		printf("\nstr:%sstr2:%sstr3:%s\n", str, str2, str3);
// 		if (!str && !str2 && !str3)
// 			break;
// 		printf("------------------------------\n");
// 		free(str);
// 		free(str2);
// 		free(str3);
// 	}

// }

//----------TEST1-------------
// can you read me?
// can you also read this line?
// alsooooo this one😉.

// haha what about me 😚
//----------TEST2-------------
// hahah
// also read this one🧐!

// and heeeeeeere

// yeeees
//----------TEST3-------------
// what about meeee!
// and also this line😆!
// what about this line too😏