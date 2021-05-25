/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:14:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:56:45 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_int(t_var *var)
{
	if (VF->period && !VF->prec && !VT->d && VT->d_bol)
	{
		VU->str = malloc(sizeof(char) * 1);
		if (!VU->str)
			return (0);
		VU->str[0] = '\0';
		return (1);
	}
	if (VT->d || VT->d_bol)
	{
		VU->str = ft_itoa(VT->d);
		if (!VU->str)
			return (0);
	}
	if (VT->i)
	{
		VU->str = ft_itoa(VT->i);
		if (!VU->str)
			return (0);
	}
	return (1);
}
