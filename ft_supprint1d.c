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

void	ft_dprint2(t_ran *ran, t_spec *s)
{
	if (s->minus == 0)
	{
		if (s->width <= s->strl)
		{
			while (s->strl--)
				ran->buf[ran->j++] = s->buf[s->j++];

		}
		else if (s->zero == 0)
		{
			while (s->i < s->width - s->strl)
			{
				ran->buf[ran->j++] = ' ';
				s->i++;
			}
			while (s->i++ < s->width)
				ran->buf[ran->j++] = s->buf[s->j++];
		}
		else
		{
			if (s->pmz == -1 || s->pmz == 1)
			{
				ran->buf[ran->j++] = s->buf[0];
				s->j++;
				s->i++;
				s->strl--;
			}
			while (s->i < s->width - s->strl)
			{
				ran->buf[ran->j++] = '0';
				s->i++;
			}
			while (s->i++ < s->width)
				ran->buf[ran->j++] = s->buf[s->j++];
		}
	}
	else
	{
		if (s->width <= s->strl)
		{
			while (s->strl--)
				ran->buf[ran->j++] = s->buf[s->j++];

		}
		else
		{
			while (s->j < s->strl)
				ran->buf[ran->j++] = s->buf[s->j++];
			while (s->j < s->width)
			{
				ran->buf[ran->j++] = ' ';
				s->j++;
			}
		}
	}
}

void	ft_dprint1(t_ran *ran, t_spec *s)
{
	if (s->space == 1 && s->minus == 0 && s->plus == 0 && s->zero == 0
		&& s->grid == 0 && s->pmz != -1)
		ran->buf[ran->j++] = ' ';
	while (s->buf[s->j])
		ran->buf[ran->j++] = s->buf[s->j++];
}

void	ft_bufjoin_d(t_ran *ran, t_spec *s)
{
	s->i = 0;
	s->j = 0;
	s->strl = ft_strlen(s->buf);
	if (s->width == 0 && s->acc == 0)
		ft_dprint1(ran, s);
	if (s->width != 0 && s->acc == 0)
		ft_dprint2(ran, s);
	// if (s->width == 0 && s->acc != 0)
	// 	ft_dprint3(ran, s);
	// if (s->width != 0 && s->acc != 0)
	// 	ft_dprint4(ran, s);
}
