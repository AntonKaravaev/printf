/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:31:15 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/25 22:38:32 by crenly-b         ###   ########.fr       */
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

int	main()
{

	printf("%x\n", 123);
	printf("\n");

	return (0);
}


// #include<stdio.h>
// int main()
// {
//  long decimal, quotient, remainder;
//  int i, j = 0;
//  char hexadecimal[100];
//
//  printf("Enter decimal number: \t");
//  scanf("%ld", &decimal);
//  printf("%ld \n",decimal);
//
//  quotient = decimal;
//
//  while (quotient != 0)
//  {
//  remainder = quotient % 16;          //step 1
//  if (remainder < 10)
//  hexadecimal[j++] = 48 + remainder;   //step 2
//  else
//  hexadecimal[j++] = 55 + remainder;   //step 3
//  quotient = quotient / 16;            //step 4
//  }
//
//  printf("Equivalent hexadecimal value of decimal number %ld:",decimal);
//
//  //step 6
//  for (i = j; i >= 0; i--)
//  printf("%c", hexadecimal[i]);
//  return 0;
// }
