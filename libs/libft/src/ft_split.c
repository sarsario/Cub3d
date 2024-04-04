/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:18:52 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 14:59:05 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**ft_free(char **new, int i)
{
	while (i--)
		free(new[i]);
	free(new);
	return (0);
}

static int	ft_count_newstrs(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_fill_newstr(char *s, char c, char *str)
{
	int	i;

	i = 0;
	while (*s == c)
		s++;
	while ((*s != c) && *s)
	{
		str[i] = *s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_newstrs(char *s, char c, int newstrs, char **new)
{
	int	i;
	int	j;
	int	next_newstr;
	int	len_newstr;

	i = 0;
	j = 0;
	while (i < newstrs)
	{
		len_newstr = 0;
		next_newstr = j;
		while (s[j] == c)
			j++;
		while ((s[j] != c) && s[j++])
			len_newstr++;
		new[i] = (char *)malloc(sizeof(char) * (len_newstr + 1));
		if (!new[i])
			return (ft_free(new, i));
		new[i] = ft_fill_newstr((char *)s + next_newstr, c, new[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		newstrs;

	if (!s)
		return (NULL);
	newstrs = ft_count_newstrs((char *)s, c);
	new = (char **)malloc(sizeof(char *) * (newstrs + 1));
	if (!new)
		return (NULL);
	new = ft_newstrs((char *)s, c, newstrs, new);
	return (new);
}
