/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_noflags_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:33:30 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 17:39:56 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_noflags_prec(t_var *var)
{
	int 	i;
	int 	j;
	size_t	len;
	char 	*temp;
	i = 0;
	j = 0;
	len = ft_strlen(VU->str);
	if ((len > (size_t)VF->prec) || (!VF->prec && VT->minus_d))
		return (width_noflags_noprec(var));
	if (len > (size_t)VF->width_size)
		VF->width_size = len;
	if (VF->prec == VF->width_size)
	{
		if (VT->minus_d)
		{
			VF->prec++;
			VT->minus_d++;
		}
		else
			VF->prec++;
	}
	if (len > (size_t)VF->prec)
		VF->width_size--;
	temp = malloc(sizeof(char) * (VF->width_size + 1 + VT->minus_d));
	if (!temp)
		return (0);
	while (i < (VF->width_size - VF->prec - VT->minus_d))
		temp[i++] = ' ';
	if (VT->minus_d)
		temp[i++] = (VU->str)[j++];
	while (i < (VF->width_size - (int)len + VT->minus_d))
		temp[i++] = '0';
	if(VU->str)
		while ((VU->str)[j])
			temp[i++] = (VU->str)[j++];
	free(VU->str);
	temp[i] = '\0';
	VU->str = temp;
	return (1);
}