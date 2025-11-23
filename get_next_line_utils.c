#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

char    *ft_strjoin(char *s1, char *s2)
{
    int     len1 = ft_strlen(s1);
    int     len2 = ft_strlen(s2);
    char    *tmp = malloc(len1 + len2 + 1);
    int     i = 0, j = 0;

    if (!tmp)
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

char *join_and_free(char *dest, char *src)
{
	char *new = ft_strjoin(dest, src);
	free(src);
	return (new);
}
