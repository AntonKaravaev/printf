#include "ft_printf.h"

void    ft_print_0x_prefix(t_ran *ran)
{
    ran->buf[ran->j++] = '0';
    ran->buf[ran->j++] = 'x';
}

void    ft_print_sps_for_p(t_ran *ran, t_spec *s, int content_width)
{
    int i;

    i = 0;
    while (i++ < (s->width - content_width))
    	ran->buf[ran->j++] = ' ';
}

void	ft_print5(t_ran *ran, t_spec *s)
{
    int cw;

    s->j = 0;
    if (ran->conver != 'p')
        return ;
    if (s->buf[0] != '0')
        cw = 14;
    else
        cw = 3;
    if (s->minus == 0)
        ft_print_sps_for_p(ran, s, cw);
    ft_print_0x_prefix(ran);
    if (cw == 3)
        ran->buf[ran->j++] = '0';
    else  
        ft_strjcpy(ran->buf, s, &ran->j);
    if (s->minus == 1)
        ft_print_sps_for_p(ran, s, cw);
}