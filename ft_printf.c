/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:50:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/14 20:38:00 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkiftext(char *str, int i)
{
	static int	flag;

	if (i == 0)
		flag = 0;
	if (str[i] != '%')
		return (1);

	else if (flag == 0 && str[i] == '%' && str[i + 1] == '%')
	{
		flag = 1;
		return (1);
	}
	else
		flag = 0;
	return (0);
}

int		ft_printtext(char *str, va_list *vl, t_ran *ran)
{
	while (str[(*ran).i] != '\0')
	{
		if (checkiftext(((char *)str), (*ran).i) == 1)
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
			ft_findconver(((char *)str), ran, vl);
			(*ran).i++;
		}
	}
	ft_putstr((*ran).buf);
	return (1);
}

int     ft_printf(const char *restrict str, ...)
{
	va_list		vl;
	t_ran 		ran;

	ran.i = 0;
	ran.j = 0;
	ran.bs = 101;
	va_start(vl, str);
	if (!(ran.buf = (char *)malloc(sizeof(char) * ran.bs)))
		return (-1);
	ft_bzero(ran.buf, ran.bs);
	if (ft_printtext((char *)str, &vl, &ran) != 1)
		{
			ft_strdel(&ran.buf);
			return (-1);
		}
	va_end(vl);
	return (ft_strlen(ran.buf));
}

int		main()
{
	int i;
	i = 0;

	i = ft_printf("Hello%d %d\n", 21, 145);
	// ft_printf("=%d\n", 123456);
	// ft_printf(" %d \n", -21);
	printf("m%d\n", i);
	// printer = printf("Hello%d \n", 21);
	// printf("p%d\n", printer);
	return (0);
}
