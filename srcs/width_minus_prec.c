/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:46:53 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:23:53 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_minus_prec(int width, int prec, char *type_data, int minus, t_type *type)
{
	int 	i;
	int 	j;
	size_t	len;
	char 	*str;

	i = 0;
	j = 0;
	len = ft_strlen(type_data);
	if (len > (size_t)prec)
		return (width_minus_noprec(width, type_data, type));
	if (len > (size_t)width)
		width = (int)len;
	str = malloc(sizeof(char) * (width + 2 + minus));
	if (minus)
	{
		str[i++] = type_data[j++];
		minus++;
	}
	while (i < (prec - (int)len + minus))
		str[i++] = '0';
	if (type_data)
		while (type_data[j])
			str[i++] = type_data[j++];
	while (i < width)
		str[i++] = ' ';
	str[i] = '\0';
	free(type_data);
	return (str);
}
