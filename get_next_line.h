/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:32:48 by doabrour          #+#    #+#             */
/*   Updated: 2025/11/24 17:27:35 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
#  endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			found(char *str);
static		char *buffer;
char		*join_and_free(char *dest, char *src);
char		*dont_forget_me(char *buffer);

#endif