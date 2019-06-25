/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 00:40:06 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/25 19:35:57 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long long int	num;
	int						sl;

	sl = 32;
	num = va_arg(*vl, unsigned long long int);
	if (s->flag == 0)
		ft_ui(s, ran, num, sl);
	else if (s->flag == 1)
		ft_usi(s, ran, num, sl);
	else if (s->flag == 2)
		ft_ucc(s, ran, num, sl);
	else if (s->flag == 3)
		ft_uli(s, ran, num, sl);
	else
		ft_ulli(s, ran, num, sl);
}

void	ft_X_record(t_ran *ran, va_list *vl, t_spec *s)
{
	unsigned long long int	num;
	int						bl;

	bl = 0;
	num = va_arg (*vl, unsigned long long int);
	if (s->flag == 0)
		ft_ui(s, ran, num, bl);
	else if (s->flag == 1)
		ft_usi(s, ran, num, bl);
	else if (s->flag == 2)
		ft_ucc(s, ran, num, bl);
	else if (s->flag == 3)
		ft_uli(s, ran, num, bl);
	else
		ft_ulli(s, ran, num, bl);
}

// void	ft_o_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }
//
// void	ft_u_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }

// void	ft_f_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
// 	if ()
//
// }
