/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:16:56 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/25 13:24:49 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	int		u;
	char	*ptr;

	if (!s1)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (free(ptr), NULL);
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
	char	*ptr;
	char	*stdph;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		stdph = ft_strdup("");
		if (!stdph)
			return (NULL);
		return (stdph);
	}
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

int	ft_strchr(char *s, int c)
{
	size_t	u;

	u = 0;
	if (!s)
		return (0);
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

	if (!s)
		return (0);
	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	k;
	char	*p;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (free(s1), NULL);
	i = 0;
	if (ft_strlen(s1))
	{
		while (i < ft_strlen(s1))
		{
			p[i] = s1[i];
			i++;
		}
	}
	k = 0;
	while (k <= ft_strlen(s2))
		p[i++] = s2[k++];
	free(s1);
	return (p);
}
