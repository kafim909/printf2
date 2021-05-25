/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_noprec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:49:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 10:48:59 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process(int width, char *data_type, t_type *types, char **str)
{
	int	i;

	i = 0;
	if (types->c_bol)
		ft_putchar('\0');
	if (data_type && !types->c_bol)
	{
		while (data_type[i])
		{
			(*str)[i] = data_type[i];
			i++;
		}
	}
	if (width)
		while (i < width)
			(*str)[i++] = ' ';
	free(data_type);
	(*str)[i] = '\0';
	return (*str);
}

char	*width_minus_noprec(int width, char *data_type, t_type *types)
{
	int		len;
	char	*str;

	str = NULL;
	len = ft_strlen(data_type);
	if ((width - len) < 0)
		width = 0;
	str = malloc(sizeof(char) * (len + width + 2));
	if (!str)
		return (NULL);
	return (process(width, data_type, types, &str));
}
