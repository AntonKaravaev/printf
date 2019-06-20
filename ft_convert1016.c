/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert1016.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:39:09 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/20 14:19:20 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ui(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned int	remainder;
	unsigned int	localnum;

	localnum = (unsigned int)num;
	if (localnum == 0)
		spec->buf[spec->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[spec->j++] = 48 + remainder;
		else
			spec->buf[spec->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	spec->j--;
	while (spec->i < spec->j)
	{
		remainder = spec->buf[spec->i];
		spec->buf[spec->i++] = spec->buf[spec->j];
		spec->buf[spec->j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}

void	ft_usi(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned short int	remainder;
	unsigned short int	localnum;

	localnum = (unsigned short int)num;
	if (localnum == 0)
		spec->buf[spec->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[spec->j++] = 48 + remainder;
		else
			spec->buf[spec->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	spec->j--;
	while (spec->i < spec->j)
	{
		remainder = spec->buf[spec->i];
		spec->buf[spec->i++] = spec->buf[spec->j];
		spec->buf[spec->j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}

void	ft_ucc(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned char	remainder;
	unsigned char	localnum;

	localnum = (unsigned char)num;
	if (localnum == 0)
		spec->buf[spec->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[spec->j++] = 48 + remainder;
		else
			spec->buf[spec->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	spec->j--;
	while (spec->i < spec->j)
	{
		remainder = spec->buf[spec->i];
		spec->buf[spec->i++] = spec->buf[spec->j];
		spec->buf[spec->j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}

void	ft_uli(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long int	remainder;
	unsigned long int	localnum;

	localnum = (unsigned long int)num;
	if (localnum == 0)
		spec->buf[spec->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[spec->j++] = 48 + remainder;
		else
			spec->buf[spec->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	spec->j--;
	while (spec->i < spec->j)
	{
		remainder = spec->buf[spec->i];
		spec->buf[spec->i++] = spec->buf[spec->j];
		spec->buf[spec->j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}

void	ft_ulli(t_spec *spec, t_ran *ran, unsigned long long int num,
	int sm)
{
	unsigned long long int	remainder;
	unsigned long long int	localnum;

	localnum = (unsigned long long int)num;
	if (localnum == 0)
		spec->buf[spec->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			spec->buf[spec->j++] = 48 + remainder;
		else
			spec->buf[spec->j++] = 55 + sm + remainder;
		localnum = localnum / 16;
	}
	spec->j--;
	while (spec->i < spec->j)
	{
		remainder = spec->buf[spec->i];
		spec->buf[spec->i++] = spec->buf[spec->j];
		spec->buf[spec->j--] = remainder;
	}
	ft_bufjoin_x(ran, spec);
}
