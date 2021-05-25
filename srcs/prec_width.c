/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:51:24 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:58:20 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prec_width(t_var *var)
{
	int		i;
	int		j;
	size_t	len;
	char	*temp;

	i = 0;
	j = 0;
	len = ft_strlen(VU->str);
	if (VT->minus_d && len <= (size_t)VF->prec)
		VT->minus_d++;
	if (len > (size_t)VF->prec)
		VF->prec = (int)len;
	temp = malloc(sizeof(char) * (VF->prec + 1 + VT->minus_d));
	if (!temp)
		return (0);
	if (VT->minus_d)
		temp[i++] = (VU->str)[j++];
	while (i < (VF->prec - (int)len) + VT->minus_d)
		temp[i++] = '0';
	while ((VU->str)[j])
		temp[i++] = (VU->str)[j++];
	temp[i] = '\0';
	free(VU->str);
	VU->str = temp;
	return (1);
}
