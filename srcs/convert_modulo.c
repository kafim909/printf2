/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_modulo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:13:40 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:56:48 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_modulo(t_var *var)
{
	VU->str = malloc(sizeof(char) * 2);
	if (!VU->str)
		return (0);
	VU->str[0] = '%';
	VU->str[1] = '\0';
	return (1);
}
