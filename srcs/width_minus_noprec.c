/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_noprec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:49:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:58:10 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(t_var *var, char **temp)
{
	int	i;

	i = 0;
	if (VT->c_bol)
		ft_putchar('\0');
	if (VU->str && !VT->c_bol)
	{
		while ((VU->str[i]))
		{
			(*temp)[i] = (VU->str)[i];
			i++;
		}
	}
	if (VF->width_size)
		while (i < VF->width_size)
			(*temp)[i++] = ' ';
	free(VU->str);
	(*temp)[i] = '\0';
	VU->str = *temp;
	return (1);
}

int	width_minus_noprec(t_var *var)
{
	int		len;
	char	*temp;

	temp = NULL;
	len = ft_strlen(VU->str);
	if ((VF->width_size - len) < 0)
		VF->width_size = 0;
	temp = malloc(sizeof(char) * (len + VF->width_size + 2));
	if (!temp)
		return (0);
	return (process(var, &temp));
}
