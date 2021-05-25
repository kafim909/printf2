/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:51:27 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 11:01:27 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	one_to_nine(char c)
{
	if (c >= 49 && c <= 57)
		return (1);
	else
		return (0);
}

int	bolcheck(t_type *type)
{
	if (type->c_bol)
		return (1);
	if (type->d_bol)
		return (1);
	if (type->p_bol)
		return (1);
	if (type->s_bol)
		return (1);
	if (type->u_bol)
		return (1);
	if (type->X_bol)
		return (1);
	if (type->x_bol)
		return (1);
	return (0);
}
