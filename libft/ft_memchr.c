/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:28:16 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/12 13:54:31 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s1;
	unsigned char d;

	s1 = (unsigned char *)s;
	d = (unsigned char)c;
	while (n > 0 && d != *s1)
	{
		s1++;
		n--;
	}
	if (n < 1)
		return (NULL);
	return ((void *)s1);
}
