#include "ft_printf.h"

void ft_printwithwidth(t_ran *ran, t_spec *spec)
{
	int i;
	i = ft_strlen(spec->buf);
	while (i < spec->width && spec->minus == 0)
	{
		ran->buf[ran->j++] = ' ';
		i++;
	}
	if (ft_strlen(spec->buf) + ran->j < ran->bs && spec->minus == 0)
		ft_strjcpy(ran->buf, spec->buf, &ran->j);
	else if (spec->minus == 0)
	{
		extend_buf(ran);
		ft_strjcpy(ran->buf, spec->buf, &ran->j);
	}

	if (spec->minus == 1)
	{
		if(ft_strlen(spec->buf) + ran->j < ran->bs )
				ft_strjcpy(ran->buf, spec->buf, &ran->j);
		else
		{
			extend_buf(ran);
			ft_strjcpy(ran->buf, spec->buf, &ran->j);
		}
		while (i < spec->width)
		{
			ran->buf[ran->j++] = ' ';
			i++;
		}
	}
}

void	ft_print(t_ran *ran, t_spec *spec)
{
	if(ft_strlen(spec->buf) + ran->j < ran->bs )
		ft_strjcpy(ran->buf, spec->buf, &ran->j);
	else
	{
		extend_buf(ran);
		ft_strjcpy(ran->buf, spec->buf, &ran->j);
	}
}

void	ft_bufjoin_x(t_ran *ran, t_spec *spec)
{
	if (spec->flag == 0 && spec->width == 0 && spec->acc == 0)
		ft_print(ran, spec);
	if (spec->flag == 0 && spec->width != 0 && spec->acc == 0)
		ft_printwithwidth(ran, spec);

}

void	ft_convert1016(t_spec *spec, long int num)
{
	long int	remainder;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			spec->buf[j++] = 48 + remainder;
		else
			spec->buf[j++] = 55 + 32 + remainder;
		num = num / 16;
	}
	j--;
	while (i < j)
	{
		remainder = spec->buf[i];
		spec->buf[i++] = spec->buf[j];
		spec->buf[j--] = remainder;
	}

}

void	ft_x_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{
	long int num;

	num = va_arg (*vl, long int);
	if (num < 4294967296)
	{
		if (num > 0)
		{
			ft_convert1016(spec, num);
			ft_bufjoin_x(ran, spec);
		}
		else if (num < 0)
		{

		}
		else
		{
			ran->buf[ran->j++] = num + 48;
			ran->buf[ran->j] = '\0';
			while (str[ran->i] != ran->conver)
				ran->i++;
		}
	}
	else
	{
		ran->buf[ran->j++] = num + 48;
		ran->buf[ran->j] = '\0';
		while (str[ran->i] != ran->conver)
			ran->i++;
	}
}


// void	ft_o_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }
//
// void	ft_u_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }
//

void	ft_bufjoin_X(t_ran *ran, t_spec *spec)
{
	if (spec->flag == 0 && spec->width == 0 && spec->acc == 0)
		ft_print(ran, spec);
	if (spec->flag == 0 && spec->width != 0 && spec->acc == 0)
		ft_printwithwidth(ran, spec);
}

void	ft_convertX1016(t_spec *spec, long int num)
{
	long int	remainder;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			spec->buf[j++] = 48 + remainder;
		else
			spec->buf[j++] = 55 + remainder;
		num = num / 16;
	}
	j--;
	while (i < j)
	{
		remainder = spec->buf[i];
		spec->buf[i++] = spec->buf[j];
		spec->buf[j--] = remainder;
	}
}

void	ft_X_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{
	long int num;

	num = va_arg (*vl, long int);
	if (num < 4294967296)
	{
		if (num > 0)
		{
			ft_convertX1016(spec, num);
			ft_bufjoin_X(ran, spec);
		}
		else if (num < 0)
		{

		}
		else
		{
			ran->buf[ran->j++] = num + 48;
			ran->buf[ran->j] = '\0';
			while (str[ran->i] != ran->conver)
				ran->i++;
		}
	}
	else
	{
		ran->buf[ran->j++] = '0';
		ran->buf[ran->j] = '\0';
		while (str[ran->i] != ran->conver)
			ran->i++;
	}
}
//
// void	ft_f_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }
