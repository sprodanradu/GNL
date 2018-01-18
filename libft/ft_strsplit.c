/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:50:24 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/19 20:55:11 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_str_find_next(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int			ft_str_count_splits(const char *str, char seps)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str = ft_str_find_next(str, seps, 1);
		if (*str != '\0')
		{
			i++;
			str = ft_str_find_next(str, seps, 0);
		}
	}
	return (i);
}

static char			**ft_tabledel(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(ret[i]);
	free(ret);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**ret;
	int			i;
	const char	*next;

	if (s == NULL)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (ft_str_count_splits(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_str_find_next(s, c, 1);
		if (*s != '\0')
		{
			next = ft_str_find_next(s, c, 0);
			ret[i] = ft_strsub(s, 0, next - s);
			if (ret[i] == NULL)
				return (ft_tabledel(ret, i));
			i++;
			s = next;
		}
	}
	ret[i] = 0;
	return (ret);
}
