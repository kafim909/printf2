/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:02:32 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:58:23 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prec_width_str(t_var *var)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if ((int)ft_strlen(VU->str) <= VF->prec)
		return (width_noflags_noprec(var));
	temp = malloc(sizeof(char) * (VF->prec + 1));
	if (!temp)
		return (0);
	while (i < VF->width_size - VF->prec)
		temp[i++] = ' ';
	while (i < VF->prec)
		temp[i++] = (VU->str)[j++];
	temp[i] = '\0';
	free(VU->str);
	VU->str = temp;
	return (1);
}
