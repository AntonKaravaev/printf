/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:50:19 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/16 01:23:16 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_spec
{
	char	*buf;
	char	conver;
	int		space;
	int		zero;
	int		minus;
	int		plus;
	int		grid;
	int 	pmz; // plus = 0, minus = 1 or zero = 2
	int		width; // #0-+ and space
	char	*buf_width;
	int		acc;
	char	*buf_acc;
} t_spec;

typedef struct s_ran
{
	int		i;
	int		j;
	int		bs;
	char	*buf;
} t_ran;
void	ft_recconver(char *str, t_ran *ran, va_list *vl, t_spec *spec);
int     printf(const char *restrict format, ...);
int		ft_strlen(char *str);
void	ft_newstruct(t_spec *spec);

void 	*extend_buf(t_ran *ran);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_bzero(void *s, size_t size);
void	ft_strdel(char **as);
void	ft_c_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_proc_record(char *str, t_ran *ran, t_spec *spec);
void	ft_s_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_p_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_d_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_findpmz(t_spec *spec, int num);
void	ft_i_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_o_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_u_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_x_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_X_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
void	ft_f_record(char *str, t_ran *ran, va_list *vl, t_spec *spec);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

#endif
