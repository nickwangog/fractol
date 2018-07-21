/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:02:34 by nwang             #+#    #+#             */
/*   Updated: 2018/02/16 17:34:17 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	udigit_spec(va_list ap, t_flag *pf)
{
	if (pf->mod == 1)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (pf->mod == 2)
		return (va_arg(ap, unsigned long int));
	else if (pf->mod == 3)
		return (va_arg(ap, uintmax_t));
	else if (pf->mod == 4)
		return (va_arg(ap, size_t));
	else if (pf->mod == 5)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (pf->mod == 6)
		return (va_arg(ap, unsigned long long int));
	else
		return (va_arg(ap, unsigned int));
}

char		*strrev(char *s)
{
	int		i;
	int		x;
	char	*ret;

	x = 0;
	i = ft_strlen(s) - 1;
	ret = ft_strnew(i + 1);
	while (i >= 0)
	{
		ret[x] = s[i];
		i--;
		x++;
	}
	ret[x] = '\0';
	free(s);
	return (ret);
}

char		*hexbase(uintmax_t z, int y)
{
	int		i;
	int		x;
	char	*s;

	i = 0;
	x = 0;
	s = (char *)malloc(sizeof(char) * 60);
	if (z == 0)
		s[i++] = x + 48;
	while (z > 0)
	{
		x = z % 16;
		z = z / 16;
		if (x < 10)
			s[i] = x + 48;
		else if (y == 1)
			s[i] = x + 55;
		else if (y == 0)
			s[i] = x + 87;
		i++;
	}
	s[i] = '\0';
	s = strrev(s);
	return (s);
}

int			ptr(uintmax_t i)
{
	uintmax_t	*p;
	char		*s;
	int			len;

	p = &i;
	s = hexbase(*p, 0);
	len = ft_strlen(s);
	len += 2;
	ft_putstr("0x");
	ft_putstr(s);
	free(s);
	return (len);
}

int			udigits(va_list ap, t_flag *pf)
{
	int			len;
	uintmax_t	i;

	len = 0;
	if (pf->cha == 'U' || pf->cha == 'p' || pf->cha == 'O')
		pf->mod = 2;
	i = udigit_spec(ap, pf);
	pf->pos = 0;
	if (pf->cha == 'u' || pf->cha == 'U')
		len = unint(i, pf);
	if (pf->cha == 'o' || pf->cha == 'O')
		len = oct(i, 0, pf);
	if (pf->cha == 'p')
		len = ptr(i);
	if (pf->cha == 'x' || pf->cha == 'X')
		len = hex(i, pf);
	return (len);
}
