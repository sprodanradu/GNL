/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:04:18 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/12 19:41:11 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;
	int		i;
	int		len;

	len = ft_strlen(s);
	d = (char)c;
	i = 0;
	while (i <= len)
	{
		if (s[i] == d)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}
