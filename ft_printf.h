#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_spec
{
	//char	flag;
	char	typet;
	//char	size;
	//int		width; // #0-+ and space
	//int		accuracy;

} t_spec;

int     printf(const char *restrict format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void    ft_bzero(void *s, size_t n);
char	*ft_strcpy(char *dest, char *src);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s);

#endif
