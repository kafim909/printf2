/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:22:30 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:11:42 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*if_null(char *str)
{
	char	*s1;
	int		i;

	i = -1;
	s1 = "(null)";
	str = malloc(sizeof(char) * 20);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*convert_str(t_type *type)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (type->s_bol)
		return (if_null(str));
	str = malloc(sizeof(char) * ft_strlen(type->s) + 1);
	if (str == NULL)
		return (NULL);
	while ((type->s)[i])
	{
		str[i] = (type->s)[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
