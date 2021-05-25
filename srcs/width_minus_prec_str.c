/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_prec_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:07:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:58:04 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_minus_prec_str(t_var *var)
{
	int		i;
	int		j;
	size_t	len;
	char	*temp;

	i = 0;
	j = 0;
	len = ft_strlen(VU->str);
	if (len < (size_t)VF->prec)
		return (width_minus_noprec(var));
	temp = malloc(sizeof(char) * (VF->width_size + 10));
	if (!temp)
		return (0);
	while ((VU->str)[j] && i < VF->prec)
		temp[i++] = (VU->str)[j++];
	while (i < VF->width_size)
		temp[i++] = ' ';
	free(VU->str);
	temp[i] = '\0';
	VU->str = temp;
	return (1);
}
