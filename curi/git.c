#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"
#define BUFF_SIZE 32

static int		ft_strlenchr(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
		++i;
	return (i);
}

static char		*ft_strdupchr(const char *s1)
{
	char	*ans;
	int		len;
	int		i;

	len = ft_strlenchr(s1);
	ans = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!len)
		return (ft_strdup(""));
	if (ans)
	{
		while (i < len)
		{
			ans[i] = s1[i];
			i++;
		}
		ans[i] = '\0';
	}
	return (ans);
}

int				get_next_line(int const fd, char **line)
{
	static char	*buffer[256];
	int			ret;
	char		*l_buffer;

	if (!buffer[fd % 256])
		buffer[fd % 256] = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	l_buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	while (!ft_strchr(buffer[fd % 256], '\n') && ret > 0)
	{
		ret = read(fd, l_buffer, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		l_buffer[ret] = '\0';
		buffer[fd % 256] = ft_strjoin(buffer[fd % 256], l_buffer);
	}
	*line = ft_strdupchr(buffer[fd % 256]);
	if (ret)
		buffer[fd % 256] = ft_strdup(&ft_strchr(buffer[fd % 256], '\n')[1]);
	else
		buffer[fd % 256] = ft_strdup("");
	free(l_buffer);
	return (*line[0] || buffer[fd % 256][0] || ret ? 1 : 0);
}
int	main(int argc, char **argv)
{
	int		fd[argc];
	char	*line[argc];
	int		i;

	i = 1;
	while (i < argc)
	{
		fd[i] = open(argv[i], 0);
		++i;
	}
	i = 1;
	while (i < argc)
	{
		while (get_next_line(fd[i], &line[i]))
			ft_putendl(line[i]);
		++i;
	}
	i = 1;
	while (i < argc)
	{
		close(fd[i]);
		++i;
	}
	
	return (0);
}