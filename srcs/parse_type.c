/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:20:52 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 13:41:26 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_var	*parse_type_3(char c, va_list args, t_var *var)
{
	if (c == 'X')
	{
		VT->HEX = va_arg(args, unsigned int);
		if (VT->HEX == 0)
			VT->X_bol = 1;
	}
	if (c == '%')
		VT->modulo = '%';
	return (var);
}

static t_var	*parse_type_2(char c, va_list args, t_var *var)
{
	if (c == 'i' || c == 'd')
	{
		VT->d = va_arg(args, int);
		if (VT->d == 0)
			VT->d_bol = 1;
		if (VT->d < 0)
			VT->minus_d = 1;
	}
	if (c == 'u')
	{
		VT->u = va_arg(args, unsigned int);
		if (VT->u == 0)
			VT->u_bol = 1;
	}
	if (c == 'x')
	{
		VT->hex = va_arg(args, unsigned int);
		if (VT->hex == 0)
			VT->x_bol = 1;
	}
	return (parse_type_3(c, args, var));
}

t_var	*parse_type(char c, va_list args, t_var *var)
{
	if (c == 'c')
	{
		VT->c = va_arg(args, int);
		if (VT->c == 0)
			VT->c_bol = 1;
	}
	if (c == 's')
	{
		VT->s = va_arg(args, char *);
		if (!VT->s)
			VT->s_bol = 1;
	}
	if (c == 'p')
	{
		VT->p = va_arg(args, void *);
		if (VT->p == 0)
			VT->p_bol = 1;
	}
	return (parse_type_2(c, args, var));
}
