/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:30:07 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/20 17:44:57 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putint_fd(long long b, int fd)
{
	if (b != 0)
	{
		if (b < 0)
		{
			b = -b;
			ft_putchar_fd('-', fd);
		}
		ft_putint_fd(b / 10, fd);
		ft_putchar_fd('0' + b % 10, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
	}
	ft_putint_fd(n, fd);
}
