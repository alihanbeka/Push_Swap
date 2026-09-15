/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masik <masik@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:48:23 by masik             #+#    #+#             */
/*   Updated: 2026/09/15 14:13:18 by masik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	convert_digits(const char *str, int i, int sign, int *out)
{
	long	num;
	long	limit;
	int		digit;

	num = 0;
	limit = 2147483647L;
	if (sign == -1)
		limit = 2147483648L;
	while (is_digit(str[i]))
	{
		digit = str[i] - '0';
		if (num > (limit - digit) / 10)
			return (0);
		num = (num * 10) + digit;
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*out = (int)(num * sign);
	return (1);
}

int	ft_atoi_check(const char *str, int *out)
{
	int	i;
	int	sign;

	if (str == NULL || out == NULL)
		return (0);
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!is_digit(str[i]))
		return (0);
	return (convert_digits(str, i, sign, out));
}
