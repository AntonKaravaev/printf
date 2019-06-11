/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:50:48 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/11 22:29:02 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check1(char *str, int i)
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

int     ft_printf(const char *restrict str, ...)
{
  /*
    char  *str;
    char  *buf;
    int   i;
    va_list vl;

    va_start(vl, format);
    str = (char *)format;
    i = 0;
    if (!(buf = (char *)malloc(sizeof(char) * 1001)))
    return (-1);
    ft_bzero(buf, 1001);
    while (str[i] != '\0')
    {
    if (str[i] != '%')
    {
    buf[i] = str[i];
    }
    else
    {
    ft_putstr("Attention");
    return (0);
    }
    i++;
    }
    ft_putstr(buf);
    va_end(vl);
  */
	int				i;
	int				j;
	int				buf_size;
	char			*buf;
	char			*bufnew;
	va_list			vl;

	i = 0;
	j = 0;
	buf_size = 101;
	va_start(vl, str);
	if (!(buf = (char *)malloc(sizeof(char) * buf_size)))
		return (-1);
	ft_bzero(buf, buf_size);
	while (str[i] != '\0')
	{
		if (check1(((char *)str), i) == 1)
		{
			if (j < buf_size)
				buf[j] = str[i];
			else
			{
				buf_size += 100;
				if (!(bufnew = (char *)malloc(sizeof(char) * buf_size)))
					return (-1);
				ft_bzero(buf, buf_size);
				bufnew = ft_strcpy(bufnew, buf);
				ft_strdel(&buf);
				buf = ft_strdup(bufnew);
				ft_strdel(&bufnew);
				buf[j] = str[i];
			}
			j++;
		}
		i++;
	}
	printf("Buf checker = %s\n",buf);
	va_end(vl);
	return (i);
}

int		main()
{
  int i;
  i = 0;

  i = ft_printf("%%hjshgkh%%%%%%dsd");
  printf("That's how many chars printed = %d\n", i);
  return (0);
}
