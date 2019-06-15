/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findconver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:40 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/16 01:03:28 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_recconver(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{
	// if ((*spec).conver == 'c')
	// 	ft_c_record(str, ran, vl, spec);
	if ((*spec).conver == '%')
		ft_proc_record(str, ran, spec);
	// if ((*spec).conver == 's')
	// 	ft_s_record(str, ran, vl, spec);
	// if ((*spec).conver == 'p')
	// 	ft_p_record(str, ran, vl, spec);
	if ((*spec).conver == 'd')
		ft_d_record(str, ran, vl, spec);
	// if ((*spec).conver == 'i')
	// 	ft_i_record(str, ran, vl, spec);
	// if ((*spec).conver == 'o')
	// 	ft_o_record(str, ran, vl, spec);
	// if ((*spec).conver == 'u')
	// 	ft_u_record(str, ran, vl, spec);
	// if ((*spec).conver == 'x')
	// 	ft_x_record(str, ran, vl, spec);
	// if ((*spec).conver == 'X')
	// 	ft_X_record(str, ran, vl, spec);
	// if ((*spec).conver == 'f')
	// 	ft_f_record(str, ran, vl, spec);
}
