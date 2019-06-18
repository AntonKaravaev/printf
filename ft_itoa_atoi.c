/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:36 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/18 22:39:27 by crenly-b         ###   ########.fr       */
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

static	int	space_free(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
							|| str[i] == '\r' || str[i] == '\n'
							|| str[i] == '\v' || str[i] == '\f'))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	long long int	sg;
	int				start;

	res = 0;
	start = space_free(str);
	i = start;
	sg = 1;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9') ||
							(i == start && (str[i] == '-' || str[i] == '+'))))
	{
		if (str[i] == '-')
			sg = -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if ((((res * 10) + sg * (str[i] - 48)
				- sg * (str[i] - 48)) / 10) != res)
				return (sg == 1 ? -1 : 0);
			else
				res = (res * 10) + sg * (str[i] - 48);
		}
		++i;
	}
	return (res);
}
