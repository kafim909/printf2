/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_noflags_noprec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:13:54 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 18:13:29 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(t_var *var, int len, int i, int j)
{
	char	*temp;

	temp = malloc(sizeof(char) * (len + VF->width_size + 2));
	if (!temp)
		return (0);
	if (VF->width_size)
		while (i < VF->width_size)
			temp[i++] = ' ';
	if (VU->str)
		while ((VU->str)[j])
			temp[i++] = (VU->str)[j++];
	else
		temp[i++] = '\0';
	free(VU->str);
	temp[i] = '\0';
	VU->str = temp;
	return (1);
}

int	width_noflags_noprec(t_var *var)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(VU->str);
	VF->width_size -= len;
	if (VF->width_size < 0)
		VF->width_size = 0;
	return (process(var, len, i, j));
}
