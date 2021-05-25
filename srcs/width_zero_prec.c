/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_zero_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:25:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/20 17:39:17 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_zero_prec(int width, int prec, char *type_data, int minus)
{
	int		i;
	int		j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(type_data);
	if ((len > (size_t)prec) || (!prec && minus) || (len >= (size_t)prec && !type_data))
		return (width_noflags_noprec(width, type_data));
	if (len > (size_t)width)
		width = (int)len;
	if (prec == width && minus)
		width++;
	if (len > (size_t)prec)
		width--;
	str = malloc(sizeof(char) * (width + 1 + minus));
	if (!str)
		return (NULL);
	while (i < (width - prec - minus) && !(len == (size_t)width))
		str[i++] = ' ';
	if (minus)
		str[i++] = type_data[j++];
	while (i < (width - (int)len + minus) && !(len == (size_t)width))
		str[i++] = '0';
	while (type_data[j])
		str[i++] = type_data[j++];
	str[i] = '\0';
	free(type_data);
	return (str);
}