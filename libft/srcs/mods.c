/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:51:00 by nwang             #+#    #+#             */
/*   Updated: 2018/02/11 22:08:01 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_spec(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == 'e' || c == 'E' || c == 'f' ||
		c == 'F' || c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'n')
		return (1);
	return (0);
}

int		check_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ' || c == '.')
		return (1);
	return (0);
}

int		which_mods(const char *f, int i, t_flag *pf)
{
	while (f[i] && f[i] != '%' && (!check_spec(f[i])))
	{
		if (f[i] == 'h' && f[i + 1] != 'h')
			pf->mod = 1;
		if (f[i] == 'l' && f[i + 1] != 'l')
			pf->mod = 2;
		if (f[i] == 'j')
			pf->mod = 3;
		if (f[i] == 'z')
			pf->mod = 4;
		if (f[i] == 'h' && f[i + 1] == 'h')
		{
			pf->mod = 5;
			i++;
		}
		if (f[i] == 'l' && f[i + 1] == 'l')
			pf->mod = 6;
		i++;
	}
	if (pf->mod >= 5)
		return (2);
	if (pf->mod > 0 && pf->mod < 5)
		return (1);
	return (0);
}
