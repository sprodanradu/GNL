/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:42:11 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/12 19:42:15 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	int		len;

	len = ft_strlen(s);
	d = (char)c;
	while (len >= 0)
	{
		if (s[len] == d)
			return ((char*)(s + len));
		len--;
	}
	return (NULL);
}
