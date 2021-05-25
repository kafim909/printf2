/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_zero_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:25:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 18:19:45 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(t_var *var, int i, int j, size_t len)
{
	char	*temp;

	temp = malloc(sizeof(char) * (VF->width_size + 1 + VT->minus_d));
	if (!temp)
		return (0);
	while (i < (VF->width_size - VF->prec - VT->minus_d)
		&& !(len == (size_t)VF->width_size))
		temp[i++] = ' ';
	if (VT->minus_d)
		temp[i++] = (VU->str)[j++];
	while (i < (VF->width_size - (int)len + VT->minus_d)
		&& !(len == (size_t)VF->width_size))
		temp[i++] = '0';
	while ((VU->str)[j])
		temp[i++] = (VU->str)[j++];
	temp[i] = '\0';
	free(VU->str);
	VU->str = temp;
	return (1);
}

int	width_zero_prec(t_var *var)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(VU->str);
	if ((len > (size_t)VF->prec) || (!VF->prec && VT->minus_d)
		|| (len >= (size_t)VF->prec && !VU->str))
		return (width_noflags_noprec(var));
	if (len > (size_t)VF->width_size)
		VF->width_size = (int)len;
	if (VF->prec == VF->width_size && VT->minus_d)
		VF->width_size++;
	if (len > (size_t)VF->prec)
		VF->width_size--;
	return (process(var, i, j, len));
}
