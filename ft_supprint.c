/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:34:11 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/21 02:15:53 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkgrid(t_ran *ran, t_spec *spec)
{
	if (spec->grid == 1 && ran->conver == 'x' && spec->buf[0] != '0')
	{
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'x';
	}
	else if (spec->grid == 1 && ran->conver == 'X' && spec->buf[0] != '0')
	{
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j++] = 'X';
	}
}
