/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:31:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/16 00:49:23 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// void var(char *format, ...)
// {
//   va_list ap;
//   va_start(ap, format);
//
//   printf("1 = %d\n",va_arg (ap, int));
//   printf("2 = %d\n",va_arg (ap, int));
//   printf("3 = %d\n",va_arg (ap, int));
//   va_end (ap);
// }

void test(char *str)
{
	(*str)++;
}
int	main()
{
	printf("%++%\n");
	printf("%-102   18%\n");
	printf("%14%\n");






  return (0);
}
