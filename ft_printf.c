/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:50:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/16 01:49:40 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checcon(char *str, int j, t_spec *spec)
{
	while (str[j] != '\0' && (str[j] != '%' && str[j] != 'c' && str[j] != 's'
		&& str[j] != 'p' && str[j] != 'd' && str[j] != 'i' && str[j] != 'o'
		&& str[j] != 'u' && str[j] != 'x' && str[j] != 'X' && str[j] != 'f'))
		j++;
	if (str[j] == '%' || str[j] == 'c' || str[j] == 's' || str[j] == 'p'
		|| str[j] == 'd' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u'
		|| str[j] == 'x' || str[j] == 'X' || str[j] == 'f')
		{
			(*spec).conver = str[j];
			return (0);
		}
	return (1);
}

int		checkiftext(char *str, int *i, t_spec *spec)
{
	int 		j;

	j = *i;
	//printf("1 %c 1", str[j]);
	if (str[j] != '%')
		return (1);
	else if (str[j] == '%')
	{
		j++;
		if (ft_checcon(str, j, spec) == 1)
			return(2);
	}
	return (0);
}

void		ft_printtext(char *str, va_list *vl, t_ran *ran)
{
	t_spec spec;
	ft_newstruct(&spec);
	while (str[(*ran).i] != '\0')
	{
		if (checkiftext(((char *)str), &(*ran).i, &spec) == 2)
			return ;
		else if (checkiftext(((char *)str), &(*ran).i, &spec) == 1)
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
	length = 0;
	va_start(vl, str);
	if (!(ran.buf = (char *)malloc(sizeof(char) * ran.bs)))
		return (-1);
	ft_bzero(ran.buf, ran.bs);
	ft_printtext((char *)str, &vl, &ran);
	length = ft_strlen(ran.buf);
	ft_putstr(ran.buf);
	ft_strdel(&ran.buf);
	va_end(vl);
	return (length);
}

int		main()
{
	ft_printf("%%%% 1\n");
	return (0);
}
