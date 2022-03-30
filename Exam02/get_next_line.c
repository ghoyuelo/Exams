#include <stdlib.h>
#include <unsitd.h>

int ft_charcheck(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char *ft_joiner(char *line, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i])
		i++;
	str = (char *)malloc (i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

char *get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	bytes = 1;
	while(!(ft_charcheck(line)) && bytes != 0)
	{
		bytes = read(fd, &buffer, 1);
		if (bytes == 0)
		{
			if (line[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		line = ft_joiner(line, buffer);
	}
	return (line);
}
