#include <stdio.h>

char	*ft_strjoin(char  *s1, char  *s2)
{
	char	*tmp;
	int		len;
	int		index;
	int		index2;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		tmp[index] = s1[index];
		index++;
	}
	index2 = 0;
	while (s2[index2])
		tmp[index++] = s2[index2++];
	tmp[index] = '\0';
	return (tmp);
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

char *join_and_free(char *dest, char *src, size_t BUFFER_SIZE)
{
	char *new = ft_strjoin(dest, src, BUFFER_SIZE);
	free(src);
	return (new);
}
