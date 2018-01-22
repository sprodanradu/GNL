/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:33:49 by sprodan-          #+#    #+#             */
/*   Updated: 2018/01/18 20:40:00 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strnllen(char *s)
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
	if (!ft_strnllen(s))
		return (ft_strdup(""));
	i = 0;
	while (i < ft_strnllen(s))
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int			get_next_line(const int fd, char **line)
{
	static char	*bufv[256];
	int			buff;
	char		*tmp;

	if (!bufv[fd % 256])
		bufv[fd % 256] = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || !line)
		return (-1);
	buff = 1;
	while (!ft_strchr(bufv[fd % 256], '\n') && buff > 0)
	{
		buff = read(fd, tmp, BUFF_SIZE);
		if (buff < 0)
			return (-1);
		tmp[ret] = '\0';
		bufv[fd % 256] = ft_strjoin(bufv[fd % 256], tmp);
	}
	*line = ft_strnlchr(bufv[fd % 256]);
	if (buff)
		bufv[fd % 256] = ft_strdup(&ft_strchr(bufv[fd % 256], '\n')[1]);
	else
		bufv[fd % 256] = ft_strdup("");
	free(tmp);
	return (*line[0] || bufv[fd % 256][0] || buff ? 1 : 0);
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