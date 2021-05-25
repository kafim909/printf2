/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:36:21 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 19:03:16 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_1(t_var *var, const char *s, int start)
{
	VU->temp = ft_substr((char *)s, start, ix - start);
	if (!VU->temp)
		return (-1);
	ft_putstr(VU->temp);
	VU->len += ft_strlen(VU->temp);
	free(VU->temp);
	VU->temp = NULL;
	return (1);
}

static int	process_2(va_list args, const char *s, t_var *var)
{
	var = parse_type(s[ix], args, var);
	if (VF->width_size && VT->c_bol)
	{
		VF->width_size--;
		if (!VF->width_size)
			ft_putchar('\0');
	}
	if (VF->wd_prec && VF->prec < 0)
	{
		VF->prec = 0;
		VF->period = 0;
		VF->wd_prec = 0;
	}
	if (!type_convert(var))
		return (-1);
	if (!data_flag_convert(var))
		return (-1);
	return (1);
}

static int	process_4(const char *s, va_list args, t_var *var)
{
	while (s[ix] && !is_type(s[ix]))
		ix++;
	if (is_type(s[ix]))
		if (!process_2(args, s, var))
			return (-1);
	if (VU->str || bolcheck(var))
	{
		ft_putstr(VU->str);
		if (VT->c_bol && !VF->minus)
			ft_putchar('\0');
		VU->len += ft_strlen(VU->str);
		free(VU->str);
		VU->str = NULL;
	}
	if (s[ix])
		ix++;
	VU->len += VT->c_bol;
	return (1);
}

static int	process_3(t_var *var, const char *s, va_list args, int start)
{
	while (s[ix])
	{	
		init_flags(var);
		init_type(var);
		start = ix;
		while (s[ix] && s[ix] != '%')
			ix++;
		if (start != ix)
			if (!process_1(var, s, start))
				return (-1);
		if (s[ix] == '%')
		{
			var = parse_flags((char *)s, ix, args, var);
			ix++;
		}
		if (!process_4(s, args, var))
			return (-1);
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	t_var	*var;
	va_list	args;
	int		start;
	int		ret;

	start = 0;
	ret = 0;
	var = malloc(sizeof(t_var));
	VF = malloc(sizeof(t_flags));
	VU = malloc(sizeof(t_utils));
	VT = malloc(sizeof(t_type));
	va_start(args, s);
	init_utils(var);
	if (!process_3(var, s, args, start))
		return (-1);
	va_end(args);
	ret = VU->len;
	free(VF);
	free(VU);
	free(VT);
	free(var);
	return (ret);
}
