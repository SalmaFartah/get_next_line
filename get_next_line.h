/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:44:03 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/07 16:58:41 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *s);
int 	ft_strchr(char *s, int c);
char	*bfnl(char *bf);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*afnl(char *bf);
int     ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
#endif