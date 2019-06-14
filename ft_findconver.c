/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findconver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:40 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/14 15:20:51 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_recconver(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{
	if ((*spec).conver == 'c')
		ft_c_record(str, ran, vl, spec);
	if ((*spec).conver == 's')
		ft_s_record(str, ran, vl, spec);
	if ((*spec).conver == 'p')
		ft_p_record(str, ran, vl, spec);
	if ((*spec).conver == 'd')
		ft_d_record(str, ran, vl, spec);
	if ((*spec).conver == 'i')
		ft_i_record(str, ran, vl, spec);
	if ((*spec).conver == 'o')
		ft_o_record(str, ran, vl, spec);
	if ((*spec).conver == 'u')
		ft_u_record(str, ran, vl, spec);
	if ((*spec).conver == 'x')
		ft_x_record(str, ran, vl, spec);
	if ((*spec).conver == 'X')
		ft_X_record(str, ran, vl, spec);
	if ((*spec).conver == 'f')
		ft_f_record(str, ran, vl, spec);
}

void	ft_findconver(char *str, t_ran *ran, va_list *vl)
{
	int		i;
	t_spec	spec;

	i = (*ran).i;
	while (str[i] != '\0' &&  str[i] != '%')
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'x'
			|| str[i] == 'X' || str[i] == 'f')
		{
			spec.conver = str[i];
			ft_recconver(str, ran, vl, &spec);
			return ;
		}
		i++;
	}
	if (str[i] != '\0' ||  str[i] != '%')
		exit(-1);
}
