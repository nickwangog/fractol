/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:14:58 by nwang             #+#    #+#             */
/*   Updated: 2018/02/21 18:57:20 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		char_out(va_list ap, t_flag *pf)
{
	int		i;
	char	c;

	i = 0;
	if (pf->cha != '%')
		c = va_arg(ap, int);
	if (pf->cha == '%')
		c = '%';
	if (pf->mwidth > 0 && pf->minus == 0)
		i = pad(pf->mwidth - 1, *pf);
	ft_putchar(c);
	if (pf->mwidth > 0 && pf->minus == 1)
		i = pad(pf->mwidth - 1, *pf);
	i++;
	return (i);
}

int		str_out(va_list ap, t_flag *pf, int j)
{
	int		i;
	char	*s;

	i = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (pf->mwidth > 0 && pf->minus == 0)
		i = pad(pf->mwidth - ft_strlen(s), *pf);
	if (pf->dot == 1)
		while (s[j] && j < pf->prec)
			ft_putchar(s[j++]);
	else
		ft_putstr(s);
	if (pf->mwidth > 0 && pf->minus == 1)
		i = pad(pf->mwidth - ft_strlen(s), *pf);
	return (i + ft_strlen(s));
}

int		pspad(int z, char *s, int i, t_flag *pf)
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

int		precstr(va_list ap, t_flag *pf)
{
	int		i;
	int		z;
	char	*s;

	i = 0;
	s = va_arg(ap, char *);
	if ((int)ft_strlen(s) > pf->prec)
		(z = pf->prec);
	else
		(z = ft_strlen(s));
	if (pf->mwidth > pf->prec)
	{
		i += pspad(pf->mwidth - z, s, 0, pf);
		return (i);
	}
	while (s[i] && i < pf->prec)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int		letters(va_list ap, t_flag *pf)
{
	int		i;

	i = 0;
	if (pf->cha == 'c' || pf->cha == 'C' || pf->cha == '%')
		i = char_out(ap, pf);
	if (pf->dot == 0)
	{
		if (pf->cha == 's' && pf->mod != 2)
			i = str_out(ap, pf, 0);
		if (pf->cha == 's' && pf->mod == 2)
			i = wstr(ap, -1, 0, pf);
	}
	if (pf->dot == 1)
	{
		if (pf->cha == 's' && pf->mod != 2)
			i = precstr(ap, pf);
		if (pf->cha == 'S' && pf->mod == 2)
			i = pwstring(ap, 0, 0, pf);
	}
	return (i);
}
