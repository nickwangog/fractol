/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:57:52 by nwang             #+#    #+#             */
/*   Updated: 2018/02/21 15:10:24 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			iplus(int i)
{
	ft_putchar('-');
	i++;
	return (i);
}

int			minpad(uintmax_t z, int i, int x, t_flag *pf)
{
	x = pf->prec - d_len(z);
	if (pf->pos == 1)
	{
		ft_putchar('+');
		i++;
	}
	if (pf->neg == 1)
		iplus(i);
	if (d_len(z) < pf->prec)
		while (x > 0)
		{
			ft_putchar('0');
			i++;
			x--;
		}
	ft_putnbr(z);
	i += d_len(z);
	while (pf->mwidth > i)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int			zppad2(uintmax_t z, int i, t_flag *pf)
{
	if (pf->neg == 1)
		iplus(i);
	while (pf->prec > d_len(z))
	{
		ft_putchar('0');
		pf->prec--;
	}
	i += d_len(z);
	if (pf->prec == 0 && z == 0)
	{
		ft_putchar(' ');
		i--;
	}
	else
		ft_putnbr(z);
	return (i + 1);
}

int			zppad(uintmax_t z, int i, int x, t_flag *pf)
{
	if (pf->prec > d_len(z))
		x = (pf->mwidth - pf->prec);
	else
		x = (pf->mwidth - d_len(z));
	if (pf->pos == 1 || pf->neg == 1)
		x--;
	while (x > 0)
	{
		ft_putchar(' ');
		i++;
		x--;
	}
	if (pf->pos == 1)
	{
		ft_putchar('+');
		i++;
	}
	return (zppad2(z, i, pf));
}
