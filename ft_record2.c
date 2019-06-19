#include "ft_printf.h"

void ft_print3(t_ran *ran, t_spec *spec)
{
	int i;

	i = ft_strlen(spec->buf);
	while (i < spec->width && spec->minus == 0)
	{
		ran->buf[ran->j++] = '0';
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

void ft_print2(t_ran *ran, t_spec *spec)
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

void	ft_print1(t_ran *ran, t_spec *spec)
{
	if (ft_strlen(spec->buf) + ran->j < ran->bs )
		ft_strjcpy(ran->buf, spec->buf, &ran->j);
	else
	{
		extend_buf(ran);
		ft_strjcpy(ran->buf, spec->buf, &ran->j);
	}
}

void	ft_bufjoin_x(t_ran *ran, t_spec *spec)
{
	if (spec->width == 0 && spec->acc == 0)
		ft_print1(ran, spec);
	if (spec->width != 0 && spec->acc == 0 && spec->zero == 0)
		ft_print2(ran, spec);
	if (spec->width != 0 && spec->acc == 0 && spec->zero == 1)
		ft_print3(ran, spec);
}

void	ft_x_record(t_ran *ran, va_list *vl, t_spec *spec)
{
	unsigned long long int	num;
	int						sl;

	sl = 32;
	num = va_arg (*vl, unsigned long long int);
	if (spec->flag == 0)
		ft_ui(spec, ran, num, sl);
	else if (spec->flag == 1)
		ft_usi(spec, ran, num, sl);
	else if (spec->flag == 2)
		ft_ucc(spec, ran, num, sl);
	else if (spec->flag == 3)
		ft_uli(spec, ran, num, sl);
	else
		ft_ulli(spec, ran, num, sl);
}

void	ft_X_record(t_ran *ran, va_list *vl, t_spec *spec)
{
	unsigned long long int	num;
	int						bl;

	bl = 0;
	num = va_arg (*vl, unsigned long long int);
	if (spec->flag == 0)
		ft_ui(spec, ran, num, bl);
	else if (spec->flag == 1)
		ft_usi(spec, ran, num, bl);
	else if (spec->flag == 2)
		ft_ucc(spec, ran, num, bl);
	else if (spec->flag == 3)
		ft_uli(spec, ran, num, bl);
	else
		ft_ulli(spec, ran, num, bl);
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

// void	ft_bufjoin_X(t_ran *ran, t_spec *spec)
// {
// 	if (spec->flag == 0 && spec->width == 0 && spec->acc == 0)
// 		ft_print(str, ran, spec);
// 	if (spec->flag == 0 && spec->width != 0 && spec->acc == 0)
// 		ft_printwithwidth(, ran, spec);
// }
//
// void	ft_convertX1016(t_spec *spec, long int num)
// {
// 	long int	remainder;
// 	int			i;
// 	int			j;
//
// 	i = 0;
// 	j = 0;
// 	while (num != 0)
// 	{
// 		remainder = num % 16;
// 		if (remainder < 10)
// 			spec->buf[j++] = 48 + remainder;
// 		else
// 			spec->buf[j++] = 55 + remainder;
// 		num = num / 16;
// 	}
// 	j--;
// 	while (i < j)
// 	{
// 		remainder = spec->buf[i];
// 		spec->buf[i++] = spec->buf[j];
// 		spec->buf[j--] = remainder;
// 	}
// }
//

//
// void	ft_f_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }
