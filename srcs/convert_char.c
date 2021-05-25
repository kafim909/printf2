/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:10:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:56:20 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_char(t_var *var)
{
	VU->str = malloc(sizeof(char) * 2);
	if (!VU->str)
		return (-1);
	VU->str[0] = VT->c;
	VU->str[1] = '\0';
	return (1);
}
