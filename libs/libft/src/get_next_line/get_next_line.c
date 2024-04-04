/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:35:15 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 14:57:14 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

/*
Deletes the first line (=line ending with \n) from stash
Copies all lines except for the first line from stash in new_stash 
*/

char	*delete_first_line(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_calloc(ft_strlen(stash) - i, sizeof(char));
	if (!new_stash)
	{
		free (stash);
		return (NULL);
	}
	j = 0;
	while (stash[++i] != '\0')
		new_stash[j++] = stash[i];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

/*
Search and retrieve the first line from stash
*/

char	*get_first_line(char *stash)
{
	char	*first_line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	first_line = ft_calloc(i + 2, sizeof(char));
	if (!first_line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		first_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		first_line[i] = stash[i];
		i++;
	}
	first_line[i] = '\0';
	return (first_line);
}

/*
Read nbytes (= BUFFERSIZE) from the opened file indicated by fd
into buffer until \n or eof
Copy and append the bytes read from buffer to stash
*/

char	*read_line(int fd, char *stash)
{
	int		chars_read;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	chars_read = 1;
	while ((ft_strchr(stash, '\n') == 0) && chars_read != 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buffer);
			if (stash)
				free (stash);
			return (NULL);
		}
		buffer[chars_read] = '\0';
		stash = ft_free_join(buffer, stash);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	new_line = get_first_line(stash);
	if (!new_line)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	stash = delete_first_line(stash);
	return (new_line);
}
