/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doabrour <doabrour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:34:18 by doabrour          #+#    #+#             */
/*   Updated: 2025/11/25 12:42:50 by doabrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

char    *ft_strjoin(char *s1, char *s2)
{
    int     len1;
    int     len2;
    char    *tmp;
    int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	j = 0;
	i = 0;
	tmp = malloc(len1 + len2 + 1);
    if (tmp == NULL)
        return (NULL);
    while (s1[i])
    {
        tmp[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        tmp[i + j] = s2[j];
        j++;
    }
    tmp[i + j] = '\0';
    return tmp;
}

int	found(char *str)
{
	int index;

	index = 0;
	while(str[index])
	{
		if (str[index] == '\n')
			return (0);
		index++;
	}
	return (1);
}
