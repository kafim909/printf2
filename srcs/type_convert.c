/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:02:13 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:51:24 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*type_convert_2(t_type *type, t_flags *flags, char **str)
{
	if (type->i || type->d_bol)
		*str = convert_int(type, flags);
	else if (type->modulo)
		*str = convert_modulo();
	else if (type->p || type->p_bol)
		*str = convert_ptr(type);
	else if (type->s || type->s_bol)
		*str = convert_str(type);
	else if (type->u || type->u_bol)
	{
		if (flags->period && !flags->prec && type->u_bol)
			return (*str);
		*str = convert_unsigned(type);
	}
	return (*str);
}

char	*type_convert(t_type *type, t_flags *flags)
{
	char	*str;

	str = NULL;
	if ((type->s && flags->zero && flags->period)
		|| (type->s && flags->period && !flags->prec && !flags->width_size))
		return (str);
	if (flags->period && !flags->prec && (type->x_bol || type->X_bol
			|| type->d_bol))
		return (str);
	if (type->c || type->c_bol)
		str = convert_char(type);
	else if (type->d || type->d_bol)
		str = convert_int(type, flags);
	else if (type->HEX || type->X_bol)
		str = convert_x(type);
	else if (type->hex || type-> x_bol)
		str = convert_x(type);
	return (type_convert_2(type, flags, &str));
}
