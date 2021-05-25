/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:02:32 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:47:15 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prec_width_str(int width, int prec, char *type_data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if ((int)ft_strlen(type_data) <= prec)
		return (width_noflags_noprec(width, type_data));
	str = malloc(sizeof(char) * (prec + 1));
	if (!str)
		return (NULL);
	while (i < width - prec)
		str[i++] = ' ';
	while (i < prec)
		str[i++] = type_data[j++];
	str[i] = '\0';
	free(type_data);
	return (str);
}
