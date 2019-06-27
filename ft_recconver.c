/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recconver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:40 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/27 17:50:16 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag(char *str, t_ran *ran, t_spec *s)
{
	while (str[ran->i] != ran->conver)
	{
		if (str[ran->i] == 'h')
		{
			ran->i++;
			s->flag = 1;
			if (str[ran->i] == 'h')
				s->flag = 2;
			return ;
		}
		if (str[ran->i] == 'l')
		{
			ran->i++;
			s->flag = 3;
			if (str[ran->i] == 'l')
				s->flag = 4;
			return ;
		}
		ran->i++;
	}
}

void	ft_acc(char *str, t_ran *ran, t_spec *s)
{
	while (str[ran->i] != ran->conver && str[ran->i] != 'h'
		&& str[ran->i] != 'l')
	{
		if (str[ran->i] == '.')
		{
			ran->i++;
			while (str[ran->i] == '0')
				ran->i++;
			if (str[ran->i] >= '1' && str[ran->i] <= '9')
			{
				s->buf[s->z++] = str[ran->i++];
				while (str[ran->i] >= '0' && str[ran->i] <= '9')
					s->buf[s->z++] = str[ran->i++];
				s->acc = ft_atoi(s->buf);
				return ;
			}
			else
			{
				s->acc = -1;
				return ;
			}
		}
		ran->i++;
	}
}

void	ft_width(char *str, t_ran *ran, t_spec *s)
{
	int z;

	while (str[ran->i] != ran->conver && str[ran->i] != '.'
		&& str[ran->i] != 'h' && str[ran->i] != 'l')
	{
		if (str[ran->i] >= '1' && str[ran->i] <= '9')
		{
			z = 0;
			s->buf[z++] = str[ran->i++];
			while (str[ran->i] >= '0' && str[ran->i] <= '9')
				s->buf[z++] = str[ran->i++];
			s->width = ft_atoi(s->buf);
			return ;
		}
		ran->i++;
	}
}

void	ft_whilenotconver(char *str, t_ran *ran, t_spec *s)
{
	if (ran->conver != '%')
	{
		ft_width(str, ran, s);
		ft_reworkbuf(s);
		ft_acc(str, ran, s);
		ft_reworkbuf(s);
		ft_flag(str, ran, s);
		while (str[ran->i] != ran->conver)
			ran->i++;
	}
}

void	ft_recconver(char *str, t_ran *ran, va_list *vl, t_spec *s)
{
	ft_whilenotconver(str, ran, s);
	if (ran->conver == '%')
		ft_p_record(str, ran, s);
	if (ran->conver == 'c')
		ft_c_record(ran, vl, s);
	if (ran->conver == 's')
		ft_s_record(ran, vl, s);
	// if (ran->conver == 'p')
	// ft_p_record(str, ran, vl, s);
	if (ran->conver == 'd' || ran->conver == 'i')
		ft_d_record(ran, vl, s);
	// if (ran->conver == 'o')
	// 	ft_o_record(str, ran, vl, s;
	// if (ran->conver == 'u')
		// ft_u_record(str, ran, vl, s);
	if (ran->conver == 'x')
		ft_x_record(ran, vl, s);
	if (ran->conver == 'X')
		ft_X_record(ran, vl, s);
	// if (ran->conver == 'f')
	// 	ft_f_record(str, ran, vl, s);
}
