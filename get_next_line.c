/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:34:54 by doabrour          #+#    #+#             */
/*   Updated: 2025/11/25 14:53:58 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *update_buffer(char *buffer)
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
	if(!buffer[index])
		return (free(buffer),NULL);
	index++;
	if(!buffer[index])
		return (free(buffer),NULL);
	new_buffer = malloc(ft_strlen(&buffer[index]) + 1);
	if (!new_buffer)
		return (free(new_buffer),NULL);
	while (buffer[index])
		new_buffer[index2++] = buffer[index++];
	new_buffer[index2] = '\0';
	free(buffer);
	return (new_buffer);
}

static char *line(char *buffer)
{
	char		*line;
	int			index;
	int			i;
	
	index = 0;
	if (!buffer[index] || !buffer[0])
		return (free(buffer), NULL);

	while(buffer[index] && buffer[index] != '\n')
	{
		index++;
	}
	line = malloc(index + 1 + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while(i < index)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[index] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*result;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	tmp =  malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	// printf("mazal ma seg foultit 🧐...\n");
	while((bytes = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (found(buffer) == 0)
			break;
	}
	free(tmp);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	result = line(buffer);
	buffer = update_buffer(buffer);
	return (result);
}
