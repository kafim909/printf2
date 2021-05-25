/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:47:50 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:35:20 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*init_flags(t_flags *flag)
{
	flag->minus = 0;
	flag->period = 0;
	flag->prec = 0;
	flag->wd_prec = 0;
	flag->wd_width = 0;
	flag->width_size = 0;
	flag->zero = 0;
	return (flag);
}
