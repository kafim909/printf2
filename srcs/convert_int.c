/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:14:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:09:53 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_int(t_type *type, t_flags *flags)
{
	char	*str;

	str = NULL;
	if (flags->period && !flags->prec && !type->d && type->d_bol)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	if (type->d || type->d_bol)
		str = ft_itoa(type->d);
	if (type->i)
		str = ft_itoa(type->i);
	return (str);
}
