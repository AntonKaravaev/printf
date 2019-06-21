#include "ft_printf.h"

// void		ft_width(char *str, t_ran *ran, t_spec *spec)
// {
// 	int w;
//
// 	w = 0;
// 	if (str[(*ran).i] >= '1' && str[(*ran).i] <= '9')
// 	{
// 		(*spec).buf[w++] = str[(*ran).i++];
// 		while ((str[(*ran).i] >= '0' && str[(*ran).i] <= '9'))
// 			(*spec).buf[w++] = str[(*ran).i++];
// 		(*spec).width = ft_atoi((*spec).buf);
// 		ft_strdel(&(*spec).buf);
// 	}
// }
//
// void		ft_acc(char *str, t_ran *ran, t_spec *spec)
// {
// 	int a;
//
// 	a = 0;
// 	if (str[(*ran).i] == '.')
// 	{
// 		(*ran).i++;
// 		while (str[(*ran).i] == '0')
// 			(*ran).i++;
// 		if (str[(*ran).i] >= '0' && str[(*ran).i] <= '9')
// 		{
// 			while (str[(*ran).i] != 'd' || (str[(*ran).i] >= '0'
// 				&& str[(*ran).i] <= '9'))
// 				(*spec).buf[a++] = str[(*ran).i++];
// 			(*spec).acc = ft_atoi((*spec).buf);
// 			ft_strdel(&(*spec).buf);
// 		}
// 	}
// }



void	ft_bufjoin_d(char *str, t_ran *ran, t_spec *spec, int num)
{
	spec->buf = ft_itoa(num);
	if (str[ran->i] == 'd')
	{
		if(ft_strlen(spec->buf) + ran->j < ran->bs )
		{
			ft_strjcpy(ran->buf, spec->buf, &ran->j);
			ft_strdel(&spec->buf);
		}
	}
}

// void	ft_c_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {

// }


void	ft_p_record(char *str, t_ran *ran, t_spec *spec)
{
	ft_procwidth(str, ran, spec);
	if (spec->minus == 1)
	{

		ran->buf[ran->j++] = str[ran->i];
		while(spec->width > 1)
		{
			ran->buf[ran->j++] = ' ';
			spec->width--;
		}
		return ;
	}
	while(spec->width > 1)
	{
		ran->buf[ran->j++] = ' ';
		spec->width--;
	}
	ran->buf[ran->j++] = str[ran->i];

}
//
void	ft_d_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{
	int num;

	num = va_arg (*vl, int);
	ft_findpmz(spec, num);
//	ft_flag(str, ran, spec);
//	ft_width(str, ran, spec);
//	ft_acc(str, ran, spec);
	ft_bufjoin_d(str, ran, spec, num);
}

// void	ft_i_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }
