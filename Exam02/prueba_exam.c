#include <unistd.h>
#include <stdlib.h>

int	ft_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] =='\n' || s[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join(int line, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	s = (char *)malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (line[i])
	{
		s[i] = line [i];
		i++,
	}
	s[i] = c;
	s[i + 1] = '\0';
	free(line);
	return (s);
}

char	*get_next_line(int	fd)
{
	char	*line;
	char	buffer;
	int		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = malloc(1);
	if(!line)
		return (NULL);
	line[0] = '\0';
	bytes = 1;
	while (!ft_check(line) && bytes != 0)
	{
		bytes = read(fd, &buffer, 1);
		if (bytes == 0)
		{
			if (line == '\0')
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		if (bytes < 0)
		{
			free (line);
			return (NULL);
		}
		line = ft_join(line, buffer);
	}
	return (line);
}
