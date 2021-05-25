/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:02:13 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 17:09:29 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_convert_2(t_var *var)
{
	if (VT->modulo)
		if (!convert_modulo(var))
			return(0);
	if (VT->p || VT->p_bol)
		if (!convert_ptr(var))
			return (0);
	if (VT->s || VT->s_bol)
		if  (!convert_str(var))
			return (0);
	if (VT->u || VT->u_bol)
	{
		if (VF->period && !VF->prec && VT->u_bol)
			return (1);
		if (!convert_unsigned(var))
			return (0);
	}
	return (1);
}

int	type_convert(t_var *var)
{
	if ((VT->s && VF->zero && VF->period)
		|| (VT->s && VF->period && !VF->prec && !VF->width_size)
		|| (VF->period && !VF->prec && (VT->x_bol || VT->X_bol
			|| VT->d_bol)))
		return (1);
	if (VT->c || VT->c_bol)
		if (!convert_char(var))
			return(0);
	if (VT->d || VT->i || VT->d_bol)
		if(!convert_int(var))
			return (0);
	if (VT->HEX || VT->X_bol)
		if (!convert_x(var))
			return (0);
	if (VT->hex || VT-> x_bol)
		if (!convert_x(var))
			return (0);
	return (type_convert_2(var));
}
