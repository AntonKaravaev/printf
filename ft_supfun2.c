/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:27:32 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/20 22:04:46 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_findpmz(t_spec *spec, int num)
{
	spec->pmz = 0;
	if (num < 0)
		spec->pmz = 1;
	else if (num == 0)
		spec->pmz = 2;
}

void	ft_strjcpy(char *dest, char *src, int *j)
{
	int i;

	i = 0;
	while (src[i])
		dest[(*j)++] = src[i++];
	dest[(*j)] = '\0';
}

void	ft_easyflag(char *str, t_spec *spec, int j)
{
	while (str[j] != '\0' && str[j] != '%' && str[j] != 'c' && str[j] != 's'
		&& str[j] != 'p' && str[j] != 'd' && str[j] != 'i' && str[j] != 'o'
		&& str[j] != 'u' && str[j] != 'x' && str[j] != 'X' && str[j] != 'f'
		&& str[j] != '\n' && str[j] != '\t' && str[j] != '\v'
		&& (str[j] < '1' || str[j] > '9'))
	{
		if (str[j] == '-')
			spec->minus = 1;
		if (str[j] == '+')
			spec->plus = 1;
		if (str[j] == '0')
			spec->zero = 1;
		if (str[j] == '#')
			spec->grid = 1;
		if (str[j] == ' ')
			spec->space = 1;
		j++;
	}
	if (spec->minus == 0 && spec->plus == 0 && spec->zero == 0 &&
		spec->grid == 0 && spec->space == 0)
		spec->allflagzero = 1;
}

void	ft_procwidth(char *str, t_ran *ran, t_spec *spec)
{
	int z;

	while (str[ran->i] != ran->conver)
	{
		if (str[ran->i] >= '1' && str[ran->i] <= '9')
		{
			z = 0;
			ft_bzero(spec->buf, 1001);
			spec->buf[z++] = str[ran->i++];
			while (str[ran->i] >= '0' && str[ran->i] <= '9')
				spec->buf[z++] = str[ran->i++];
			if (str[ran->i] == ran->conver)
			{
				spec->width = ft_atoi(spec->buf);
				return ;
			}
			else
			{
				spec->width = ft_atoi(spec->buf);
				ran->i--;
			}
		}
		ran->i++;
	}
}
