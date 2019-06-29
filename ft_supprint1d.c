#include "ft_printf.h"

void	ft_dznak1(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		// s->i++; // or not ++
		s->j++;
		s->strl--; //yes or no
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';

		s->j++;
		s->strl--;
		//s->i++;
	}
}

void	ft_dznak2(t_spec *s)
{
	if (s->pmz == -1 || s->plus == 1)
		s->i++;
	if (s->pmz == -1)
	{
		s->j++;
	}
}

void	ft_dznak3(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		s->acc++;
		ran->buf[ran->j++] = '-';
	}
	else if (s->plus == 1)
	{
		s->strl--;
		s->j++;
		ran->buf[ran->j++] = '+';
	}

}

void	ft_dznak4(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		s->strl--; //yes or no
		s->i++;
		s->j++;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->strl--;
		s->i++;
		s->j++;
	}
}

void	ft_dznak5(t_ran *ran, t_spec *s)
{
	if (s->pmz == -1)
	{
		ran->buf[ran->j++] = '-';
		if (s->acc > s->strl)
			s->strl--;
		else
			s->i++;
		s->j++;
	}
	else if (s->plus == 1)
	{
		ran->buf[ran->j++] = '+';
		s->strl--;
		s->j++;
	}
}

void	ft_dprint4(t_ran *ran, t_spec *s)
{
	if (s->acc == -1 && s->z == 1)
	{
		if (s->plus && s->minus)
		{
			ran->buf[ran->j++] = '+';
			s->width--;
		}
		else if (s->plus)
			s->width--;
		while (s->width--)
			ran->buf[ran->j++] = ' ';
		if (s->plus && !s->minus)
			ran->buf[ran->j++] = '+';
		return ;
	}
	if (s->minus == 0)
	{
		if (s->width <= s->acc)
		{
			ft_dznak1(ran, s);
			if(s->acc <= s->strl)
			{
				while (s->i < s->strl)
				{
					ran->buf[ran->j++] = s->buf[s->j++];
					s->i++;
				}
			}
			else
			{
				while (s->i < s->acc - s->strl)
				{
					ran->buf[ran->j++] = '0';
					s->i++;
				}
				while (s->i < s->acc)
				{
					ran->buf[ran->j++] = s->buf[s->j++];
					s->i++;
				}
			}
		}
		else
		{
				if (s->strl <= s->acc)
				{
					ft_dznak2(s);
					while (s->i < s->width - s->acc)
					{
						ran->buf[ran->j++] = ' ';
						s->i++;
					}
					ft_dznak3(ran, s);
					while (s->acc - s->strl++)
					{
						ran->buf[ran->j++] = '0';
						s->i++;
					}
					while (s->i++ < s->width)
						ran->buf[ran->j++] = s->buf[s->j++];

				}
				else
				{
					while (s->i++ < s->width - s->strl)
						ran->buf[ran->j++] = ' ';
					while (s->strl--)
						ran->buf[ran->j++] = s->buf[s->j++];
				}
		}
	}
	else
	{
		if (s->width <= s->acc)
		{
			ft_dznak5(ran, s);
			if (s->acc <= s->strl)
			{
				while (s->i++ < s->strl)
					ran->buf[ran->j++] = s->buf[s->j++];
			}
			else
			{
				while (s->acc > s->strl++)
				{
					ran->buf[ran->j++] = '0';
					s->i++;
				}
				while (s->i++ < s->acc)
					ran->buf[ran->j++] = s->buf[s->j++];
			}
		}
		else
		{
			ft_dznak4(ran, s);
			if (s->acc <= s->strl)
			{
				while (s->strl--)
				{
					ran->buf[ran->j++] = s->buf[s->j++];
					s->i++;
				}
				while (s->i++ < s->width)
					ran->buf[ran->j++] = ' ';
			}
			else
			{
				while (s->acc - s->strl++)
				{
					ran->buf[ran->j++] = '0';
					s->i++;
				}
				while (s->buf[s->j])
				{
					ran->buf[ran->j++] = s->buf[s->j++];
					s->i++;
				}

				while (s->i++ < s->width)
				{
					ran->buf[ran->j++] = ' ';
					s->j++;
				}

			}
		}
	}
}

void	ft_dprint3(t_ran *ran, t_spec *s)
{

	if (s->acc == -1 && s->z == 1)
	{
		if (s->plus)
			ran->buf[ran->j++] = '+';
		return;
	}
	if (s->acc <= s->strl)
	{
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
	{
		ft_dznak1(ran, s);
		while (s->acc-- > s->strl)
			ran->buf[ran->j++] = '0';
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
	}
}

void	ft_dprint2(t_ran *ran, t_spec *s)
{
	if (s->z == 1)
	{
		if (s->allflagzero)
		{
			while (s->i < s->width - 1)
			{
				ran->buf[ran->j++] = ' ';
				s->i++;
			}
			ran->buf[ran->j++] = '0';
			return ;
		}
		else if (s->minus)
		{
			ran->buf[ran->j++] = '0';
			s->i++;
			while (s->i++ < s->width)
				ran->buf[ran->j++] = ' ';
			return ;
		}
		else if (s->plus && !s->space)
		{
			while (s->width-- - 2)
				ran->buf[ran->j++] = ' ';
			ran->buf[ran->j++] = '+';
			ran->buf[ran->j++] = '0';
			return ;
		}
		else if (s->plus)
		{
			ran->buf[ran->j++] = '+';
			s->width--;
			s->i++;
		}
		else if (s->space)
		{

			while (s->i < s->width - 1)
			{
				ran->buf[ran->j++] = ' ';
				s->i++;
			}
		}
		while (s->i < s->width)
		{
			ran->buf[ran->j++] = '0';
			s->i++;
		}

		return;
	}
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
	if (s->width == 0 && s->acc != 0)
		ft_dprint3(ran, s);
	if (s->width != 0 && s->acc != 0)
		ft_dprint4(ran, s);
}
