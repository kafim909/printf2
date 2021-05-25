/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:15:28 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 18:48:32 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_utils(t_var *var)
{
	VU->len = 0;
	ix = 0;
	VU->temp = NULL;
	VU->str = NULL;
}

void	init_type(t_var *var)
{
	VT->c = 0;
	VT->d = 0;
	VT->hex = 0;
	VT->HEX = 0;
	VT->i = 0;
	VT->p = 0;
	VT->s = 0;
	VT->u = 0;
	VT->modulo = 0;
	VT->s_bol = 0;
	VT->c_bol = 0;
	VT->d_bol = 0;
	VT->u_bol = 0;
	VT->p_bol = 0;
	VT->x_bol = 0;
	VT->X_bol = 0;
	VT->minus_d = 0;
}

void	init_flags(t_var *var)
{
	VF->minus = 0;
	VF->period = 0;
	VF->prec = 0;
	VF->wd_prec = 0;
	VF->wd_width = 0;
	VF->width_size = 0;
	VF->zero = 0;
}
