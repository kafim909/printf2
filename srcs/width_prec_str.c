/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_prec_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:37:24 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:46:45 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_prec_str(int width, int prec, char *type_data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if ((int)ft_strlen(type_data) <= prec)
		return (width_noflags_noprec(width, type_data));
	str = malloc(sizeof(char) * (width + 1));
	if (!str)
		return (NULL);
	while (i < width - prec)
		str[i++] = ' ';
	while (i < width)
		str[i++] = type_data[j++];
	str[i] = '\0';
	free(type_data);
	return (str);
}
