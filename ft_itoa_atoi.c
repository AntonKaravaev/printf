/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:36 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/25 15:01:03 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dmoveonestep(t_spec *s)
{
	int	i;

	if (s->pmz == 1 || (s->plus == 1 && s->pmz != 1))
	{
		i = ft_strlen(s->buf);
		while (i > 0)
		{
			s->buf[i] = s->buf[i - 1];
			i--;
		}
		if (s->pmz == 1)
		{
			s->buf[i] = '-';
			s->j = ft_strlen(s->buf) + 1;
		}
		else if (s->plus == 1 && s->pmz != 1)
		{
			s->buf[i] = '+';
			s->j = ft_strlen(s->buf) + 1;
		}
	}
}

static 	char	*fill(int i, int n, t_spec *s)
{
	int num;

	num = n;
	if (ft_checkdzero(s, n) == 1)
		return (s->buf);
	// if (s->pmz == 1)
	// 	s->buf[s->j++] = '-';
	// else if (s->plus == 1)
	// 	s->buf[s->j++] = '+';
	while (i > 0)
	{
		s->buf[s->j++] = n / i + '0';
		n = n % i;
		i = i / 10;
	}
	s->buf[s->j] = '\0';
	if (s->width != 0 && (s->acc == 0 || s->acc == -1))
		ft_dmoveonestep(s);
	return (s->buf);
}

char		*ft_itoa(int n, t_spec *s)
{
	unsigned int	i;
	int				count;

	if (n == -2147483648)
		s->buf = ft_strdup("-2147483648");
	else
	{
		count = 0;
		if (s->pmz == 1)
			n = -n;
		i = 1;
		while (n / i > 9)
		{
			i = i * 10;
			count++;
		}
		fill(i, n, s);
	}
	return (s->buf);
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
