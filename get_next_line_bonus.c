/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:15:55 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/25 13:39:29 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*afnl(char *bf)
{
	int		i;
	char	*nw;

	i = 0;
	while (bf[i])
	{
		if (bf[i] == '\n')
		{
			nw = ft_substr(bf, i + 1, ft_strlen(bf) - i - 1);
			if (!nw)
				return (free(bf), bf = NULL, NULL);
			free(bf);
			bf = NULL;
			return (nw);
		}
		i++;
	}
	free (bf);
	bf = NULL;
	return (NULL);
}

char	*bfnl(char *bf)
{
	int		i;
	char	*line;

	i = 0;
	while (bf[i])
	{
		if (bf[i] == '\n')
		{
			line = ft_substr(bf, 0, i + 1);
			if (!line)
				return (NULL);
			return (line);
		}
		i++;
	}
	line = ft_strdup(bf);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*rdbuff;
	char		*lgn;
	static char	*bf[OPEN_MAX];
	int			k;

	rdbuff = malloc(BUFFER_SIZE + 1);
	if (!rdbuff)
		return (free(bf[fd]), bf[fd] = NULL, NULL);
	(!bf[fd]) && (bf[fd] = ft_strdup(""));
	k = 1;
	while (!ft_strchr(bf[fd], '\n') && k > 0)
	{
		k = read(fd, rdbuff, BUFFER_SIZE);
		if (k < 0)
			return (free(rdbuff), free(bf[fd]), bf[fd] = NULL, NULL);
		rdbuff[k] = '\0';
		bf[fd] = ft_strjoin(bf[fd], rdbuff);
	}
	if (!bf[fd] || !*bf[fd])
		return (free(rdbuff), free(bf[fd]), bf[fd] = NULL, NULL);
	lgn = bfnl(bf[fd]);
	if (!lgn)
		return (free(rdbuff), free(bf[fd]), bf[fd] = NULL, NULL);
	return (bf[fd] = afnl(bf[fd]), free(rdbuff), lgn);
}
