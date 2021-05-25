/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:18:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:31:49 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static t_flags	*parse_flags_2(char *input, int i, va_list args, t_flags *flags)
{
	if (ft_isdigit(input[i]) && !flags->wd_width)
		flags->width_size = atoi(input + i);
	while (ft_isdigit(input[i]))
		i++;
	if (input[i] == '.' && input[i++])
	{
		flags->period = 1;
		if (input[i] == '*')
		{
			flags->prec = va_arg(args, int);
			flags->wd_prec = 1;
		}
		else
			flags->prec = atoi(input + i);
	}
	return (flags);
}

t_flags	*parse_flags(char *input, int i, va_list args, t_flags *flags)
{
	if (input[i] == '%')
		i++;
	while (!is_type(input[i]) && input[i] != '.' && input[i] != '*'
		&& !one_to_nine(input[i]) && input[i])
	{
		if (input[i] == '0')
			flags->zero = 1;
		if (input[i] == '-')
			flags->minus = 1;
		i++;
	}
	if (input[i] == '*')
	{
		flags->width_size = va_arg(args, int);
		flags->wd_width = 1;
		if (flags->width_size < 0)
		{
			flags->width_size *= -1;
			flags->minus = 1;
		}
		i++;
	}
	return (parse_flags_2(input, i, args, flags));
}
