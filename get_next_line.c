/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:06:38 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/19 15:23:04 by sfartah          ###   ########.fr       */
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
	static char	*bf;
	int			k;

	rdbuff = malloc(BUFFER_SIZE + 1);
	if (!rdbuff)
		return (ft_free(&bf), NULL);
	(!bf) && (bf = ft_strdup(""));
	k = 1;
	while (!ft_strchr(bf, '\n') && k > 0)
	{
		k = read(fd, rdbuff, BUFFER_SIZE);
		if (k < 0)
			return (ft_free(&rdbuff), ft_free(&bf), NULL);
		rdbuff[k] = '\0';
		bf = ft_strjoin(bf, rdbuff);
	}
	if (!bf || !*bf)
		return (ft_free(&rdbuff), ft_free(&bf), NULL);
	lgn = bfnl(&bf);
	if (!lgn)
		return (ft_free(&rdbuff), ft_free(&bf), NULL);
	return (bf = afnl(&bf), ft_free(&rdbuff), lgn);
}

// #include <fcntl.h>
// int main()
// {
// 	int fd = open("tst.txt", O_CREAT | O_RDWR, 0777);
// 	printf("--------first call----------\n");
// 	char *l = get_next_line(fd);
// 	printf("RETURN ==== %s", l);
// 	printf("\n--------second call----------\n");
// 	char *g = get_next_line(fd);
// 	printf("RETURN ==== %s", g);
// 	printf("\n--------third call----------\n");
// 	char *r = get_next_line(fd);
// 	printf("RETURN ==== %s", r);
// 	printf("\n--------4444 call----------\n");
// 	char *lc = get_next_line(fd);
// 	printf("RETURN ==== %s", lc);
// 	printf("\n--------55555 call----------\n");
// 	char *h = get_next_line(fd);
// 	printf("%s", h);
// 		printf("\n--------66666 call----------\n");
// 	char *f = get_next_line(fd);
// 	printf("%s", f);
// 	// system("leaks a.out");
// }
