/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:29:58 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/20 22:04:55 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		len;

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

void	*extend_buf(t_ran *ran)
{
	char *bufnew;

	ran->bs += 100;
	if (!(bufnew = (char *)malloc(sizeof(char) * ran->bs)))
		exit(-1);
	ft_bzero(bufnew, ran->bs);
	bufnew = ft_strcpy(bufnew, ran->buf);
	ft_strdel(&ran->buf);
	ran->buf = ft_strdup(bufnew);
	ft_strdel(&bufnew);
	return (ran->buf);
}

void	ft_reworkbuf(t_spec *spec)
{
	if (spec->buf)
		ft_strdel(&spec->buf);
	if (!(spec->buf = (char *)malloc(sizeof(char) * 1001)))
		exit(-1);
	ft_bzero(spec->buf, 1001);
}

void	ft_newstruct(t_spec *spec)
{
	spec->i = 0;
	spec->j = 0;
	spec->z = 0;
	spec->space = 0;
	spec->flag = 0;
	spec->zero = 0;
	spec->minus = 0;
	spec->plus = 0;
	spec->grid = 0;
	spec->pmz = 0;
	spec->width = 0;
	spec->acc = 0;
	spec->allflagzero = 0;
	if (!(spec->buf = (char *)malloc(sizeof(char) * 1001)))
		exit(-1);
	ft_bzero(spec->buf, 1001);
}
