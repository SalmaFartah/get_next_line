/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:06:38 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/07 20:23:16 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

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
		if (k < BUFFER_SIZE)
			rdbuff = ft_substr(rdbuff, 0, k);
		rdbuff[k] = '\0';
		bf = ft_strjoin(bf, rdbuff);
	}
	if (ft_strcmp(bf, "") == 0)
		return (NULL);
	lgn = bfnl(bf);
	bf = afnl(bf);
	return (lgn);
}

#include <fcntl.h>
int main()
{
	int fd = open("tst.txt", O_CREAT | O_RDWR, 0777);
	char *l = get_next_line(fd);
	char *t = get_next_line(fd);
	char *r = get_next_line(fd);
	printf("%s", l);
	printf("%s", t);
	printf("%s", r);

	// system("leaks a.out");
}
