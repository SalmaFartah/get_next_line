/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:06:38 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/09 20:45:27 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void ft_free(char **p)
{
	if(p)
	{
		free(*p);
		*p = NULL;
	}
}
int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);	
}

char *afnl(char **bf)
{
	int	i;
	size_t lb;
	char *nw;

	i = 0;
	lb = ft_strlen(*bf);
	while ((*bf)[i])
	{
		if ((*bf)[i] == '\n')
		{
			nw = ft_substr(*bf, i + 1, lb);
			ft_free(bf);
			return (nw);
		}
		i++;
	}
	ft_free (bf);
	return (NULL);
}
char *bfnl(char **bf)
{
    int i;
	char *line;

    i = 0;
    while ((*bf)[i])
	{
		if ((*bf)[i] == '\n')
		{
			line = ft_substr(*bf, 0, i + 1);
			return (line);
		}
		i++;
	}
	line = ft_strdup(*bf);
    return (line);
}

char	*get_next_line(int fd)
{
	char *rdbuff;
	char *lgn;
	static char *bf;
	int k;

	rdbuff = malloc(BUFFER_SIZE + 1);
	if (!rdbuff)
		return (ft_free(&bf), NULL);
	(!bf) && (bf = ft_strdup(""));
	k = 1;
	while (!ft_strchr(bf, '\n') && k > 0)
	{
		k = read(fd, rdbuff,BUFFER_SIZE);
		if (k < 0)
			return (ft_free(&rdbuff), ft_free(&bf), NULL);
		rdbuff[k] = '\0';
		bf = ft_strjoin(bf, rdbuff);
	}
	ft_free(&rdbuff);
	if (!bf || ft_strcmp(bf, "") == 0)
		return (ft_free(&bf), NULL);
	lgn = bfnl(&bf);
	bf = afnl(&bf);
	return (lgn);
}

// #include <fcntl.h>
// int main()
// {
// 	int fd = open("tst.txt", O_CREAT | O_RDWR, 0777);
// 	char *l = get_next_line(fd);
// 	char *t = get_next_line(fd);
// 	char *r = get_next_line(fd);
// 	printf("%s", l);
// 	printf("%s", t);
// 	printf("%s", r);

// 	system("leaks a.out");
// }
