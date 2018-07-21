/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addto2darray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:46:30 by nwang             #+#    #+#             */
/*   Updated: 2018/07/11 14:26:15 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addto2darray(char **old, char *s)
{
	char	**new;
	int		i;
	int		j;

	if (!old || (i = 0) == 1)
		return (NULL);
	while (old[i])
		++i;
	if (!(new = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	j = i;
	i = -1;
	while (++i < j)
	{
		if (!(new[i] = ft_strdup(old[i])))
		{
			while (i >= 0)
				free(new[i--]);
			free(new);
			return (NULL);
		}
	}
	new[i] = s;
	new[i + 1] = NULL;
	return (new);
}
