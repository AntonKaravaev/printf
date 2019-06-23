/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:29:58 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/23 23:32:43 by crenly-b         ###   ########.fr       */
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

void	ft_reworkbuf(t_spec *s)
{
	if (s->buf)
		ft_strdel(&s->buf);
	if (!(s->buf = (char *)malloc(sizeof(char) * 1001)))
		exit(-1);
	ft_bzero(s->buf, 1001);
}

void	ft_newstruct(t_spec *s)
{
	s->i = 0;
	s->j = 0;
	s->z = 0;
	s->space = 0;
	s->flag = 0;
	s->zero = 0;
	s->minus = 0;
	s->plus = 0;
	s->grid = 0;
	s->pmz = 0;
	s->width = 0;
	s->acc = 0;
	s->allflagzero = 0;
	if (!(s->buf = (char *)malloc(sizeof(char) * 1001)))
		exit(-1);
	ft_bzero(s->buf, 1001);
}
