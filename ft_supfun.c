/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:28:26 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/24 00:41:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (save);
}
