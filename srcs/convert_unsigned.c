/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:35:46 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:57:04 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_unsigned(t_var *var)
{
	VU->str = unsigned_itoa(VT->u);
	if (!VU->str)
		return (0);
	return (1);
}
