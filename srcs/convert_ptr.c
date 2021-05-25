/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:19:07 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:11:00 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_ptr(t_type *type)
{
	char	*temp;
	char	*str;
	int		i;
	int		j;

	temp = NULL;
	str = NULL;
	i = 2;
	j = 0;
	temp = ft_itoa_base((unsigned long long int)type->p, "0123456789abcdef");
	if (!temp)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(temp) + 2));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	while (temp[j])
		str[i++] = temp[j++];
	free(temp);
	str[i] = '\0';
	return (str);
}
