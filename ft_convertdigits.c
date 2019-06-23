#include "ft_printf.h"

// void	ft_dui(t_spec *spec, t_ran *ran, unsigned long long int num,
// 	int sm)
// {
// 	unsigned int	remainder;
// 	unsigned int	localnum;
//
// 	localnum = (unsigned int)num;
// 	if (localnum == 0)
// 		spec->buf[spec->j++] = 48 + localnum;
// 	while (localnum != 0)
// 	{
// 		remainder = localnum % 16;
// 		if (remainder < 10)
// 			spec->buf[spec->j++] = 48 + remainder;
// 		else
// 			spec->buf[spec->j++] = 55 + sm + remainder;
// 		localnum = localnum / 16;
// 	}
// 	spec->j--;
// 	while (spec->i < spec->j)
// 	{
// 		remainder = spec->buf[spec->i];
// 		spec->buf[spec->i++] = spec->buf[spec->j];
// 		spec->buf[spec->j--] = remainder;
// 	}
// 	ft_bufjoin_d(ran, spec);
// }
//
// void	ft_dusi(t_spec *spec, t_ran *ran, unsigned long long int num,
// 	int sm)
// {
// 	unsigned short int	remainder;
// 	unsigned short int	localnum;
//
// 	localnum = (unsigned short int)num;
// 	if (localnum == 0)
// 		spec->buf[spec->j++] = 48 + localnum;
// 	while (localnum != 0)
// 	{
// 		remainder = localnum % 16;
// 		if (remainder < 10)
// 			spec->buf[spec->j++] = 48 + remainder;
// 		else
// 			spec->buf[spec->j++] = 55 + sm + remainder;
// 		localnum = localnum / 16;
// 	}
// 	spec->j--;
// 	while (spec->i < spec->j)
// 	{
// 		remainder = spec->buf[spec->i];
// 		spec->buf[spec->i++] = spec->buf[spec->j];
// 		spec->buf[spec->j--] = remainder;
// 	}
// 	ft_bufjoin_d(ran, spec);
// }
//
// void	ft_ducc(t_spec *spec, t_ran *ran, unsigned long long int num,
// 	int sm)
// {
// 	unsigned char	remainder;
// 	unsigned char	localnum;
//
// 	localnum = (unsigned char)num;
// 	if (localnum == 0)
// 		spec->buf[spec->j++] = 48 + localnum;
// 	while (localnum != 0)
// 	{
// 		remainder = localnum % 16;
// 		if (remainder < 10)
// 			spec->buf[spec->j++] = 48 + remainder;
// 		else
// 			spec->buf[spec->j++] = 55 + sm + remainder;
// 		localnum = localnum / 16;
// 	}
// 	spec->j--;
// 	while (spec->i < spec->j)
// 	{
// 		remainder = spec->buf[spec->i];
// 		spec->buf[spec->i++] = spec->buf[spec->j];
// 		spec->buf[spec->j--] = remainder;
// 	}
// 	ft_bufjoin_d(ran, spec);
// }
//
// void	ft_duli(t_spec *spec, t_ran *ran, unsigned long long int num,
// 	int sm)
// {
// 	unsigned long int	remainder;
// 	unsigned long int	localnum;
//
// 	localnum = (unsigned long int)num;
// 	if (localnum == 0)
// 		spec->buf[spec->j++] = 48 + localnum;
// 	while (localnum != 0)
// 	{
// 		remainder = localnum % 16;
// 		if (remainder < 10)
// 			spec->buf[spec->j++] = 48 + remainder;
// 		else
// 			spec->buf[spec->j++] = 55 + sm + remainder;
// 		localnum = localnum / 16;
// 	}
// 	spec->j--;
// 	while (spec->i < spec->j)
// 	{
// 		remainder = spec->buf[spec->i];
// 		spec->buf[spec->i++] = spec->buf[spec->j];
// 		spec->buf[spec->j--] = remainder;
// 	}
// 	ft_bufjoin_d(ran, spec);
// }
//
// void	ft_dulli(t_spec *spec, t_ran *ran, unsigned long long int num,
// 	int sm)
// {
// 	unsigned long long int	remainder;
// 	unsigned long long int	localnum;
//
// 	localnum = (unsigned long long int)num;
// 	if (localnum == 0)
// 		spec->buf[spec->j++] = 48 + localnum;
// 	while (localnum != 0)
// 	{
// 		remainder = localnum % 16;
// 		if (remainder < 10)
// 			spec->buf[spec->j++] = 48 + remainder;
// 		else
// 			spec->buf[spec->j++] = 55 + sm + remainder;
// 		localnum = localnum / 16;
// 	}
// 	spec->j--;
// 	while (spec->i < spec->j)
// 	{
// 		remainder = spec->buf[spec->i];
// 		spec->buf[spec->i++] = spec->buf[spec->j];
// 		spec->buf[spec->j--] = remainder;
// 	}
// 	ft_bufjoin_d(ran, spec);
// }

//
