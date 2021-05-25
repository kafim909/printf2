/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:51:27 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 15:52:51 by mtournay         ###   ########.fr       */
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

int	bolcheck(t_var *var)
{
	if (VT->c_bol)
		return (1);
	if (VT->d_bol)
		return (1);
	if (VT->p_bol)
		return (1);
	if (VT->s_bol)
		return (1);
	if (VT->u_bol)
		return (1);
	if (VT->X_bol)
		return (1);
	if (VT->x_bol)
		return (1);
	return (0);
}
