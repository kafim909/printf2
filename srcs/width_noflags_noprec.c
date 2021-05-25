/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_noflags_noprec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:13:54 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 12:33:42 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width_noflags_noprec(int width, char *data_type)
{
	int 	len;
	char	*str;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	len = ft_strlen(data_type);
	width -= len;
	if (width < 0)
		width = 0;
	str = malloc(sizeof(char) * (len + width + 2));
	if (!str)
		return (NULL);
	if (width)
		while (i < width)
			str[i++] = ' ';
	if (data_type)
		while (data_type[j])
			str[i++] = data_type[j++];
	else
		str[i++] = '\0';
	free(data_type);
	str[i] = '\0';
	return (str);
}