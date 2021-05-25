/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:33:32 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/25 11:01:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct 		s_type
{
    unsigned char	c;
    void			*p;
    int				d;
    int				i;
    char			*s;
    unsigned int	u;
	unsigned int	hex;
	unsigned int	HEX;
    char            modulo;
    int             s_bol;
    int             c_bol;
    int             p_bol;
    int             d_bol;
    int             u_bol;
    int             x_bol;
    int             X_bol;
    int             minus_d;
}					t_type;

typedef struct 	s_flags
{
    int			zero;
    int			minus;
    int			wd_width;
	int 		width_size;
	int 		period;
	int 		prec;
	int 		wd_prec;
}				t_flags;

int	    bolcheck(t_type *type);
int     ft_printf(const char *s, ...);
int     is_type(char c);
t_flags   *init_flags(t_flags *flag);
t_type    *init_type(t_type *types);
t_flags   *parse_flags(char *input, int i, va_list args, t_flags *flags);
t_type    *parse_type(char c, va_list args, t_type *type);
char    *type_convert(t_type *type, t_flags *flags);
char	*ft_itoa_base(unsigned long long nbr, char *base);
int     one_to_nine(char c);

char	*convert_int(t_type *type, t_flags *flags);
char    *convert_char(t_type *type);
char	*convert_x(t_type *type);
char	*convert_modulo(void);
char	*convert_ptr(t_type *type);
char	*convert_str(t_type *type);
char	*convert_unsigned(t_type *type);

char	*unsigned_itoa(unsigned int n);
char	*data_flag_convert(t_flags *flags, char *type_data, t_type *type);
char	*width_noflags_noprec(int width, char *data_type);
char	*width_minus_noprec(int width, char *data_type, t_type *types);
char	*width_zero_noprec(int width, char *data_type, int minus);
char	*width_prec_str(int width, int prec, char *type_data);
char	*width_noflags_prec(int width, int prec, char *type_data, int minus);
char	*width_minus_prec(int width, int prec, char *type_data, int minus, t_type *type);
char	*width_minus_prec_str(int width, int prec, char *type_data, t_type *types);
char	*width_zero_prec(int width, int prec, char *type_data, int i);
char	*prec_width(int prec, char *type_data, int minus);
char	*prec_width_str(int width, int prec, char *type_data);
char	*join(char **s1,char **s2);

#endif 