/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:22:30 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 16:50:35 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	if_null(t_var *var)
{
	char	*s1;
	int		i;

	i = -1;
	s1 = "(null)";
	VU->str = malloc(sizeof(char) * 20);
	while (s1[++i])
		(VU->str)[i] = s1[i];
	(VU->str)[i] = '\0';
	return (1);
}

int	convert_str(t_var *var)
{
	int		i;

	i = 0;
	if (VT->s_bol)
		return (if_null(var));
	VU->str = malloc(sizeof(char) * ft_strlen(VT->s) + 1);
	if (!VU->str)
		return (0);
	while ((VT->s)[i])
	{
		(VU->str)[i] = (VT->s)[i];
		i++;
	}
	(VU->str)[i] = '\0';
	return (1);
}
