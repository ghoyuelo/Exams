#include <stdlib.h>
#include <unistd.h>
/* First (auxiliar) function for check the final of line required (\n or \0).
This function returns a boolean as a true/false check */
int ft_charcheck(char *str)
{
  int i;
  i = 0;
  if (!str)
    return(0);
  while(str[i])
  {
    if(str[i] == '\n' || str[i] == '\0')
      return (1);
    i++;
  }
  return (0);
}
/* This second function is for join last buffered chars whit all.
We will use this function in the main loop for get the last line
when ft_charcheck returns true */
char *ft_joiner(char *line, char c)
{
	char *str;
	int i;
	
	i = 0;
	while(line[i])
		i++;
	str = (char *)malloc(i + 2);
	if(!str)
		return(NULL);
	i = 0;
	while(line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return(str);
}
char *get_next_line(int fd)
{
	char *line;
	char buffer;
	int fbytes;
	
	if (fd < 0 || BUFFER_SIZE <= 0)//First checking condition for received fd and BUFFER_SIZE
		return (NULL);
	line = malloc(1);//the first malloc is done here for this variable does exist. The rest will be allocated while is joined.
	if (!line)
		return (NULL);
	line[0] = '\0';
	fbytes = 1; //Start var with any value > 0 for introduce into the next loop.
	while (!(ft_charcheck(line)) && fbytes != 0)
	{
		fbytes = read(fd, &buffer, 1);
    /*the one and only read function must be into the loop and BUFFER_SIZE = 1.
    It is not mandatory to work with any other B_S, so this one simplifies work.*/
		if (fbytes == 0) //Checking that any byte has been readed
		{
			if (line[0] == '\0')// If last buffer returned this, there is no line to return and function ends.
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		if (fbytes < 0) //Whe FD is null, returns -1 then, function could not work with null FD
		{
			free(line);
			return (NULL);
		}
		line = ft_joiner(line, buffer); //Join last line and return it.
	}
	return (line);
}
