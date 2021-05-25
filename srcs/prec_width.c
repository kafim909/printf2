/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:51:24 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:46:29 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prec_width(int prec, char *type_data, int minus)
{
	int		i;
	int		j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	len = ft_strlen(type_data);
	if (minus && len <= (size_t)prec)
		minus++;
	if (len > (size_t)prec)
		prec = (int)len;
	str = malloc(sizeof(char) * (prec + 1 + minus));
	if (!str)
		return (NULL);
	if (minus)
		str[i++] = type_data[j++];
	while (i < (prec - (int)len) + minus)
		str[i++] = '0';
	while (type_data[j])
		str[i++] = type_data[j++];
	str[i] = '\0';
	free(type_data);
	return (str);
}
