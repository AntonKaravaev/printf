/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:54:21 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/29 15:08:21 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_record(t_ran *ran, va_list *vl, t_spec *s)
{
	char c;

	c = (char)(va_arg(*vl, int));
	if (c == '\0')
		ran->fzero++;
	if (s->width == 0)
		ran->buf[ran->j++] = c;
	if (s->width > 0 && s->minus == 1)
	{
		ran->buf[ran->j++] = c;
		while (s->width-- > 1)
			ran->buf[ran->j++] = ' ';
	}
	if (s->width > 0 && s->minus == 0)
	{
		while (s->width-- > 1)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = c;
	}
}

void	ft_s_record(t_ran *ran, va_list *vl, t_spec *s)
{
	char *str;

	ft_strdel(&s->buf);
	str = (va_arg(*vl, char*));
	if (str == '\0')
	{
		s->buf = ft_strdup("(null)\0");
		s->grid = 1;
	}
	else
		s->buf = ft_strdup(str);
	s->strl = ft_strlen(s->buf);
	str = NULL;
	ft_bufjoin_s(ran, s);
}

void	ft_pc_record(char *str, t_ran *ran, t_spec *s)
{
	ft_procwidth(str, ran, s);
	if (s->minus == 1)
	{
		ran->buf[ran->j++] = str[ran->i];
		while (s->width > 1)
		{
			ran->buf[ran->j++] = ' ';
			s->width--;
		}
		return ;
	}
	while (s->width > 1)
	{
		ran->buf[ran->j++] = ' ';
		s->width--;
	}
	ran->buf[ran->j++] = str[ran->i];
}

void	ft_p_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long long int	num;
	int						sl;

	sl = 32;
	num = va_arg(*vl, unsigned long long int);
	ft_uli(s, ran, num, sl);
}

void	ft_d_record(t_ran *ran, va_list *vl, t_spec *s)
{
	long long int	num;

	ran->conver = 'd';
	s->i = 0;
	s->j = 0;
	num = va_arg(*vl, long long int);
	if (num == 0)
	{	s->z = 1; // показывает, что наше число ноль
		if (s->plus == 1)
		{
			s->buf[0] = '+';
			s->buf[1] = 48;
		}
		else
			s->buf[0] = 48;
		ft_bufjoin_d(ran, s);
		return ;
	}
	if (s->flag == 0)
		ft_di(s, ran, (int)num);
	else if (s->flag == 1)
		ft_dsi(s, ran, (short int)num);
	else if (s->flag == 2)
		ft_dc(s, ran, (char)num);
	else if (s->flag == 3)
		ft_dli(s, ran, (long int)num);
	else
		ft_dlli(s, ran, (long long int)num);
}
