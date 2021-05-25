/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_HEX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:20:06 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:56:42 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_x(t_var *var)
{
	if (VT->HEX || VT->X_bol)
	{
		VU->str = ft_itoa_base(VT->HEX, "0123456789ABCDEF");
		if (!VU->str)
			return (0);
	}
	if (VT->hex || VT->x_bol)
	{
		VU->str = ft_itoa_base(VT->hex, "0123456789abcdef");
		if (!VU->str)
			return (0);
	}
	return (1);
}
