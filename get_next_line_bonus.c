/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:15:55 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/19 15:23:32 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **p)
{
	if (p)
	{
		free(*p);
		*p = NULL;
	}
}

char	*afnl(char **bf)
{
	int		i;
	char	*nw;

	i = 0;
	while ((*bf)[i])
	{
		if ((*bf)[i] == '\n')
		{
			nw = ft_substr(*bf, i + 1, ft_strlen(*bf) - i - 1);
			if (!nw)
				return (ft_free(bf), NULL);
			ft_free(bf);
			return (nw);
		}
		i++;
	}
	ft_free (bf);
	return (NULL);
}

char	*bfnl(char **bf)
{
	int		i;
	char	*line;

	i = 0;
	while ((*bf)[i])
	{
		if ((*bf)[i] == '\n')
		{
			line = ft_substr(*bf, 0, i + 1);
			if (!line)
				return (NULL);
			return (line);
		}
		i++;
	}
	line = ft_strdup(*bf);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*rdbuff;
	char		*lgn;
	static char	*bf[10240];
	int			k;

	rdbuff = malloc(BUFFER_SIZE + 1);
	if (!rdbuff)
		return (ft_free(&bf[fd]), NULL);
	(!bf[fd]) && (bf[fd] = ft_strdup(""));
	k = 1;
	while (!ft_strchr(bf[fd], '\n') && k > 0)
	{
		k = read(fd, rdbuff, BUFFER_SIZE);
		if (k < 0)
			return (ft_free(&rdbuff), ft_free(&bf[fd]), NULL);
		rdbuff[k] = '\0';
		bf[fd] = ft_strjoin(bf[fd], rdbuff);
	}
	if (!bf[fd] || !*bf[fd])
		return (ft_free(&rdbuff), ft_free(&bf[fd]), NULL);
	lgn = bfnl(&bf[fd]);
	if (!lgn)
		return (ft_free(&rdbuff), ft_free(&bf[fd]), NULL);
	return (bf[fd] = afnl(&bf[fd]), ft_free(&rdbuff), lgn);
}
