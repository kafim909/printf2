/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_flag_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:35:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 17:39:46 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void string_check(t_var *var)
{
	if ((VT->s || VT->s_bol) && VF->prec < 0)
	{
		VF->prec = 0;
		VF->period = 0;
	}
}

int	data_flag_convert(t_var *var)
{
	string_check(var);
	
	if (!VF->minus && !VF->period && !VF->prec && !VF->wd_prec && !VF->wd_width && !VF->width_size && !VF->zero)
		return (1);
	if (VF->width_size == 0 && !VU->str)
		return (1); 
	if (!VF->width_size && !VF->period)
		return (1);
	if (VF->width_size && VF->zero && VF->minus && !VF->period)
		if (!width_minus_noprec(var))
		return (0);
	if (VF->width_size && VF->minus && !VF->zero && !VF->period)
		if (!width_minus_noprec(var))
			return (0);
	if (VF->width_size && VF->zero && !VF->period && !VT->s && !VT->s_bol)
		if (!width_zero_noprec(var))
			return (0);
	if (VF->width_size && !VF->period && !VF->minus && !VF->zero)
		if (!width_noflags_noprec(var))
			return (0);
	if (VF->width_size && VF->period && VF->minus && (VT->s || VT->s_bol))
		if (!width_minus_prec_str(var))
			return (0);
	if (VF->width_size >= VF->prec && VF->period && VF->minus && !VT->s && !VT->s_bol)				
		if (!width_minus_prec(var))
			return (0);
	if (VF->prec > VF->width_size && !VT->s && !VT->s_bol)
		if (!prec_width(var))
			return (0);
	if (VF->prec > VF->width_size && (VT->s || VT->s_bol))
		if (!prec_width_str(var))
			return (0);
	if (VF->width_size >= VF->prec && VF->period && !VF->zero && !VF->minus && !VT->s && !VT->s_bol)
		if (!width_noflags_prec(var))
			return (0);
	if (VF->width_size >= VF->prec && VF->period && VF->zero && !VT->s && !VT->s_bol)
		if (!width_zero_prec(var))
			return (0);
	if (VF->width_size >= VF->prec && VF->period && !VF->zero && !VF->minus && (VT->s || VT->s_bol))
		if (!width_prec_str(var))
			return (0);
	return (1);
	}