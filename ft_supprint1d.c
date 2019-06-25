#include "ft_printf.h"

int			ft_checkdzero1(t_spec *s)
{
	if (s->space == 0 && s->width != 0 && s->plus == 1 && s->zero == 1)
	{
		s->buf[s->j++] = '+';
		while (s->j < s->width)
			s->buf[s->j++] = '0';
		return (1);
	}
	if (s->space == 0 && s->width != 0 && s->plus == 1 && s->zero == 0)
	{
		while (s->j < s->width - 2)
			s->buf[s->j++] = ' ';
		s->buf[s->j++] = '+';
		s->buf[s->j++] = '0';
		return (1);
	}
	return (0);
}

int			ft_checkdzero(t_spec *s, int n)
{
	if (n == 0 && (s->acc == 0 || s->acc != -1) && s->minus == 0)
	{
		if (s->space == 1 && s->width == 0 && s->zero == 0 && s->plus != 1)
		{
			s->buf[s->j++] = ' ';
			s->buf[s->j++] = '0';
			return (1);
		}
		if (s->space == 0 && s->width == 0 && s->zero == 0 && s->plus == 1)
		{
			s->buf[s->j++] = '+';
			s->buf[s->j++] = '0';
			return (1);
		}
		if (ft_checkdzero1(s) == 1)
				return (1);
	}
	return (0);
}

void	ft_bufjoin_d(t_ran *ran, t_spec *s)
{
	if (s->width == 0 && s->acc == 0)
		ft_print1(ran, s);
	if (s->width != 0 && s->acc == 0)
		ft_print2(ran, s);
	if (s->width == 0 && s->acc != 0)
		ft_print3(ran, s);
	if (s->width != 0 && s->acc != 0)
		ft_print4(ran, s);
}
