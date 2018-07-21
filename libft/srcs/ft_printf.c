/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:08:50 by nwang             #+#    #+#             */
/*   Updated: 2018/02/21 20:01:40 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		char_count(const char *f, int i)
{
	int	j;

	j = 0;
	while (f[i] && !(check_spec(f[i])) && f[i] != '%')
	{
		i++;
		j++;
	}
	return (j + 1);
}

int		percent(int i, int *fl, size_t *z)
{
	ft_putchar('%');
	*z += 1;
	*fl = 1;
	return (i + 2);
}

int		man_flag(const char *f, int i, t_flag *pf)
{
	int a;
	int b;

	a = 1;
	which_flag(f, i + 1, 0, pf);
	b = valid_char(f, i + 1, pf);
	which_mods(f, i + 1, pf);
	a = char_count(f, i + 1);
	if (b == 0)
	{
		return (-1);
	}
	return (a + i);
}

int		checkstr(const char *s, size_t ret, t_flag *pf, va_list ap)
{
	int				fl;
	static size_t	i;

	fl = 0;
	ft_bzero(pf, sizeof(t_flag));
	while (s[i] && s[i] != '%' && i < ft_strlen(s))
	{
		ft_putchar(s[i++]);
		ret++;
	}
	if (s[i] && s[i] == '%' && s[i + 1] != '%' && (fl = 1))
	{
		if ((i = man_flag(s, i, pf) + 1) == 0)
			return (0);
	}
	else if (s[i] && s[i] == '%' && s[i + 1] == '%')
		i = percent(i, &fl, &ret);
	if (fl == 1)
	{
		ret += output(ap, pf);
		ret = checkstr(s, ret, pf, ap);
	}
	i = 0;
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	size_t		j;
	t_flag		pf;

	j = 0;
	va_start(ap, format);
	count = checkstr(format, j, &pf, ap);
	va_end(ap);
	return (count);
}
