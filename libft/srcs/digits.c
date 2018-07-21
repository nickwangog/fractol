/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:01:11 by nwang             #+#    #+#             */
/*   Updated: 2018/02/21 15:01:43 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	digit_spec(va_list ap, t_flag *pf)
{
	if (pf->mod == 1)
		return ((short)va_arg(ap, int));
	if (pf->mod == 2)
		return (va_arg(ap, long int));
	if (pf->mod == 3)
		return (va_arg(ap, intmax_t));
	if (pf->mod == 4)
		return (va_arg(ap, ssize_t));
	if (pf->mod == 5)
		return ((signed char)va_arg(ap, int));
	if (pf->mod == 6)
		return (va_arg(ap, long long));
	else
		return (va_arg(ap, int));
}

int			d_len(intmax_t i)
{
	int len;

	len = 1;
	if (i == -9223372036854775807 - 1)
		return (19);
	if (i == 0)
		return (i);
	if (i < 0)
	{
		i *= -1;
		len++;
	}
	while (i /= 10)
		len += 1;
	return (len);
}

int			lenplus(int len)
{
	len++;
	ft_putchar(' ');
	return (len);
}

int			digits_cont(long long i, t_flag *pf, int len)
{
	if (pf->dot == 1 && pf->minus == 0 && pf->prec > pf->mwidth
			&& pf->zero && pf->sp == 0)
		return (zppad(i, 0, 0, pf));
	if (pf->minus == 0 && pf->prec > d_len(len) && pf->sp)
		lenplus(len);
	if (pf->minus == 0 && pf->prec > d_len(len))
		len = pad(pf->mwidth - pf->prec, *pf);
	if (pf->minus == 1 && pf->neg == 1)
		i = i * -1;
	if (pf->neg == 0 && pf->pos == 0 && pf->sp == 1 && pf->dot == 0)
		lenplus(len);
	len += d_len(i);
	if (i == 0 && pf->dot == 1)
		return (len - 1);
	if (pf->pos == 1 && pf->minus == 1)
		ft_putchar('+');
	ft_putnbrmax(i);
	if (pf->minus == 1 && pf->dot == 0)
		len = len + pad(pf->mwidth - len, *pf);
	return (len);
}

int			digits(va_list ap, t_flag *pf, int len)
{
	long long	i;

	if (pf->cha == 'D')
		pf->mod = 2;
	i = digit_spec(ap, pf);
	pf->ilen = d_len(i);
	if (i < 0)
	{
		i *= -1;
		pf->neg = 1;
	}
	if (pf->minus == 0 && pf->sp == 1 && pf->mwidth > 0 && pf->prec == 0)
		pf->mwidth--;
	if (pf->dot == 1 && pf->minus == 1)
		return (minpad(i, 0, 0, pf));
	if (pf->dot == 1 && pf->mwidth > pf->prec)
		return (zppad(i, 0, 0, pf));
	if (pf->dot == 1 && pf->pos == 1 && pf->neg == 0)
		pf->mwidth--;
	if (pf->dot == 0 && pf->minus == 0 && pf->prec <= d_len(len))
		len = pad(pf->mwidth - (d_len(i)), *pf);
	return (digits_cont(i, pf, len));
}
