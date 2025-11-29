/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:34:54 by doabrour          #+#    #+#             */
/*   Updated: 2025/11/29 12:51:11 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buffer;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 
		|| BUFFER_SIZE >= 2147483647)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = read_25_line(fd, buffer);
	if (!buffer)
		return (NULL);
	if (buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	result = line(buffer);
	if (!result)
		return (free(buffer), buffer = NULL, NULL);
	buffer = update_buffer(buffer);
	return (result);
}

//----------TEST1-------------
// can you read me?
// can you also read this line?
// alsooooo this one😉.

// haha what about me 😚