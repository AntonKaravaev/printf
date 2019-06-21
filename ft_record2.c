#include "ft_printf.h"

int		ft_biggeraccornum(t_spec *spec)
{
	if (ft_strlen(spec->buf) < spec->acc)
		return (spec->acc);
	return (ft_strlen(spec->buf));
}

void	ft_print4(t_ran *ran, t_spec *spec)
{
	if (spec->minus == 1 && spec->buf[0] == '0' && spec->acc != -1) // doesnt matter spec->zero == 0 or 1
	{
		while (spec->acc != spec->i)
		{
			ran->buf[ran->j++] = '0';
			spec->i++;
		}

		while (spec->i < spec->width)
		{
			ran->buf[ran->j++] = ' ';
			spec->i++;
		}
		return ;
	}
	if (spec->minus == 0 && spec->buf[0] == '0' && spec->acc != -1) // doesnt matter spec->zero == 0 or 1
	{
		while (spec->width - spec->acc > spec->i)
		{
			ran->buf[ran->j++] = ' ';
			spec->i++;
		}
		while (spec->i < spec->width)
		{
			ran->buf[ran->j++] = '0';
			spec->i++;
		}
		return ;
	}
	if (spec->acc == -1 && spec->buf[0] == '0') // doesnt matter spec->zero == 0 or 1
	{
		while (spec->i < spec->width)
		{
				ran->buf[ran->j++] = ' ';
				spec->i++;
		}
		return ;
	}
	if (spec->allflagzero == 1) // doesnt matter spec->zero == 0 or 1
	{
		if (spec->width >= spec->acc)
		{
			while (spec->i < spec->width - ft_biggeraccornum(spec))
			{
				ran->buf[ran->j++] = ' ';
				spec->i++;
			}
			while (spec->i < spec->width - ft_strlen(spec->buf))
			{
				ran->buf[ran->j++] = '0';
				spec->i++;
			}
			ft_strjcpy(ran->buf, spec->buf, &ran->j);
			return ;
		}
		else
		{
			while (spec->i < spec->acc - ft_strlen(spec->buf))
			{
				ran->buf[ran->j++] = '0';
				spec->i++;
			}
			ft_strjcpy(ran->buf, spec->buf, &ran->j);
			return ;
		}
	}
	if (spec->minus == 1 && spec->buf[0] != '0') // doesnt matter spec->zero == 0 or 1
	{
		if (spec->width >= spec->acc)
		{
			if (spec->grid == 1)
			{
				ft_checkgrid(ran, spec);
				spec->i += 2;
				while (spec->i < spec->acc - ft_strlen(spec->buf) + 2)
				{
					ran->buf[ran->j++] = '0';
					spec->i++;
				}
				ft_strjcpy(ran->buf, spec->buf, &ran->j);
				spec->i += ft_strlen(spec->buf);
				while (spec->i < spec->width)
				{
					ran->buf[ran->j++] = ' ';
					spec->i++;
				}
				return ;
			}
			if (spec->acc < ft_strlen(spec->buf))
			{
				ft_strjcpy(ran->buf, spec->buf, &ran->j);
				spec->i += ft_strlen(spec->buf);
				while (spec->i < spec->width)
				{
					ran->buf[ran->j++] = ' ';
					spec->i++;
				}
				return ;
			}
			while (spec->i < spec->width - ft_biggeraccornum(spec))
			{
				ran->buf[ran->j++] = '0';
				spec->i++;
			}
			ft_strjcpy(ran->buf, spec->buf, &ran->j);
			spec->i += ft_strlen(spec->buf);
			while (spec->i < spec->width)
			{
				ran->buf[ran->j++] = ' ';
				spec->i++;
			}
			return ;
		}
		else
		{
			if (spec->grid == 1)
			{
				ft_checkgrid(ran, spec);
				spec->i += 2;
				while (spec->i < spec->acc - ft_strlen(spec->buf) + 2)
				{
					ran->buf[ran->j++] = '0';
					spec->i++;
				}
				ft_strjcpy(ran->buf, spec->buf, &ran->j);
				spec->i += ft_strlen(spec->buf);
				while (spec->i < spec->width)
				{
					ran->buf[ran->j++] = ' ';
					spec->i++;
				}
				return ;
			}
			if (spec->acc >= ft_strlen(spec->buf))
			{
				while (spec->i < spec->acc - ft_strlen(spec->buf))
				{
					ran->buf[ran->j++] = '0';
					spec->i++;
				}
			}
			ft_strjcpy(ran->buf, spec->buf, &ran->j);
			spec->i += ft_strlen(spec->buf);
			while (spec->i < spec->acc - ft_strlen(spec->buf))
			{
				ran->buf[ran->j++] = '0';
				spec->i++;
			}
			return ;
		}
	}
	if (spec->minus == 0 && spec->buf[0] != '0')
	{
		if (spec->width >= spec->acc)
		{
			if (spec->grid == 1)
			{
				while (spec->i < spec->width - ft_biggeraccornum(spec) - 2)
				{
					ran->buf[ran->j++] = ' ';
					spec->i++;
				}
				ft_checkgrid(ran, spec);
				spec->i += 2;
				while (spec->i < spec->width - ft_strlen(spec->buf))
				{
					ran->buf[ran->j++] = '0';
					spec->i++;
				}
				ft_strjcpy(ran->buf, spec->buf, &ran->j);
				return ;
			}
			while (ran->j < spec->width - ft_biggeraccornum(spec))
			{
				ran->buf[ran->j++] = ' ';
				spec->i++;
			}
			while (spec->i < spec->width - ft_strlen(spec->buf))
			{
				ran->buf[ran->j++] = '0';
				spec->i++;
			}
			ft_strjcpy(ran->buf, spec->buf, &ran->j);
			return ;
		}
		else
		{
			if (spec->grid == 1)
			{
				ft_checkgrid(ran, spec);
				while (spec->i < spec->acc - ft_strlen(spec->buf))
				{
					ran->buf[ran->j++] = '0';
					spec->i++;
				}
				ft_strjcpy(ran->buf, spec->buf, &ran->j);
				return ;
			}
			if (spec->acc >= ft_strlen(spec->buf))
			{
				while (spec->i < spec->acc - ft_strlen(spec->buf))
				{
					ran->buf[ran->j++] = '0';
					spec->i++;
				}
			}
			ft_strjcpy(ran->buf, spec->buf, &ran->j);
			spec->i += ft_strlen(spec->buf);
			while (spec->i < spec->acc - ft_strlen(spec->buf))
			{
				ran->buf[ran->j++] = '0';
				spec->i++;
			}
			return ;
		}
	}
}

void ft_print3(t_ran *ran, t_spec *spec)
{
	if (spec->acc == -1)
		return ;
	if (spec->grid == 1 && spec->buf[0] != '0')
	{
		ft_checkgrid(ran, spec);
		spec->i += 2;
		while (spec->i < spec->acc - ft_strlen(spec->buf) + 2)
		{
			ran->buf[ran->j++] = '0';
			spec->i++;
		}
		ft_strjcpy(ran->buf, spec->buf, &ran->j);
		return ;
	}
	while (spec->i < spec->acc - ft_strlen(spec->buf))
	{
		ran->buf[ran->j++] = '0';
		spec->i++;
	}
	ft_strjcpy(ran->buf, spec->buf, &ran->j);
}

void ft_print2(t_ran *ran, t_spec *spec)
{
	int i;

	if (spec->zero == 0)
	{
		if ((spec->grid == 1 && ran->conver == 'x' && spec->buf[0] != '0')
			|| (spec->grid == 1 && ran->conver == 'X' && spec->buf[0] != '0'))
			i = ft_strlen(spec->buf) + 2;
		else
			i = ft_strlen(spec->buf);
		while (i < spec->width && spec->minus == 0)
		{
			ran->buf[ran->j++] = ' ';
			i++;
		}
		ft_checkgrid(ran, spec);
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
	else
	{
		if (spec->minus == 0)
		{
			if (spec->grid == 1 && ran->conver == 'x' && spec->buf[0] != '0')
			{
				ran->buf[ran->j++] = '0';
				ran->buf[ran->j++] = 'x';
				i = ft_strlen(spec->buf) + 2;
			}
			else if (spec->grid == 1 && ran->conver == 'X' && spec->buf[0] != '0')
			{
				ran->buf[ran->j++] = '0';
				ran->buf[ran->j++] = 'X';
				i = ft_strlen(spec->buf) + 2;
			}
			else
				i = ft_strlen(spec->buf);
			while (i < spec->width && spec->minus == 0)
			{

				ran->buf[ran->j++] = '0';
				i++;
			}
			if (ft_strlen(spec->buf) + ran->j < ran->bs && spec->minus == 0)
				ft_strjcpy(ran->buf, spec->buf, &ran->j);
			else
			{
				extend_buf(ran);
				ft_strjcpy(ran->buf, spec->buf, &ran->j);
			}
		}
		else
		{
			if (spec->grid == 1 && ran->conver == 'x' && spec->buf[0] != '0')
			{
				ran->buf[ran->j++] = '0';
				ran->buf[ran->j++] = 'x';
				i = ft_strlen(spec->buf) + 2;
			}
			else if (spec->grid == 1 && ran->conver == 'X' && spec->buf[0] != '0')
			{
				ran->buf[ran->j++] = '0';
				ran->buf[ran->j++] = 'X';
				i = ft_strlen(spec->buf) + 2;
			}
			else
				i = ft_strlen(spec->buf);
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
}

void	ft_print1(t_ran *ran, t_spec *spec)
{
	ft_checkgrid(ran, spec);
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
		spec->i = 0;
	if (spec->width == 0 && spec->acc == 0)
		ft_print1(ran, spec);
	if (spec->width != 0 && spec->acc == 0)
		ft_print2(ran, spec);
	if (spec->width == 0 && spec->acc != 0)
		ft_print3(ran, spec);
	if (spec->width != 0 && spec->acc != 0)
		ft_print4(ran, spec);
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
// void	ft_f_record(char *str, t_ran *ran, va_list *vl, t_spec *spec)
// {
//
//
// }
