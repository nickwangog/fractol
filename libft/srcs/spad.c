/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 22:21:14 by nwang             #+#    #+#             */
/*   Updated: 2018/02/18 16:22:21 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		wslen(wchar_t *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		wspad(int z, int i, wchar_t *s, t_flag *pf)
{
	int x;

	x = 0;
	if (pf->minus == 1)
		while (s[i] && i < pf->prec)
		{
			ft_putchar(s[i]);
			i++;
		}
	while (x < z)
	{
		ft_putchar(' ');
		x++;
	}
	if (pf->minus == 0)
		while (s[i] && i < pf->prec)
		{
			ft_putchar(s[i]);
			i++;
		}
	return (i + x);
}

int		wstr(va_list ap, int i, int x, t_flag *pf)
{
	wchar_t	*s;

	s = va_arg(ap, wchar_t *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (pf->minus == 0 && pf->mwidth > 0)
		x = pad(pf->mwidth - wslen(s), *pf);
	if (pf->dot == 1)
		while (++i < pf->prec && s[i])
			ft_putchar(s[i]);
	else
		while (s[++i])
			ft_putchar(s[i]);
	if (pf->minus == 1 && pf->mwidth > 0)
		x = pad(pf->mwidth - wslen(s), *pf);
	return (x + wslen(s));
}

int		pwstring(va_list ap, int i, int z, t_flag *pf)
{
	wchar_t *s;

	s = va_arg(ap, wchar_t *);
	if (wslen(s) > pf->prec)
		z = pf->prec;
	else
		z = wslen(s);
	if (pf->mwidth > pf->prec)
	{
		i += wspad(pf->mwidth - z, 0, s, pf);
		return (i);
	}
	while (i < pf->prec && s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
