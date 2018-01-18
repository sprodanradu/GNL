#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#define BUFF_SIZE 32

static int 	ft_strnllen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_strnlchar(char *s)
{
	char	*s2;
	int		i;

	if (!(s2 = ft_strnew(ft_strnllen(s))))
		return (NULL);
	i = 0;
	while (i < ft_strnllen(s))
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int		get_next_line(const int fd, char **line)
{
	static char	*bufv[1000];
	int			buff;
	char		*tmp;
	char		*p;

	if (fd < 0 || !(tmp = ft_strnew(BUFF_SIZE)) || !line || (buff = read(fd, tmp, 0)) < 0)
		return (-1);
	if (!bufv[fd])
		{
			if (!(bufv[fd] = ft_strnew(BUFF_SIZE)))
				return (-1);
		}
	buff = 1;
	while (!(ft_strchr(bufv[fd],'\n')) &&  buff > 0)
	{
		if ((buff = read(fd, tmp, BUFF_SIZE + 1)) < 0)
			return (-1);
		tmp[buff] = '\0';
		bufv[fd] = ft_strjoin(bufv[fd], tmp);
	}
	if(!(*line = ft_strnlchar(bufv[fd])))
		return (-1);
	if (buff)
	{
		p = ft_strchr(bufv[fd], '\n');
		bufv[fd] = p + 1;
	}
	else
		bufv[fd] = "";
	free(tmp);
	
}

int main(int argc, char **argv)
{
	int		fd;
	char	*line[argc];
	int		i;


	fd = open(argv[1], 0);
	
	while (get_next_line(fd, &line[0]))
		ft_putendl(line[0]);
	
	
	return (0);
}