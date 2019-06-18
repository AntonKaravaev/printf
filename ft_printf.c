/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:50:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/18 02:11:17 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_easyflag(char *str, t_spec *spec, int j)
{
	if (str[j] == '-')
		(*spec).minus = 1;
	if (str[j] == '+')
		(*spec).plus = 1;
	if (str[j] == '0')
		(*spec).plus = 1;
	if (str[j] == '#')
		(*spec).plus = 1;
}

int		ft_checcon(char *str, int j, t_spec *spec, t_ran *ran)
{
	while (str[j] != '\0' && str[j] != '%' && str[j] != 'c' && str[j] != 's'
		&& str[j] != 'p' && str[j] != 'd' && str[j] != 'i' && str[j] != 'o'
		&& str[j] != 'u' && str[j] != 'x' && str[j] != 'X' && str[j] != 'f'
		&& str[j] != '\n' && str[j] != '\t' && str[j] != '\v')
	{
		ft_easyflag(str, spec, j);
		j++;
	}
	if (str[j] == '\n' || str[j] == '\t' || str[j] == '\v')
	{
		(*ran).i = j;
		return (1);
	}
	if (str[j] == '%' || str[j] == 'c' || str[j] == 's' || str[j] == 'p'
		|| str[j] == 'd' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u'
		|| str[j] == 'x' || str[j] == 'X' || str[j] == 'f')
		{
			(*ran).conver = str[j];
			return (0);
		}
	(*ran).ret = 1;
	return (0);
}

int		checkiftext(char *str, t_ran *ran, t_spec *spec)
{
	int 		j;

	j = (*ran).i;
	if (str[j] != '%')
		return (1);
	if (str[j] == '%' && str[j + 1] == '%')
	{
		(*ran).i++;
		return (1);
	}
	else if (str[j] == '%')
	{
		j++;
		if (ft_checcon(str, j, spec, ran) == 1)
			return(1);
	}
	return (0);
}

void		ft_start(char *str, va_list *vl, t_ran *ran)
{
	t_spec spec;

	ft_newstruct(&spec);
	while (str[(*ran).i] != '\0')
	{
		if (checkiftext(((char *)str), ran, &spec) == 1)
		{
			if ((*ran).j < (*ran).bs)
				(*ran).buf[(*ran).j++] = str[(*ran).i++];
			else
			{
				extend_buf(ran);
				(*ran).buf[(*ran).j++] = str[(*ran).i++];
			}
		}
		else
		{
			if ((*ran).ret == 1)
					return ;
			(*ran).i++;
			ft_recconver(((char *)str), ran, vl, &spec);
			(*ran).i++;
		}
	}
}

int     ft_printf(const char *restrict str, ...)
{
	va_list		vl;
	t_ran 		ran;
	int			length;

	ran.i = 0;
	ran.j = 0;
	ran.bs = 101;
	ran.ret = 0;
	length = 0;
	va_start(vl, str);
	if (!(ran.buf = (char *)malloc(sizeof(char) * ran.bs)))
		return (-1);
	ft_bzero(ran.buf, ran.bs);
	ft_start((char *)str, &vl, &ran);
	length = ft_strlen(ran.buf);
	ft_putstr(ran.buf);
	ft_strdel(&ran.buf);
	va_end(vl);
	return (length);
}

// int		main()
// {
//
// 	ft_printf("%-5 %%\n");
//
// 	return (0);
// }
