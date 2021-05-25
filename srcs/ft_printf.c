/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:36:21 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 17:14:38 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_var	*var;
	va_list args;
	int 	start;
	int 	ret;

	start = 0;
	ret = 0;
	var = malloc(sizeof(t_var));
	VF = malloc(sizeof(t_flags));
	VU = malloc(sizeof(t_utils));
	VT = malloc(sizeof(t_type));
	// if (!var)
	// 	return (-1);
    va_start(args, s);
	init_utils(var);
	while (s[ix])
	{	
		init_flags(var);
		init_type(var);
		start = ix;
		while (s[ix] && s[ix] != '%')
			ix++;
		if (start != ix)
		{
			VU->temp = ft_substr((char *)s, start, ix - start);
			ft_putstr(VU->temp); 
			ret += ft_strlen(VU->temp); 
			free(VU->temp);
			VU->temp = NULL;
		}      		
		if (s[ix] == '%')
		{
			var = parse_flags((char *)s, ix, args, var);
			ix++;
		}
		while (s[ix] && !is_type(s[ix]))
			ix++;
		if (is_type(s[ix]))
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
		}
		if (VU->str || bolcheck(var))
		{
			ft_putstr(VU->str);
			if (VT->c_bol && !VF->minus)
				ft_putchar('\0');
			ret += ft_strlen(VU->str); 
			free(VU->str);
			VU->str = NULL;
		}
		if (s[ix])
			ix++;
		ret += VT->c_bol;
		null_char += VT->c_bol;
	}
	va_end(args);
	// if (ptr_type->c_bol && !ptr_flags->minus)
	// {
	// 	while (null_char)
	// 	{
	// 		ft_putchar('\0');
	// 		null_char--;
	// 	}
	// }
	free(VF);
	free(VU);
	free(VT);
	free(var);
	// printf("coucou\n");
	return (ret);
}