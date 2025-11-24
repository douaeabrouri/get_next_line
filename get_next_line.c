/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:34:54 by doabrour          #+#    #+#             */
/*   Updated: 2025/11/24 18:57:33 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		token;
	static char	*buffer;
	char		*buffer_val;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return NULL;
	printf("mazal ma segfaultit 🤲\n");
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	while(read(fd, tmp, BUFFER_SIZE) > 0)
	{
		tmp[BUFFER_SIZE] = '\0';
		if (found(tmp) == 0)
		{
			buffer = ft_strjoin(buffer, tmp);
			break;
		}
		buffer = ft_strjoin(buffer, tmp);
	}
	int index = 0;
	char *line = malloc(100);
	while(buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	line[index] = '\0';
	buffer_val = dont_forget_me(buffer);
	free(buffer);
	buffer = buffer_val;
	return (line);
}
