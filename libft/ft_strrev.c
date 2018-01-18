/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:56:29 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/19 21:02:51 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	char	temp;
	int		start;

	start = 0;
	len = ft_strlen(str) - 1;
	while (start < len)
	{
		temp = str[start];
		str[start++] = str[len];
		str[len--] = temp;
	}
	return (str);
}
