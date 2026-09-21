/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:55:52 by masik             #+#    #+#             */
/*   Updated: 2026/08/17 21:41:35 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*ptr;

	if (!dst && !src)
		return (NULL);
	ptr = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			ptr[len] = str[len];
		}
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
