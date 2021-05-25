/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:19:07 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:56:50 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_ptr(t_var *var)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 2;
	j = 0;
	temp = ft_itoa_base((unsigned long long int)VT->p, "0123456789abcdef");
	if (!temp)
		return (0);
	VU->str = malloc(sizeof(char) * (ft_strlen(temp) + 10));
	if (!VU->str)
		return (0);
	VU->str[0] = '0';
	VU->str[1] = 'x';
	while (temp[j])
		VU->str[i++] = temp[j++];
	free(temp);
	VU->str[i] = '\0';
	return (1);
}
