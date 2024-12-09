/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:16:56 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/09 18:15:53 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strdup(char *s1)
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
char	*ft_substr(char *s, unsigned int start, size_t len)
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


int ft_strchr(char *s, int c)
{
	size_t	u;

	u = 0;
	if (!s || !c)
		return 0;
	while (u <= ft_strlen(s))
	{
		if (s[u] == (unsigned char)c)
			return (1);
		u++;
	}
	return (0);
}
size_t	ft_strlen(char *s)
{
    size_t	counter;

    counter = 0;
	if (!s)
		return (0);
    while (s[counter])
		counter++;
    return (counter);
}
char *ft_strjoin(char *s1, char *s2)
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
    k = 0;
    while (k <= ls2)
        p[i++] = s2[k++];
	ft_free(&s1);
    return (p);
}
