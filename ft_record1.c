#include "ft_printf.h"

void		ft_findpmz(t_spec *spec, int num)
{
	(*spec).pmz = 0;
	if (num < 0)
		(*spec).pmz = 1;
	else if (num == 0)
		(*spec).pmz = 2;
}

void ft_findwidth(char *str, t_ran *ran, t_spec *spec)
{
	while (str[(*ran).i] >= 0 && str[(*ran).i] <= 9)
}
void ft_before_d(char *str, t_ran *ran, t_spec *spec)
{
	while (str[(*ran).i] == 'd')
	{
		if (str[(*ran).i] == ' ')
			(*spec).space = 1;
		if (str[(*ran).i] == '+')
			(*spec).plus = 1;
		if (str[(*ran).i] == '-')
			(*spec).minus = 1;
		if (str[(*ran).i] == '0')
			(*spec).zero = 1;
		if (str[(*ran).i] == '#')
			(*spec).grid = 1;
		if (str[(*ran).i] >= 1 && str[(*ran).i] <= 9)
			ft_findwidth(str, ran, spec);
		(*ran).i++;
	}
	if (str[(*ran).i] == 'd')
		exit(-1);
}
// void ft_ifspaceandzero(char *str, t_ran *ran, t_spec *spec)
// {
// 	if (str[(*ran).i] == ' ')
// 		(*spec).space = 1;
// 	while (str[(*ran).i] == ' ')
// 		(*ran).i++;
// 	if (str[(*ran).i] == '0')
// 		(*spec).zero = 1;
// 	while (str[(*ran).i] == '0')
// 		(*ran).i++;
// 	if (str[(*ran).i] == ' ')
// 		(*spec).space = 1;
// 	while (str[(*ran).i] == ' ')
// 		(*ran).i++;
// 	while (str[(*ran).i] == ' ' || str[(*ran).i] == '0')
// 			(*ran).i++;
// 	if ((*spec).space == 1 && (*spec).zero == 1 && str[(*ran).i] == '-')
// 		exit(-1);
// }
void	ft_strjcpy(char *dest, char *src, int *j)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[(*j)++] = src[i++];
	}
}

void ft_bufjoin_d(char *str, t_ran *ran, t_spec *spec, int num)
{
	(*spec).buf = ft_itoa(num);
	if (str[(*ran).i] == 'd')
	{
		if(ft_strlen((*spec).buf) + (*ran).j < (*ran).bs )
		{
			ft_strjcpy((*ran).buf, (*spec).buf, &(*ran).j);
			ft_strdel(&(*spec).buf);
		}
		else
		{
			extend_buf(ran);
			ft_strjcpy((*ran).buf, (*spec).buf, &(*ran).j);
		}
	}
}

void	ft_c_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{


}

void	ft_s_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{


}

void	ft_p_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{


}

void	ft_d_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{
	int num;

	num = va_arg (*vl, int);
	ft_findpmz(spec, num);
	ft_before_d(str, ran, spec);
	ft_bufjoin_d(str, ran, spec, num);

}

void	ft_i_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
{


}
