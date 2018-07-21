/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:39:33 by nwang             #+#    #+#             */
/*   Updated: 2018/03/18 16:57:41 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_line(char **storage, char **line)
{
	char			*tmp;
	char			*strcheck;
	char			*tmp2;
	int				i;

	i = 0;
	strcheck = *storage;
	while (strcheck[i] != '\n')
		if (!strcheck[i++])
			return (0);
	tmp = &strcheck[i];
	*tmp = '\0';
	*line = ft_strdup(*storage);
	tmp2 = *storage;
	*storage = ft_strdup(tmp + 1);
	free(tmp2);
	return (1);
}

static	int			ft_read(int fd, char *tmpstore, char **storage, char **line)
{
	int				ret;
	char			*tmp;

	while ((ret = read(fd, tmpstore, BUFF_SIZE)) > 0)
	{
		tmpstore[ret] = '\0';
		if (*storage)
		{
			tmp = ft_strjoin(*storage, tmpstore);
			free(*storage);
			*storage = tmp;
		}
		else
			*storage = ft_strdup(tmpstore);
		if (check_line(storage, line))
			break ;
	}
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		*storage[10000];
	char			*tmpstore;
	char			tmp[2];
	int				ret;

	if (!line || (fd < 0) || (read(fd, tmp, 0) < 0) ||
			!(tmpstore = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (storage[fd])
		if (check_line(&storage[fd], line))
			return (1);
	ret = ft_read(fd, tmpstore, &storage[fd], line);
	free(tmpstore);
	if (ret != 0 || storage[fd] == NULL || storage[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		if (ret > 0)
			return (1);
		else if (ret == 0)
			return (0);
	}
	*line = storage[fd];
	storage[fd] = NULL;
	return (1);
}
