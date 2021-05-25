/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:35:46 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:11:58 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_unsigned(t_type *type)
{
	char	*str;

	str = unsigned_itoa(type->u);
	if (!str)
		return (NULL);
	return (str);
}
