/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:49:06 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/20 18:47:18 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			ft_tochar(int n)
{
	char c;

	c = 48 + n;
	return (c);
}

static void			ft_ifnzero(char **str)
{
	char *str2;

	str2 = *str;
	str2 = (char*)malloc(sizeof(char) * 2);
	str2[0] = '0';
	str2[1] = '\0';
	*str = str2;
}

static char			*ft_memaloc(char *str, int i, int len, int n)
{
	long long nb;

	if (n < 0)
	{
		str = (char*)malloc(sizeof(char) * (i + 2));
		if (!str)
			return (NULL);
		len = i + 2;
		str[0] = '-';
	}
	else
	{
		str = (char*)malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		len = (i + 1);
	}
	nb = ft_modulus((long long)n);
	str[--len] = '\0';
	while (nb > 0)
	{
		str[--len] = ft_tochar(nb % 10);
		nb = nb / 10;
	}
	return (str);
}

char				*ft_itoa(int n)
{
	int			i;
	long long	nb;
	char		*str;
	int			len;

	if (n == 0)
	{
		ft_ifnzero(&str);
		return (str);
	}
	nb = ft_modulus((long long)n);
	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	len = 0;
	str = NULL;
	str = ft_memaloc(str, i, len, n);
	return (str);
}
