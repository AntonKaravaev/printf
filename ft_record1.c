#include "ft_printf.h"

void	ft_c_record(t_ran *ran, va_list *vl, t_spec *s)
{
	char c;

	c = (char)(va_arg(*vl, int));

	if (c == '\0')
		ran->fzero++;
	if (s->width == 0 && (s->acc == 0 || s->acc == -1))
			ran->buf[ran->j++] = c;

	if (s->width > 0 && s->minus == 1)
	{
		ran->buf[ran->j++] = c;
		while (s->width-- > 1)
			ran->buf[ran->j++] = ' ';

	}

	if (s->width > 0 && s->minus == 0)
	{
		while (s->width-- > 1)
			ran->buf[ran->j++] = ' ';
		ran->buf[ran->j++] = c;
	}
}


void	ft_p_record(char *str, t_ran *ran, t_spec *s)
{
	ft_procwidth(str, ran, s);
	if (s->minus == 1)
	{

		ran->buf[ran->j++] = str[ran->i];
		while(s->width > 1)
		{
			ran->buf[ran->j++] = ' ';
			s->width--;
		}
		return ;
	}
	while(s->width > 1)
	{
		ran->buf[ran->j++] = ' ';
		s->width--;
	}
	ran->buf[ran->j++] = str[ran->i];

}

void	ft_d_record(t_ran *ran, va_list *vl, t_spec *s)
{
	long long int	num;

	ran->conver = 'd';
	num = va_arg (*vl, long long int);
	if (s->flag == 0)
		ft_dui(s, ran, num);
	else if (s->flag == 1)
		ft_dusi(s, ran, num);
	else if (s->flag == 2)
		ft_ducc(s, ran, num);
	else if (s->flag == 3)
		ft_duli(s, ran, num);
	else
		ft_dulli(s, ran, num);
}
