/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_HEX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:20:06 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:07:09 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_x(t_type *type)
{
	char	*str;

	str = NULL;
	if (type->HEX || type->X_bol)
	{
		str = ft_itoa_base(type->HEX, "0123456789ABCDEF");
		if (!str)
			return (NULL);
	}
	if (type->hex || type->x_bol)
	{
		str = ft_itoa_base(type->hex, "0123456789abcdef");
		if (!str)
			return (NULL);
	}
	return (str);
}
