/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:48:23 by masik             #+#    #+#             */
/*   Updated: 2026/08/13 01:15:18 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	ng;
	int	sayi;

	i = 0;
	ng = 1;
	sayi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ng = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sayi = 10 * sayi + (str[i] - '0');
		i++;
	}
	return (ng * sayi);
}
