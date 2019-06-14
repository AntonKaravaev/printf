/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:31:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/14 21:29:55 by crenly-b         ###   ########.fr       */
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
	// char *buf;
	// buf = (char *)malloc(sizeof(char) * 11);
	// buf[10] = '\0';
	// *buf = 'A';
	// buf[2] = 'B';
	// buf[3] = 'C';
	// buf[4] = '1';
	// buf[5] = '2';
	// buf[6] = '3';
	// buf[7] = '4';
	// buf[8] = '5';
	// buf[9] = '6';
	// test(buf);
	// printf(" %c \n", *buf);
	// printf("%012123122.12d\n", 123);
//printf("%.d\n", 0/0);
	// printf("%.d\n", 123);
	// printf("%d\n", 123);
	printf("%0d\n", 123);
	printf("%00000d\n", 123);
	printf("%00012d\n", 123);
	printf("%00012d\n", 123);
	// printf("%0 d\n", 123);
	//printf("%f\n", 0.0 / 0.0);
	// printf("%   01d\n", 123);
	// printf("%   0010d\n", 123);
	// printf("%   d\n", -123);
	// printf("%   d\n", 0);
  //  printf("Hello\n");
  //  printf("Hello%%\n");
  //  printf("Hello %3d %d \n", 12, 123);
  //printf("Hello %3 %3d %3d \n", 123, 1245);
  // printf("Hello %3d %3d %3d \n", 12, 12, 1245);
  //printf("Hello %3d %3d %3d \n", 12, 1, 125);
  //printf("Hello %3d %d \n", 12, 123);
  //printf("Hello %03d \n", 12);
  //printf (" %f \n", 123.441234567);
  //printf("%3.8d\n", 1000);
  //printf("%3.4d\n", 10300);
//printf("%.8d\n", 1000);
  //printf("%10d\n", 1000);
  //printf("%5.7s\n", "hel");
  // printf("right-justified:%8d\n", 100);
  // printf ("left-justified: %-8d\n", 100);
  // printf("%#.0f\n", 10.00);
  // printf("%*.*f", 10, 4, 1234.34);
  //var("hello", 15, 23, 44);
  return (0);
}
