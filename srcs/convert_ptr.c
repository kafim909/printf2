/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:19:07 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 11:21:39 by mtournay         ###   ########.fr       */
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
	str = malloc(sizeof(char) * (ft_strlen(temp) + 10));
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
