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

void	ft_sprint4(t_ran *ran, t_spec *s)
{
	if (s->grid == 1 && s->acc == -1)
	{
		while (s->width > 0)
		{
			ran->buf[ran->j++] = ' ';
			s->width--;
		}
		return;
	}
	if (s->width >= s->acc)
	{
		if (s->minus == 0)
		{
			if (s->strl <= s->acc)
			{
				while (s->i < s->width - s->strl)
				{
					ran->buf[ran->j++] = ' ';
					s->i++;
				}
				while ((s->j + s->i) < s->width)
					ran->buf[ran->j++] = s->buf[s->j++];
			}
			else
			{
				while (s->i < s->width - s->acc)
				{
					ran->buf[ran->j++] = ' ';
					s->i++;
				}
				while (s->j + s->i < s->width)
					ran->buf[ran->j++] = s->buf[s->j++];
			}
		}
		else if (s->minus == 1)
		{
			if (s->strl <= s->acc)
			{
				while (s->j < s->strl)
					ran->buf[ran->j++] = s->buf[s->j++];
				while (s->j < s->width)
				{
					ran->buf[ran->j++] = ' ';
					s->j++;
				}
			}
			else
			{
				while (s->j < s->acc)
					ran->buf[ran->j++] = s->buf[s->j++];
				while (s->j < s->width)
				{
					ran->buf[ran->j++] = ' ';
					s->j++;
				}

			}
		}
	}
	else
	{
		if (s->strl <= s->acc)
		{
			while (s->j < s->strl)
				ran->buf[ran->j++] = s->buf[s->j++];
		}
		else
		{
			while (s->j < s->acc)
				ran->buf[ran->j++] = s->buf[s->j++];
		}
	}
}

void	ft_sprint3(t_ran *ran, t_spec *s)
{
	if (s->acc == -1 || s->acc == -1)
		return;
	if (s->strl <= s->acc || s->acc == -1 || s->acc == -1)
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
	else
	{
		while(s->acc)
		{
			ran->buf[ran->j++] = s->buf[s->j++];
			s->acc--;
		}
	}
}

void	ft_sprint2(t_ran *ran, t_spec *s)
{
	if (s->width <= s->strl)
	{
	while (s->buf[s->j])
		ran->buf[ran->j++] = s->buf[s->j++];
	}
	else
	{
		if (s->minus == 1)
		{
			while (s->buf[s->j])
				ran->buf[ran->j++] = s->buf[s->j++];
			while (s->strl < s->width)
			{
				ran->buf[ran->j++] = ' ';
				s->strl++;
			}
		}
		else
		{
			while (s->strl < s->width)
			{
				ran->buf[ran->j++] = ' ';
				s->strl++;
			}
			while (s->buf[s->j])
				ran->buf[ran->j++] = s->buf[s->j++];
		}
	}
}
void	ft_sprint1(t_ran *ran, t_spec *s)
{
		while (s->buf[s->j])
			ran->buf[ran->j++] = s->buf[s->j++];
}



void	ft_bufjoin_s(t_ran *ran, t_spec *s)
{
		s->i = 0;
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
	char 	*str;

	ft_strdel(&s->buf);
	str = (va_arg(*vl, char*));
	if (str == '\0')
	{
		s->buf = ft_strdup("(null)\0");
		s->grid = 1;
	}

	else
		s->buf = ft_strdup(str);
	s->strl = ft_strlen(s->buf);
	str = NULL;
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
