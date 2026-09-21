/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcmp.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: masik <masik@student.42istanbul.com.tr>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/07 18:15:21 by masik            #+#    #+#              */
/*   Updated: 2026/08/07 18:59:03 by masik           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	const unsigned char	*ptr;

	str = (const unsigned char *) s1;
	ptr = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str[i] != ptr[i])
			return ((unsigned char) str[i] - (unsigned char) ptr[i]);
		i++;
	}
	return (0);
}
