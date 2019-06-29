/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:50:19 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/28 18:54:12 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

typedef struct s_spec
{
	char	*buf;
	int		flag; // 1 - h 2 - hh 3 - l 4 -ll
	int		space;
	int		zero;
	int		minus;
	int		plus;
	int		grid;
	int 	pmz; // plus = 0, minus = -1 or zero = 2
	int		width; // #0-+ and space
	int		acc;
	int		allflagzero; //  #0-+ and space если все из этого не нашлось
	int		i;
	int		j;
	int		z; // use for void	ft_acc(char *str, t_ran *ran, t_spec *spec) Problems with norm;
			// z  - используется в %d как если подаваемое число равно нулю
	int		strl; //length of the str %s and %d
} t_spec;

typedef struct s_ran
{
	int		i;
	int		j;
	int		bs;
	char	conver;
	int		ret;
	char	*buf;
	int		fzero;
	int 	strlen;
} t_ran;



int     printf(const char *restrict format, ...);
void	ft_procwidth(char *str, t_ran *ran, t_spec *s);
void	ft_recconver(char *str, t_ran *ran, va_list *vl, t_spec *s);

void	ft_p_record(char *str, t_ran *ran, t_spec *s);
void	ft_c_record(t_ran *ran, va_list *vl, t_spec *s);
void	ft_s_record(t_ran *ran, va_list *vl, t_spec *s);
void	ft_bufjoin_s(t_ran *ran, t_spec *s);
void	ft_sprint1(t_ran *ran, t_spec *s);
void	ft_sprint2(t_ran *ran, t_spec *s);
void	ft_sprint2_1(t_ran *ran, t_spec *s);
void	ft_sprint3(t_ran *ran, t_spec *s);
void	ft_sprint4(t_ran *ran, t_spec *s);
void	ft_sprint4_1(t_ran *ran, t_spec *s);
void	ft_sprint4_2(t_ran *ran, t_spec *s);
void	ft_sprint4_3(t_ran *ran, t_spec *s);

void	ft_d_record(t_ran *ran, va_list *vl, t_spec *s);
void	ft_di(t_spec *spec, t_ran *ran, int num);
void	ft_diexeption(t_spec *s, int *num);
void	ft_dsi(t_spec *spec, t_ran *ran, short int num);
void	ft_dsiexeption(t_spec *s, short int *num);
void	ft_dc(t_spec *spec, t_ran *ran, char num);
void	ft_dcexeption(t_spec *s, char *num);
void	ft_dli(t_spec *spec, t_ran *ran, long int num);
void	ft_dliexeption(t_spec *s, long int *num);
void	ft_dlli(t_spec *spec, t_ran *ran, long long int num);
void	ft_dllexeption(t_spec *s, long long int *num);
void	ft_bufjoin_d(t_ran *ran, t_spec *s);
int		ft_checkdzero(t_spec *s, int n);
int		ft_checkdzero1(t_spec *s);


void	ft_i_record(char *str, t_ran *ran, va_list *vl, t_spec *s);
void	ft_o_record(char *str, t_ran *ran, va_list *vl, t_spec *s);
void	ft_u_record(char *str, t_ran *ran, va_list *vl, t_spec *s);
void	ft_f_record(char *str, t_ran *ran, va_list *vl, t_spec *s);



void	ft_x_record(t_ran *ran, va_list *vl, t_spec *s);
void	ft_X_record(t_ran *ran, va_list *vl, t_spec *s);
void	ft_ui(t_spec *s, t_ran *ran, unsigned long long int num, int sm);
void	ft_usi(t_spec *s, t_ran *ran, unsigned long long int num, int sm);
void	ft_ucc(t_spec *s, t_ran *ran, unsigned long long int num, int sm);
void	ft_uli(t_spec *s, t_ran *ran, unsigned long long int num, int sm);
void	ft_ulli(t_spec *s, t_ran *ran, unsigned long long int num, int sm);
void	ft_bufjoin_x(t_ran *ran, t_spec *s);
void	ft_print1(t_ran *ran, t_spec *s);
void	ft_print2(t_ran *ran, t_spec *s);
void	ft_print2_1(t_ran *ran, t_spec *s);
void	ft_print3(t_ran *ran, t_spec *s);
void	ft_print4(t_ran *ran, t_spec *s);
void	ft_print4_1(t_ran *ran, t_spec *s);
void	ft_print4_2(t_ran *ran, t_spec *s);
void	ft_print4_3(t_ran *ran, t_spec *s);
void	ft_print4_4(t_ran *ran, t_spec *s);
void	ft_print4_5(t_ran *ran, t_spec *s);
void	ft_print4_6(t_ran *ran, t_spec *s);
void	ft_print4grid(t_ran *ran, t_spec *s);
void	ft_checkgrid(t_ran *ran, t_spec *s);
void	ft_checkgridplus2(t_ran *ran, t_spec *s);
int		ft_biggeraccornum(t_spec *s);


int		ft_strlen(char *str);
void	ft_newstruct(t_spec *s);
void	ft_findflags(char *str, t_ran *ran, t_spec *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
void	ft_strjcpy(char *dest, t_spec *s, int *j);
void	ft_easyflag(char *str, t_spec *s, int j);
void 	*extend_buf(t_ran *ran);
void	ft_putchar(char c);
void	ft_putstr(char *str, t_ran ran, int *i);
void	ft_bzero(void *s, size_t size);
void	ft_strdel(char **as);
void	ft_reworkbuf(t_spec *s);

#endif
