/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:41:16 by nwang             #+#    #+#             */
/*   Updated: 2017/10/03 23:07:30 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*str;

	str = (char *)b;
	if (len == 0)
		return (str);
	counter = 0;
	while (counter < len)
	{
		str[counter] = (char)c;
		counter++;
	}
	return (b);
}
