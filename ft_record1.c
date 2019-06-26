#include "ft_printf.h"

void	ft_c_record(t_ran *ran, va_list *vl, t_spec *s)
{
	char c;

	c = (char)(va_arg(*vl, int));

	if (c == '\0')
		ran->fzero++;
	if (s->width == 0)
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


void ft_sprint1(t_ran *ran, t_spec *s)
{


	if (s->width < len && (s->acc == 0 || s->acc == -1))
	{
		while (*str)
			ran->buf[ran->j++] = *str++;
	}
	if (s->width > len && s->minus == 0)
	{
		while(ran->j < s->width - len)
			ran->buf[ran->j++] = ' ';
		while (*str)
			ran->buf[ran->j++] = *str++;
	}
	if (s->width > len && s->minus == 1)
	{
		while (*str)
			ran->buf[ran->j++] = *str++;
		while(ran->j < s->width - len)
			ran->buf[ran->j++] = ' ';
	}
}



void	ft_bufjoin_s(t_ran *ran, t_spec *s)
{
	if (s->width == 0 && s->acc == 0)
		ft_sprint1(ran, s);
	if (s->width != 0 && s->acc == 0)
		ft_sprint2(ran, s);
	if (s->width == 0 && s->acc != 0)
		ft_sprint3(ran, s);
	if (s->width != 0 && s->acc != 0)
		ft_sprint4(ran, s);
}

void	ft_s_record(t_ran *ran, va_list *vl, t_spec *s)
{
	char	*str;
	char	*s_nul;
	int		len;

	s_nul = "(null)\0";
	str = (va_arg(*vl, char*));

	if (str == '\0')
		str = s_nul;
	len = ft_strlen(str);
	if (s->acc < len && s->acc != 0 && s->acc != -1 && str == s_nul)
		len = s->acc;
	ft_bufjoin_s(ran, s);
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
