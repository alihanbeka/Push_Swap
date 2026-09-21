/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 17:34:42 by masik             #+#    #+#             */
/*   Updated: 2026/08/14 21:32:00 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		d;

	str = (const unsigned char *) s;
	d = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == d)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
