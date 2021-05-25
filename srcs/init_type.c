/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:16:00 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:17:20 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	*init_type(t_type *types)
{
	types->c = 0;
	types->d = 0;
	types->hex = 0;
	types->HEX = 0;
	types->i = 0;
	types->p = 0;
	types->s = 0;
	types->u = 0;
	types->modulo = 0;
	types->s_bol = 0;
	types->c_bol = 0;
	types->d_bol = 0;
	types->u_bol = 0;
	types->p_bol = 0;
	types->x_bol = 0;
	types->X_bol = 0;
	types->minus_d = 0;
	return (types);
}
