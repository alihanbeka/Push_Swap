/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:10:25 by masik             #+#    #+#             */
/*   Updated: 2026/08/10 16:14:54 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	d;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
	{
		i++;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	d = 0;
	while (d < i)
	{
		str[d] = f(d, s[d]);
		d++;
	}
	str[d] = '\0';
	return (str);
}
