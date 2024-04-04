/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:48:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 14:56:33 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char		*ptr;
// 	size_t		i;

// 	ptr = malloc(count * size);
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (i < (size * count))
// 	{
// 		ptr[i] = '\0';
// 		i++;
// 	}
// 	return (ptr);
// }

int	ft_strchr(char *stash, char c)
{
	int	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i] && (stash[i] != c))
		i++;
	if (stash[i] == c)
		return (1);
	return (0);
}

// size_t	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_free_join(char	*buffer, char *stash)
{
	char	*tmp;

	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	if (!stash)
	{
		stash = ft_calloc(1, sizeof(char));
		if (!stash)
			return (NULL);
	}
	tmp = ft_strjoin(buffer, stash);
	return (tmp);
}

char	*ft_strjoin(char *buffer, char *stash)
{
	char	*joined;
	int		i;
	int		j;

	joined = ft_calloc(ft_strlen(buffer) + ft_strlen(stash) + 1, sizeof(char));
	if (!joined)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\0')
	{
		joined[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j] != '\0')
	{
		joined[i + j] = buffer[j];
		j++;
	}
	joined[i + j] = '\0';
	free(stash);
	return (joined);
}
