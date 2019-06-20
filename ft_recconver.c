/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recconver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:40 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/21 01:54:12 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag(char *str, t_ran *ran, t_spec *spec)
{
	while (str[ran->i] != ran->conver)
	{
		if (str[ran->i] == 'h')
		{
			ran->i++;
			spec->flag = 1;
			if (str[ran->i] == 'h')
			{
				spec->flag = 2;
			}
			return ;
		}
		if (str[ran->i] == 'l')
		{
			ran->i++;
			spec->flag = 3;
			if (str[ran->i] == 'l')
			{
				spec->flag = 4;
			}
			return ;
		}
		ran->i++;
	}
}

void	ft_acc(char *str, t_ran *ran, t_spec *spec)
{
	while (str[ran->i] != ran->conver && str[ran->i] != 'h'
		&& str[ran->i] != 'l')
	{
		if (str[ran->i] == '.')
		{
			ran->i++;
			if (str[ran->i] >= '1' && str[ran->i] <= '9')
			{
				spec->buf[spec->z++] = str[ran->i++];
				while (str[ran->i] >= '0' && str[ran->i] <= '9')
					spec->buf[spec->z++] = str[ran->i++];
				spec->acc = ft_atoi(spec->buf);
				return ;
			}
			else
			{
				spec->acc = -1;
				return ;
			}
		}
		ran->i++;
	}
}

void	ft_width(char *str, t_ran *ran, t_spec *spec)
{
	int z;

	while (str[ran->i] != ran->conver && str[ran->i] != '.'
		&& str[ran->i] != 'h' && str[ran->i] != 'l')
	{
		if (str[ran->i] >= '1' && str[ran->i] <= '9')
		{
			z = 0;
			spec->buf[z++] = str[ran->i++];
			while (str[ran->i] >= '0' && str[ran->i] <= '9')
				spec->buf[z++] = str[ran->i++];
			spec->width = ft_atoi(spec->buf);
			return ;
		}
		ran->i++;
	}
}

void	ft_whilenotconver(char *str, t_ran *ran, t_spec *spec)
{
	ft_width(str, ran, spec);
	ft_reworkbuf(spec);
	ft_acc(str, ran, spec);
	ft_reworkbuf(spec);
	ft_flag(str, ran, spec);
	while (str[ran->i] != ran->conver)
		ran->i++;
}

void	ft_recconver(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{
	if (ran->conver == '%')
		ft_p_record(str, ran, spec);
	// if (ran->conver == 'c')
	// ft_c_record(str, ran, vl, spec);
	// if (ran->conver == 's')
	// ft_s_record(str, ran, vl, spec);
	// if (ran->conver == 'p')
	// ft_p_record(str, ran, vl, spec);
	if (ran->conver == 'd')
		ft_d_record(str, ran, vl, spec);
	// if (ran->conver == 'i')
	// 	ft_i_record(str, ran, vl, spec);
	// if (ran->conver == 'o')
	// 	ft_o_record(str, ran, vl, spec);
	// if (ran->conver == 'u')
		// ft_u_record(str, ran, vl, spec);
	if (ran->conver == 'x')
	{
		ft_whilenotconver(str, ran, spec);
		ft_x_record(ran, vl, spec);
	}
	if (ran->conver == 'X')
	{
		ft_whilenotconver(str, ran, spec);
		ft_X_record(ran, vl, spec);
	}

	// if (ran->conver == 'f')
	// 	ft_f_record(str, ran, vl, spec);
	ft_newstruct(spec);
}
