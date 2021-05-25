/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:18:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 13:37:52 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static t_var	*parse_flags_2(char *input, int i, va_list args, t_var *var)
{
	if (ft_isdigit(input[i]) && !VF->wd_width)
		VF->width_size = atoi(input + i);
	while (ft_isdigit(input[i]))
		i++;
	if (input[i] == '.' && input[i++])
	{
		VF->period = 1;
		if (input[i] == '*')
		{
			VF->prec = va_arg(args, int);
			VF->wd_prec = 1;
		}
		else
			VF->prec = atoi(input + i);
	}
	return (var);
}

t_var	*parse_flags(char *input, int i, va_list args, t_var *var)
{
	if (input[i] == '%')
		i++;
	while (!is_type(input[i]) && input[i] != '.' && input[i] != '*'
		&& !one_to_nine(input[i]) && input[i])
	{
		if (input[i] == '0')
			VF->zero = 1;
		if (input[i] == '-')
			VF->minus = 1;
		i++;
	}
	if (input[i] == '*')
	{
		VF->width_size = va_arg(args, int);
		VF->wd_width = 1;
		if (VF->width_size < 0)
		{
			VF->width_size *= -1;
			VF->minus = 1;
		}
		i++;
	}
	return (parse_flags_2(input, i, args, var));
}
