#include "ft_printf.h"

void	ft_bufjoin_d(t_ran *ran, t_spec *s)
{
	if (s->width == 0 && s->acc == 0)
		ft_print1(ran, s);
	if (s->width != 0 && s->acc == 0)
		ft_print2(ran, s);
	if (s->width == 0 && s->acc != 0)
		ft_print3(ran, s);
	if (s->width != 0 && s->acc != 0)
		ft_print4(ran, s);
}
