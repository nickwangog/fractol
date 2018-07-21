/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 23:17:00 by nwang             #+#    #+#             */
/*   Updated: 2018/07/09 23:17:03 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arraydup(char **old)
{
	char	**new;
	int		i;
	int		j;

	if (!old || (i = 0) == 1)
		return (NULL);
	while (old[i])
		++i;
	if (!(new = (char **)malloc(sizeof(char *) * (i + 1))))
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
	new[i] = NULL;
	return (new);
}
