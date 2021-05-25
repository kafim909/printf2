/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:20:52 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:37:10 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_type	*parse_type_3(char c, va_list args, t_type *type)
{
	if (c == 'X')
	{
		type->HEX = va_arg(args, unsigned int);
		if (type->HEX == 0)
			type->X_bol = 1;
	}
	if (c == '%')
		type->modulo = '%';
	return (type);
}

static t_type	*parse_type_2(char c, va_list args, t_type *type)
{
	if (c == 'i' || c == 'd')
	{
		type->d = va_arg(args, int);
		if (type->d == 0)
			type->d_bol = 1;
		if (type->d < 0)
			type->minus_d = 1;
	}
	if (c == 'u')
	{
		type->u = va_arg(args, unsigned int);
		if (type->u == 0)
			type->u_bol = 1;
	}
	if (c == 'x')
	{
		type->hex = va_arg(args, unsigned int);
		if (type->hex == 0)
			type->x_bol = 1;
	}
	return (parse_type_3(c, args, type));
}

t_type	*parse_type(char c, va_list args, t_type *type)
{
	if (c == 'c')
	{
		type->c = va_arg(args, int);
		if (type->c == 0)
			type->c_bol = 1;
	}
	if (c == 's')
	{
		type->s = va_arg(args, char *);
		if (!type->s)
			type->s_bol = 1;
	}
	if (c == 'p')
	{
		type->p = va_arg(args, void *);
		if (type->p == 0)
			type->p_bol = 1;
	}
	return (parse_type_2(c, args, type));
}
