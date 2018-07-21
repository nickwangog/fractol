/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 18:01:38 by nwang             #+#    #+#             */
/*   Updated: 2018/02/12 15:49:21 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		output(va_list ap, t_flag *pf)
{
	int i;

	i = 0;
	if (pf->starw == 1)
		pf->mwidth = (va_arg(ap, int));
	if (pf->starp == 1)
		pf->prec = (va_arg(ap, int));
	if ((pf->cha == 'd') || (pf->cha == 'D') || (pf->cha == 'i'))
		i += digits(ap, pf, 0);
	if ((pf->cha == 'o') || (pf->cha == 'O') || (pf->cha == 'u') ||
		(pf->cha == 'U') || (pf->cha == 'x') || (pf->cha == 'X') ||
		(pf->cha == 'p'))
		i += udigits(ap, pf);
	if (pf->cha == 'c' || pf->cha == 'C' || pf->cha == 's' ||
		pf->cha == 'S' || pf->cha == '%')
		i += letters(ap, pf);
	return (i);
}
