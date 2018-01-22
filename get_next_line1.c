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
	static char	*bufv[13000];
	int			buff;
	char		*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!bufv[fd])
		bufv[fd] = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(BUFF_SIZE);
	buff = 1;
	while (!(ft_strchr(bufv[fd], '\n')) && buff > 0)
	{
		if ((buff = read(fd, tmp, BUFF_SIZE + 1)) < 0)
			return (-1);
		tmp[buff] = '\0';
		bufv[fd] = ft_strjoin(bufv[fd], tmp);
	}
	if (!(*line = ft_strnlchar(bufv[fd])))
		return (-1);
	if (buff)
		bufv[fd] = ft_strchr(bufv[fd], '\n') + 1;
	else
		bufv[fd] = "";
	free(tmp);
	return (*line[0] || bufv[fd][0] || buff ? 1 : 0);
}
