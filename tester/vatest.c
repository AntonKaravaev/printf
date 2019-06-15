/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vatest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:42:01 by crenly-b          #+#    #+#             */
/*   Updated: 2019/06/11 13:59:46 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int		sumnum(int num, ...)
{
	int	sum;
	int	count;

	sum = 0;
	count = 0;
	va_list argptr;
	va_start(argptr, num);
	while (count < num)
	{
		sum = sum + va_arg(argptr, int);
		count++;
	}
	va_end(argptr);
	return (sum);
}

void printstr(int num, ...)
{
	int count = 0;
	char *ptr;
	va_list argptr;

	va_start(argptr, num);
	while (count < num)
	{
		ptr = va_arg(argptr, char *);
		printf("PTR = %s\n", ptr);
		count++;
	}
	va_end(argptr);
}

int		main(int argc, char *argv[])
{
	int total;

	total = sumnum(3, 1, 12, 1324);
	printf("total = %d\n", total);
	printstr(3, "one", "two", "fhree");

	return (0);
}
