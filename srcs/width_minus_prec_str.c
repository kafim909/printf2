/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_prec_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:07:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:52:49 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_minus_prec_str(int width, int prec,
								char *type_data, t_type *types)
{
	int		i;
	int		j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(type_data);
	if (len < (size_t)prec)
		return (width_minus_noprec(width, type_data, types));
	str = malloc(sizeof(char) * (width + 1));
	if (!str)
		return (NULL);
	while (type_data[j] && i < prec)
		str[i++] = type_data[j++];
	while (i < width)
		str[i++] = ' ';
	free(type_data);
	str[i] = '\0';
	return (str);
}
