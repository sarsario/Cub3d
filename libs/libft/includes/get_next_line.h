/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:50:18 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/04 12:47:38 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_free_join(char	*buffer, char *stash);
char	*ft_strjoin(char *buffer, char *stash);

// void	*ft_calloc(size_t count, size_t size);

int		ft_strchr(char *stash, char c);

// size_t	ft_strlen(char *s);

#endif
