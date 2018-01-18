/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:29:15 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/20 17:47:16 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putint(long long b)
{
	if (b != 0)
	{
		if (b < 0)
		{
			b = -b;
			ft_putchar('-');
		}
		ft_putint(b / 10);
		ft_putchar('0' + b % 10);
	}
}

void		ft_putnbr(int n)
{
	if (n == 0)
	{
		ft_putchar('0');
	}
	ft_putint(n);
}
