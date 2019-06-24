#include "ft_printf.h"

void	ft_dui(t_spec *s, t_ran *ran, unsigned long long int num)
{
	int	localnum;

	localnum = (int)num;
	if (localnum > 0)
		s->pmz = 2;
	else if (localnum < 0)
		s->pmz = 1;
	ft_itoa(localnum, s);
	ft_bufjoin_d(ran, s);
}

void	ft_dusi(t_spec *s, t_ran *ran, unsigned long long int num)
{
	unsigned short int	remainder;
	unsigned short int	localnum;

	localnum = (unsigned short int)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 10;
		s->buf[s->j++] = 48 + remainder;
		localnum = localnum / 10;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}

void	ft_ducc(t_spec *s, t_ran *ran, unsigned long long int num)
{
	unsigned char	remainder;
	unsigned char	localnum;

	localnum = (unsigned char)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 10;
		s->buf[s->j++] = 48 + remainder;
		localnum = localnum / 10;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}

void	ft_duli(t_spec *s, t_ran *ran, unsigned long long int num)
{
	unsigned long int	remainder;
	unsigned long int	localnum;

	localnum = (unsigned long int)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 10;
		s->buf[s->j++] = 48 + remainder;
		localnum = localnum / 10;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}

void	ft_dulli(t_spec *s, t_ran *ran, unsigned long long int num)
{
	unsigned long long int	remainder;
	unsigned long long int	localnum;

	localnum = (unsigned long long int)num;
	if (localnum == 0)
		s->buf[s->j++] = 48 + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 10;
		s->buf[s->j++] = 48 + remainder;
		localnum = localnum / 10;
	}
	s->j--;
	while (s->i < s->j)
	{
		remainder = s->buf[s->i];
		s->buf[s->i++] = s->buf[s->j];
		s->buf[s->j--] = remainder;
	}
	ft_bufjoin_d(ran, s);
}
