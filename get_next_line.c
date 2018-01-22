/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:33:49 by sprodan-          #+#    #+#             */
/*   Updated: 2018/01/19 20:50:15 by sprodan-         ###   ########.fr       */
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
	i = 0;
	while (i < ft_strnllen(s))
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int			ft_readbufv(int fd, char **b, int *buff, char **tmp)
{
	char *tmp2;
	char *bufv2;

	tmp2 = *tmp;
	bufv2 = *b;
	while (!(ft_strchr(bufv2, '\n')) && *buff > 0)
	{
		if ((*buff = read(fd, tmp2, BUFF_SIZE)) < 0)
			return (-1);
		tmp2[*buff] = '\0';
		bufv2 = ft_strjoin(bufv2, tmp2);
	}
	*b = bufv2;
	*tmp = tmp2;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*bufv[13000];
	int			buff;
	char		*tmp;
	char		*b;

	tmp = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line)
		return (-1);
	if (!bufv[fd])
		bufv[fd] = ft_strnew(BUFF_SIZE);
	buff = 1;
	b = bufv[fd];
	if (ft_readbufv(fd, &b, &buff, &tmp) == -1)
		return (-1);
	bufv[fd] = b;
	if (!(*line = ft_strnlchar(bufv[fd])))
		return (-1);
	if (buff)
		bufv[fd] = ft_strchr(bufv[fd], '\n') + 1;
	else
		bufv[fd] = "";
	free(tmp);
	if (*line[0] || bufv[fd][0] || buff)
		return (1);
	return (0);
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
