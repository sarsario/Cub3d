/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:11:14 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 14:59:25 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && !len)
		return (0);
	if (!*needle || needle == haystack)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && (j < len) && (i + j < len))
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (j == ft_strlen(needle))
			return ((char *)haystack + i);
		else
			i++;
	}
	return (0);
}
