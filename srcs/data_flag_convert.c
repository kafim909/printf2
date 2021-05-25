/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_flag_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:35:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:39:36 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void string_check(t_flags *flags, t_type *types)
{
	if ((types->s || types->s_bol) && flags->prec < 0)
	{
		flags->prec = 0;
		flags->period = 0;
	}
}

char	*data_flag_convert(t_flags *flags, char *type_data, t_type *type)
{
	string_check(flags, type);
	
	if (!flags->minus && !flags->period && !flags->prec && !flags->wd_prec && !flags->wd_width && !flags->width_size && !flags->zero)
		return (type_data);

	if (flags->width_size == 0 && !type_data)
		return (type_data); 
	
	if (!flags->width_size && !flags->period)
		return (type_data);

	if (flags->width_size && flags->zero && flags->minus && !flags->period)
		return (width_minus_noprec(flags->width_size, type_data, type));

	if (flags->width_size && flags->minus && !flags->zero && !flags->period)
		return (width_minus_noprec(flags->width_size, type_data, type));

	if (flags->width_size && flags->zero && !flags->period && !type->s && !type->s_bol)
		return (width_zero_noprec(flags->width_size, type_data, type->minus_d));
	if (flags->width_size && !flags->period && !flags->minus && !flags->zero)
		return (width_noflags_noprec(flags->width_size, type_data));	
		
	if (flags->width_size >= flags->prec && !flags->zero && !flags->minus && (type->s || type->s_bol))
		return (width_prec_str(flags->width_size, flags->prec, type_data)); 

	if (flags->width_size >= flags->prec && flags->period && !flags->zero && !flags->minus && !type->s && !type->s_bol)
		return (width_noflags_prec(flags->width_size, flags->prec, type_data, type->minus_d));

	if (flags->width_size && flags->period && flags->minus && (type->s || type->s_bol))
		return (width_minus_prec_str(flags->width_size, flags->prec, type_data, type));
	
	if (flags->width_size >= flags->prec && flags->period && flags->minus && !type->s && !type->s_bol)				
		return (width_minus_prec(flags->width_size, flags->prec, type_data, type->minus_d, type));
		
	if (flags->width_size >= flags->prec && flags->period && flags->zero && !type->s && !type->s_bol)
		return (width_zero_prec(flags->width_size, flags->prec, type_data, type->minus_d));

	if (flags->prec > flags->width_size && !type->s && !type->s_bol)
		return (prec_width(flags->prec, type_data, type->minus_d));
		
	if (flags->prec > flags->width_size && (type->s || type->s_bol))
		return (prec_width_str(flags->width_size, flags->prec, type_data));
		
	return (NULL);
	}