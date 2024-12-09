/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:06:38 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/09 13:57:14 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);	
}

char *afnl(char *bf)
{
	int	i;
	size_t lb;

	i = 0;
	lb = ft_strlen(bf);
	while (bf[i])
	{
		if (bf[i] == '\n')
			return (ft_substr(bf, i + 1, lb));
			
		i++;
	}
	return (NULL);
}
char *bfnl(char *bf)
{
    int i;

    i = 0;
    while (bf[i])
	{
		if (bf[i] == '\n')
		{
			bf = ft_substr(bf, 0, i + 1);
		}
		i++;
	}
    return (bf);
}

char	*get_next_line(int fd)
{
	char *rdbuff;
	char *lgn;
	static char *bf;
	int k;

	rdbuff = malloc(BUFFER_SIZE + 1);
	if (!rdbuff)
		return (NULL);
	(!bf) && (bf = "");
	k = 1;
	while (!ft_strchr(bf, '\n') && k > 0)
	{
		k = read(fd, rdbuff,BUFFER_SIZE);
		if (k < 0)
			return (free(rdbuff), NULL);
		rdbuff[k] = '\0';
		bf = ft_strjoin(bf, rdbuff);
	}
	if (ft_strcmp(bf, "") == 0)
		return (NULL);
	lgn = bfnl(bf);
	bf = afnl(bf);
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

// 	// system("leaks a.out");
// }
