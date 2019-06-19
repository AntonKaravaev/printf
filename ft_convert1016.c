/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert1016.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:39:09 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/20 01:03:46 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ui(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned int	remainder;
	unsigned int	localnum;
	int				i;
	int				j;

	i = 0;
	j = 0;
	localnum = (unsigned int)num;
	if (localnum == 0)
		spec->buf[j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[j++] = 48 + remainder;
		else
			spec->buf[j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	j--;
	while (i < j)
	{
		remainder = spec->buf[i];
		spec->buf[i++] = spec->buf[j];
		spec->buf[j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}

void	ft_usi(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned short int	remainder;
	unsigned short int	localnum;
	int				i;
	int				j;

	i = 0;
	j = 0;
	localnum = (unsigned short int)num;
	if (localnum == 0)
		spec->buf[j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[j++] = 48 + remainder;
		else
			spec->buf[j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	j--;
	while (i < j)
	{
		remainder = spec->buf[i];
		spec->buf[i++] = spec->buf[j];
		spec->buf[j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}

void	ft_ucc(t_spec *spec, t_ran *ran, unsigned long long int num,
	int smallbig)
{
	unsigned char	remainder;
	unsigned char	localnum;
	int				i;
	int				j;

	i = 0;
	j = 0;
	localnum = (unsigned char)num;
	if (localnum == 0)
		spec->buf[j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[j++] = 48 + remainder;
		else
			spec->buf[j++] = 55 + smallbig + remainder;
		localnum = localnum / 16;
	}
	j--;
	while (i < j)
	{
		remainder = spec->buf[i];
		spec->buf[i++] = spec->buf[j];
		spec->buf[j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}

void	ft_uli(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long int	remainder;
	unsigned long int	localnum;
	int				i;
	int				j;

	i = 0;
	j = 0;
	localnum = (unsigned long int)num;
	if (localnum == 0)
		spec->buf[j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[j++] = 48 + remainder;
		else
			spec->buf[j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	j--;
	while (i < j)
	{
		remainder = spec->buf[i];
		spec->buf[i++] = spec->buf[j];
		spec->buf[j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}

void	ft_ulli(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long long int	remainder;
	unsigned long long int	localnum;
	int				i;
	int				j;

	i = 0;
	j = 0;
	localnum = (unsigned long long int)num;
	if (localnum == 0)
		spec->buf[j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[j++] = 48 + remainder;
		else
			spec->buf[j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	j--;
	while (i < j)
	{
		remainder = spec->buf[i];
		spec->buf[i++] = spec->buf[j];
		spec->buf[j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}
