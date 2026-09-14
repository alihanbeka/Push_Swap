/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:48:23 by masik             #+#    #+#             */
/*   Updated: 2026/09/14 23:26:31 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	ng;
	long int	sayi;
	
	
	
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





int	parse_int(const char *str, int *value)
{
	long	number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		if ((sign == 1 && number > 2147483647L)
			|| (sign == -1 && number > 2147483648L))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*value = (int)(number * sign);
	return (1);
}




#include "push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_check(const char *str, int *out_value)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!is_digit(str[i]))
		return (0);
	while (is_digit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');//sınırları aşıyor mu kontrol edilmeli ve gerekirse düzeltilmeli
		if ((sign * num) > 2147483647 || (sign * num) < -2147483648)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*out_value = (int)(sign * num);
	return (1);
}

