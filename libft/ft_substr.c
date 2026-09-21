/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 00:02:03 by masik             #+#    #+#             */
/*   Updated: 2026/08/09 00:01:29 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*src;

	i = 0;
	while (s[i])
		i++;
	if (start >= i)
		size = 0;
	else if (i - start < len)
		size = i - start;
	else
		size = len;
	src = malloc(size + 1);
	if (!src)
		return (NULL);
	i = 0;
	while (i < size)
	{
		src[i] = s[start + i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
