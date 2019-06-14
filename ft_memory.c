#include "ft_printf.h"

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	len = 0;
	while (s[len] != '\0')
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

void 	*extend_buf(t_ran *ran)
{
	char *bufnew;

	(*ran).bs += 100;
	if (!(bufnew = (char *)malloc(sizeof(char) * (*ran).bs)))
		exit(-1);
	ft_bzero(bufnew, (*ran).bs);
	bufnew = ft_strcpy(bufnew, (*ran).buf);
	ft_strdel(&(*ran).buf);
	(*ran).buf = ft_strdup(bufnew);
	ft_strdel(&bufnew);
	return ((*ran).buf);
}
