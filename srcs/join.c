/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:56:49 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 17:22:41 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "../includes/ft_printf.h"

static char	*cpy(char *str, char **s1, char **s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*s1)
	{
		while ((*s1)[j])
			str[i++] = (*s1)[j++];
		free(*s1);
		*s1 = NULL;
	}
	j = 0;
	if (*s2)
	{
		while ((*s2)[j] != '\0')
			str[i++] = (*s2)[j++];
		free(*s2);
		*s2 = NULL;
	}
	str[i] = '\0';
	return (str);
}

char	*join(char **s1, char **s2)
{
	size_t	tot;
	char	*str;

	tot = ft_strlen(*s1) + ft_strlen(*s2);
	str = malloc(sizeof(char) * (tot + 2));
	return (cpy(str, s1, s2));
}
