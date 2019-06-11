/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:09:08 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/11 21:27:52 by crenly-b         ###   ########.fr       */
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

void	ft_bzero(void *s, size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i  < size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strcpy(char *dest, char *src)
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

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
