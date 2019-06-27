/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:27:32 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/27 21:04:43 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strjcpy(char *dest, t_spec *s, int *j)
{
	int i;

	i = 0;
	while (s->buf[i])
		dest[(*j)++] = s->buf[i++];
	dest[(*j)] = '\0';
}

void	ft_easyflag(char *str, t_spec *s, int j)
{
	while (str[j] != '\0' && str[j] != '%' && str[j] != 'c' && str[j] != 's'
		&& str[j] != 'p' && str[j] != 'd' && str[j] != 'i' && str[j] != 'o'
		&& str[j] != 'u' && str[j] != 'x' && str[j] != 'X' && str[j] != 'f'
		&& str[j] != '\n' && str[j] != '\t' && str[j] != '\v'
		&& (str[j] < '1' || str[j] > '9'))
	{
		if (str[j] == '-')
			s->minus = 1;
		if (str[j] == '+')
			s->plus = 1;
		if (str[j] == '0')
			s->zero = 1;
		if (str[j] == '#')
			s->grid = 1;
		if (str[j] == ' ')
			s->space = 1;
		j++;
	}
	if (s->minus == 0 && s->plus == 0 && s->zero == 0 && s->grid == 0
		&& s->space == 0)
		s->allflagzero = 1;
}

void	ft_procwidth(char *str, t_ran *ran, t_spec *s)
{
	int z;

	while (str[ran->i] != ran->conver)
	{
		if (str[ran->i] >= '1' && str[ran->i] <= '9')
		{
			z = 0;
			ft_bzero(s->buf, 1001);
			s->buf[z++] = str[ran->i++];
			while (str[ran->i] >= '0' && str[ran->i] <= '9')
				s->buf[z++] = str[ran->i++];
			if (str[ran->i] == ran->conver)
			{
				s->width = ft_atoi(s->buf);
				return ;
			}
			else
			{
				s->width = ft_atoi(s->buf);
				ran->i--;
			}
		}
		ran->i++;
	}
}

int		ft_biggeraccornum(t_spec *s)
{
	if (ft_strlen(s->buf) < s->acc)
		return (s->acc);
	return (ft_strlen(s->buf));
}
