/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:44:31 by nwang             #+#    #+#             */
/*   Updated: 2018/07/04 17:44:34 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print2darray(char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!array)
	{
		ft_putstr("Error");
		return ;
	}
	while (array[i] && array[i] != NULL)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		i++;
	}
}
