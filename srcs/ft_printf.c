/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:36:21 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 11:05:09 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int 	i;
	int		start;
	char 	*temp;
	char	*data;
	va_list args;
    t_type 	*ptr_type;
	t_flags	*ptr_flags;
	size_t	len;
	int 	null_char;

	i = 0;
	start = 0;
	len = 0;
	temp = NULL;
	data = NULL;
	null_char = 0;
    va_start(args, s);
	ptr_type = malloc(sizeof(t_type));
	ptr_flags = malloc(sizeof(t_flags));
	while (s[i])
	{
		ptr_flags = init_flags(ptr_flags);
		ptr_type = init_type(ptr_type);
		start = i;
		while (s[i] && s[i] != '%')
			i++;
		if (start != i)
		{
			temp = ft_substr((char *)s, start, i - start);
			ft_putstr(temp); 
			len += ft_strlen(temp); 
			free(temp);
			temp = NULL;
		}      		
		if (s[i] == '%')
		{
			ptr_flags = parse_flags((char *)s, i, args, ptr_flags);
			i++;
		}
		while (s[i] && !is_type(s[i]))
			i++;
		if (is_type(s[i]))
		{
			ptr_type = parse_type(s[i], args, ptr_type);
			if (ptr_flags->width_size && ptr_type->c_bol)
				ptr_flags->width_size--;
			if (ptr_flags->wd_prec && ptr_flags->prec < 0)
			{
				ptr_flags->prec = 0;
				ptr_flags->period = 0;
				ptr_flags->wd_prec = 0;
			}
			data = type_convert(ptr_type, ptr_flags);
			data = data_flag_convert(ptr_flags, data, ptr_type);
		}
		if (data || bolcheck(ptr_type))
		{
			ft_putstr(data);
			len += ft_strlen(data); 
			free(data);
			data = NULL;
		}
		if (s[i])
			i++;
		len += ptr_type->c_bol;
		null_char += ptr_type->c_bol;
	}
	va_end(args);
	if (ptr_type->c_bol && !ptr_flags->minus)
	{
		while (null_char)
		{
			ft_putchar('\0');
			null_char--;
		}
	}
	free(ptr_flags);
	free(ptr_type);
	return ((int)len);
}