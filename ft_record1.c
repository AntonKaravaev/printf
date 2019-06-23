#include "ft_printf.h"

// void	ft_bufjoin_d(char *str, t_ran *ran, t_spec *s, int num)
// {
//
// }

// void	ft_c_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {

// }


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
	unsigned long long int	num;
	int						bl;

	bl = 0;
	num = va_arg (*vl, unsigned long long int);
	s->buf = ft_itoa(num);
	ft_bufjoin_x(ran, s);
	// if (s->flag == 0)
	// 	ft_dui(s, ran, num, bl);
	// else if (s->flag == 1)
	// 	ft_dusi(s, ran, num, bl);
	// else if (s->flag == 2)
	// 	ft_ducc(s, ran, num, bl);
	// else if (s->flag == 3)
	// 	ft_duli(s, ran, num, bl);
	// else
	// 	ft_dulli(s, ran, num, bl);
}

// void	ft_i_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }
