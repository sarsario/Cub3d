/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:50:05 by jsteenpu          #+#    #+#             */
/*   Updated: 2024/04/03 14:59:12 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	if (dstsize <= d_len)
		return (s_len + dstsize);
	i = 0;
	while (src[i] && (d_len + i < dstsize - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
