/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:06:38 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/25 13:38:48 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				return (free(bf), NULL);
			free(bf);
			return (nw);
		}
		i++;
	}
	free(bf);
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
	static char	*bf;
	int			k;

	rdbuff = malloc(BUFFER_SIZE + 1);
	if (!rdbuff)
		return (free(bf), bf = NULL, NULL);
	(!bf) && (bf = ft_strdup(""));
	k = 1;
	while (!ft_strchr(bf, '\n') && k > 0)
	{
		k = read(fd, rdbuff, BUFFER_SIZE);
		if (k < 0)
			return (free(rdbuff), free(bf), bf = NULL, NULL);
		rdbuff[k] = '\0';
		bf = ft_strjoin(bf, rdbuff);
	}
	if (!bf || !*bf)
		return (free(rdbuff), free(bf), bf = NULL, NULL);
	lgn = bfnl(bf);
	if (!lgn)
		return (free(rdbuff), free(bf), bf = NULL, NULL);
	return (bf = afnl(bf), free(rdbuff), lgn);
}
