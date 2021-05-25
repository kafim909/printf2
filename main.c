/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 07:55:07 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 11:23:23 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

int main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";


	// printf(" [%d]\n", printf(" -%-*c* -%-*c* ", 2, 0, -2, 0));

	// printf(" [%d]\n", ft_printf(" -%-*c* -%-*c* ", 2, 0, -2, 0));

	// printf("\n\n");
	
	printf(" [%d]\n", printf(" %10p %-10p ", 0, 0));
	printf(" [%d]\n", ft_printf(" %10p %-10p ", 0, 0));
	
	// printf("\n\n");
	// printf("\n\n");
	// printf("\n\n");
	
	// printf("[%d]\n", printf("-->|%-1.2d|<--\n", -1));
	// printf("[%d]\n", ft_printf("-->|%-1.2d|<--\n", -1));

	// printf("[%d]\n", printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("[%d]\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));

	// printf("\n\n");

	// printf(" [%d]\n", printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// printf(" [%d]\n", ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));














	// str = malloc(sizeof(char) * 20);
	// str = ft_itoa_base(202020, "0123456789abcdef");
	// printf("[%s]\n", str);

	// ft_putnbr_base(20, "0123456789abcdef");
	// ft_printf("[%-*.*u]", 4, 5, 10);
	// printf("[%-*.*u]", 4, 5, 10);
	
	// ft_printf("[-%*c*]\n", 5, 0);
	// printf("[-%*c*]\n", 5, 0);
}