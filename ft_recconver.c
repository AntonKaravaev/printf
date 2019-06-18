/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recconver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:00:40 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/18 11:39:28 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int ft_findacc(char *str, t_ran *ran, t_spec *spec)
// {
// 	int z;
//
// 	z = 0;
// 	if (str[(*ran).i] >= '1' && str[(*ran).i] <= '9')
// 	{
// 		(*spec).buf_acc[z++] = str[(*ran).i++];
// 		while (str[(*ran).i] >= '0' && str[(*ran).i] <= '9')
// 			(*spec).buf_acc[z++] = str[(*ran).i++];
// 		if (str[(*ran).i] == (*ran).conver)
// 		{
// 			(*spec).acc = ft_atoi((*spec).buf_acc);
// 			return (1);
// 		}
// 		else
// 		{
// 			ft_bzero((*spec).buf_acc, 1001);\
// 			z = 0;
// 		}
// 	}
// 	return (0);
//
// }

// int ft_findwidth(char *str, t_ran *ran, t_spec *spec)
// {
// 	int z;
//
// 	z = 0;
// 	if (str[(*ran).i] >= '1' && str[(*ran).i] <= '9')
// 	{
// 		(*spec).buf_width[z++] = str[(*ran).i++];
// 		while (str[(*ran).i] >= '0' && str[(*ran).i] <= '9')
// 			(*spec).buf_width[z++] = str[(*ran).i++];
// 		if (str[(*ran).i] == (*ran).conver)
// 		{
// 			(*spec).width = ft_atoi((*spec).buf_width);
// 			return (1);
// 		}
// 		else if (str[(*ran).i] == '.')
// 		{
// 			if (ft_findacc(str, ran, spec) == 1)
// 			{
// 				(*spec).width = ft_atoi((*spec).buf_width);
// 				return (1);
// 			}
// 			else
// 			{
// 				ft_bzero((*spec).buf_width, 1001);
// 				z = 0;
// 			}
// 		}
// 		else
// 		{
// 			ft_bzero((*spec).buf_width, 1001);
// 			z = 0;
// 		}
// 	}
// 	return (0);
//
// }

void ft_procwidth(char *str, t_ran *ran, t_spec *spec)
{
	int z;

	while (str[(*ran).i] != (*ran).conver)
	{
		if (str[(*ran).i] >= '1' && str[(*ran).i] <= '9')
		{
			z = 0;
			ft_bzero((*spec).buf_width, 1001);
			(*spec).buf_width[z++] = str[(*ran).i++];
			while (str[(*ran).i] >= '0' && str[(*ran).i] <= '9')
				(*spec).buf_width[z++] = str[(*ran).i++];
			if (str[(*ran).i] == (*ran).conver)
			{
				(*spec).width = ft_atoi((*spec).buf_width);
				return;
			}
			else
			{
				(*spec).width = ft_atoi((*spec).buf_width);
				(*ran).i--;
			}
		}
	(*ran).i++;
	}
}


// void ft_findflags(char *str, t_ran *ran, t_spec *spec)
// {
// 	int z;
//
// 	z = 0;
// 	while (str[(*ran).i] != (*ran).conver)
// 	{
// 		ft_easyflag(str, ran, spec);
// 		if (str[(*ran).i] == '.')
// 		{
// 			if (ft_findacc(str, ran, spec) == 1)
// 				return ;
// 		}
// 		if (str[(*ran).i] >= '1' && str[(*ran).i] <= '9')
// 			ft_findwidth(str, ran, spec);
// 	(*ran).i++;
// 	}
// }



void ft_recconver(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{
	if ((*ran).conver == '%')
	{
		ft_procwidth(str, ran, spec);
		ft_strdel(&(*spec).buf_width);
		ft_p_record(str, ran, spec);
	}
	// if ((*ran).conver == 'c')
	// ft_c_record(str, ran, vl, spec);
	// if ((*ran).conver == 's')
	// ft_s_record(str, ran, vl, spec);
	// if ((*ran).conver == 'p')
	// ft_p_record(str, ran, vl, spec);
	if ((*ran).conver == 'd')
		ft_d_record(str, ran, vl, spec);
	// if ((*ran).conver == 'i')
	// 	ft_i_record(str, ran, vl, spec);
	// if ((*ran).conver == 'o')
	// 	ft_o_record(str, ran, vl, spec);
	// if ((*ran).conver == 'u')
		// ft_u_record(str, ran, vl, spec);
	if ((*ran).conver == 'x')
		ft_x_record(str, ran, vl, spec);
	// if ((*ran).conver == 'X')
	// 	ft_X_record(str, ran, vl, spec);
	// if ((*ran).conver == 'f')
	// 	ft_f_record(str, ran, vl, spec);
	ft_newstruct(spec);
}
