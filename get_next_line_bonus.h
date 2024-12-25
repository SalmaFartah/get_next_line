/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:15:50 by sfartah           #+#    #+#             */
/*   Updated: 2024/12/25 13:34:15 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*bfnl(char *bf);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*afnl(char *bf);
char	*ft_strdup(char *s1);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
#endif