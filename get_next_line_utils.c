/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:16:56 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/07 16:35:04 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void ffree(char *s, int st, int l)
{
	int i;
	i = 0;

	while (i < l)
	{
		free (s + st + i);
		i++;
	}
}
int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);	
}
char	*ft_strdup(const char *s1)
{
	int		u;
	char	*ptr;

	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	u = 0;
	while (s1[u])
	{
		ptr[u] = s1[u];
		u++;
	}
	ptr[u] = '\0';
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	if (!s)
		return (NULL);
	(len > ft_strlen(s) - start) && (len = ft_strlen(s) - start);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char *afnl(char *bf)
{
	int	i;
	size_t lb;
	char *temp;

	i = 0;
	lb = ft_strlen(bf);
	while (bf[i])
	{
		if (bf[i] == '\n')
		{
			temp = ft_substr(bf, i + 1, lb);
			free (bf);
			return (temp);
		}
			
		i++;
	}
	
	return (NULL);
}
char *bfnl(char *bf)
{
    int i;
	char *bh;

    i = 0;
	bh = NULL;
	// printf("bfnl====[%s]\n", bf);
    while (bf[i])
	{
		if (bf[i] == '\n')
		{
			bh = ft_substr(bf, 0, i + 1);
		}
		i++;
	}
	// printf("bfnl****[%s]\n", bf);
	// printf("bh++++[%s]\n", bh);
	// free(bf);
    return (bh);
}

int ft_strchr(char *s, int c)
{
	size_t	u;

	u = 0;
	if (!s)
		return 0;
	while (u <= ft_strlen(s))
	{
		if (s[u] == (unsigned char)c)
			return (1);
		u++;
	}
	return (0);
}
size_t	ft_strlen(char const *s)
{
    size_t	counter;

    counter = 0;
    while (s[counter])
		counter++;
    return (counter);
}
char *ft_strjoin(char const *s1, char const *s2)
{
    size_t ls1;
    size_t ls2;
    size_t i;
    size_t k;
	char *p;

    ls1 = ft_strlen(s1);
    ls2 = ft_strlen(s2);
    p = malloc(ls1 + ls2  + 1);
    if (!p)
        return (NULL);
    i  = 0;
    if (ls1)
        while (i < ls1)
        {
            p[i] = s1[i];
            i++;
        }
	// printf("JOIN----");
    k = 0;
    while (k <= ls2)
        p[i++] = s2[k++];
	p[i] = '\0';
	free((void *)s1);
    return (p);
}
