/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:30:11 by nwang             #+#    #+#             */
/*   Updated: 2018/02/16 16:47:01 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			z_pad(int i, t_flag pf)
{
	int		len;

	len = 0;
	if (pf.neg == 1)
	{
		ft_putchar('-');
		len++;
	}
	if (pf.pos == 1 && pf.neg == 0)
	{
		ft_putchar('+');
		len++;
	}
	if (pf.cha == 'X' && pf.hash == 1)
		ft_putstr("0X");
	if (pf.cha == 'x' && pf.hash == 1)
		ft_putstr("0x");
	while (len < i)
	{
		ft_putchar('0');
		len++;
	}
	return (len);
}

int			p_pad(t_flag pf)
{
	int		i;
	int		len;

	i = 0;
	if (pf.ilen != 0)
	{
		len = pf.ilen;
		if (pf.neg == 1)
			len--;
		while (len < pf.prec)
		{
			ft_putnbr(0);
			i++;
			len++;
		}
	}
	return (i);
}

int			pad(int i, t_flag pf)
{
	int		x;

	x = 0;
	if (pf.zero == 1 && pf.minus == 0)
		return (z_pad(i, pf));
	if (pf.neg == 1 && pf.minus == 0)
		i--;
	while (x < i)
	{
		ft_putchar(' ');
		x++;
	}
	if (pf.neg == 1 && pf.minus == 0)
	{
		ft_putchar('-');
		x++;
	}
	if (pf.neg == 0 && pf.minus == 0 && pf.pos == 1)
	{
		ft_putchar('+');
		x++;
	}
	return (x + p_pad(pf));
}
