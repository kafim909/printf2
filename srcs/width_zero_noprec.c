/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_zero_noprec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:09:47 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:57:48 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_zero_noprec(t_var *var)
{
	int		len;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(VU->str);
	VF->width_size -= len;
	if (VF->width_size < 0)
		VF->width_size = 0;
	temp = malloc(sizeof(char) * (len + VF->width_size + 1 + VT->minus_d));
	if (!temp)
		return (0);
	if (VT->minus_d)
		temp[i++] = (VU->str)[j++];
	if (VF->width_size)
		while (i < VF->width_size + VT->minus_d)
			temp[i++] = '0';
	while ((VU->str[j]))
		temp[i++] = (VU->str)[j++];
	free (VU->str);
	temp[i] = '\0';
	VU->str = temp;
	return (1);
}
