/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:46:53 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 18:13:44 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(t_var *var, int i, int j, size_t len)
{
	char	*temp;

	temp = malloc(sizeof(char) * (VF->width_size + 2 + VT->minus_d));
	if (!temp)
		return (0);
	if (VT->minus_d)
	{
		temp[i++] = (VU->str)[j++];
		VT->minus_d++;
	}
	while (i < (VF->prec - (int)len + VT->minus_d))
		temp[i++] = '0';
	if (VU->str)
		while ((VU->str)[j])
			temp[i++] = (VU->str)[j++];
	while (i < VF->width_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	free(VU->str);
	VU->str = temp;
	return (1);
}

int	width_minus_prec(t_var *var)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(VU->str);
	if (len > (size_t)VF->prec)
		return (width_minus_noprec(var));
	if (len > (size_t)VF->width_size)
		VF->width_size = (int)len;
	return (process(var, i, j, len));
}
