/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:36 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/14 14:59:58 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fill(int sign, int i, int n, char *str)
{
	int j;

	j = 0;
	if (sign == 1)
	{
		str[j] = '-';
		j++;
	}
	while (i > 0)
	{
		str[j] = n / i + '0';
		n = n % i;
		i = i / 10;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	int				sign_flag;
	int				count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign_flag = 0;
	count = 0;
	if (n < 0)
	{
		sign_flag = 1;
		n = -n;
	}
	i = 1;
	while (n / i > 9)
	{
		i = i * 10;
		count++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (count + 1 + sign_flag) + 1)))
		return (NULL);
	return (fill(sign_flag, i, n, str));
}
