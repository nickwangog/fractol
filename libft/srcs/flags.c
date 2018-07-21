/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:07:14 by nwang             #+#    #+#             */
/*   Updated: 2018/02/16 21:18:27 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		prec(const char *f, int i, t_flag *pf)
{
	char	*tmp;
	int		j;

	j = 0;
	i++;
	tmp = (char *)malloc(sizeof(char) * 12);
	while (ft_isdigit(f[i]))
	{
		tmp[j] = f[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	pf->prec = ft_atoi(tmp);
	pf->dot = 1;
	free(tmp);
	return (i);
}

void	star(const char *f, int i, t_flag *pf)
{
	pf->star = 1;
	if (f[i - 1] == '.')
		pf->starp = 1;
	else
		pf->starw = 1;
}

int		width(const char *f, int i, t_flag *pf)
{
	int x;

	x = 0;
	while (ft_isdigit(f[i]))
	{
		x = (x * 10) + (f[i] - 48);
		pf->mwidth = x;
		i++;
	}
	return (i);
}

int		which_flag(const char *f, int i, int x, t_flag *pf)
{
	while (f[i] && f[i] != '%' && !check_spec(f[i]))
	{
		if (f[i] == '#')
			pf->hash = 1;
		else if (ft_isdigit(f[i]))
		{
			if (f[i] == '0')
				pf->zero = 1;
			else
				i = width(f, i, pf) - 1;
		}
		else if (f[i] == '-')
			pf->minus = 1;
		else if (f[i] == '+')
			pf->pos = 1;
		else if (f[i] == ' ' && !check_spec(f[i - 1]))
			pf->sp = 1;
		else if (f[i] == '.')
			i = prec(f, i, pf);
		else if (f[i] == '*')
			star(f, i, pf);
		i++;
		x++;
	}
	return (x);
}

int		valid_char(const char *f, int i, t_flag *pf)
{
	while (f[i] && f[i] != '%')
	{
		if (check_spec(f[i]))
		{
			pf->cha = f[i];
			return (1);
		}
		i++;
	}
	if (f[i] == '%')
	{
		pf->cha = f[i];
		return (1);
	}
	return (0);
}
