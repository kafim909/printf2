/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_noflags_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:33:30 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 16:17:33 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_noflags_prec(int width, int prec, char *type_data, int minus)
{
	int 	i;
	int 	j;
	size_t	len;
	char 	*str;

	i = 0;
	j = 0;
	len = ft_strlen(type_data);
	if ((len > (size_t)prec) || (!prec && minus))
		return (width_noflags_noprec(width, type_data));
	if (len > (size_t)width)
		width = len;
	if (prec == width)
	{
		if (minus)
		{
			prec++;
			minus++;
		}
		else
			prec++;
	}
	if (len > (size_t)prec)
		width--;
	str = malloc(sizeof(char) * (width + 1 + minus));
	if (!str)
		return (NULL);
	while (i < (width - prec - minus))
		str[i++] = ' ';
	if (minus)
		str[i++] = type_data[j++];
	while (i < (width - (int)len + minus))
		str[i++] = '0';
	if(type_data)
		while (type_data[j])
			str[i++] = type_data[j++];
	free(type_data);
	str[i] = '\0';
	return (str);
}