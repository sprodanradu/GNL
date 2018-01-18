/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:42:42 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/13 12:39:04 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	k;

	if ((int)ft_strlen(little) == 0)
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (big[k] == little[j])
			{
				k++;
				j++;
				if (!little[j])
					return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}
