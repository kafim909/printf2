/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_zero_noprec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:09:47 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:46:12 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_zero_noprec(int width, char *data_type, int minus)
{
	int		len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(data_type);
	width -= len;
	if (width < 0)
		width = 0;
	str = malloc(sizeof(char) * (len + width + 1 + minus));
	if (!str)
		return (NULL);
	if (minus)
		str[i++] = data_type[j++];
	if (width)
		while (i < width + minus)
			str[i++] = '0';
	while (data_type[j])
		str[i++] = data_type[j++];
	free (data_type);
	str[i] = '\0';
	return (str);
}
