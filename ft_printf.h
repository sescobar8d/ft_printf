/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:46:36 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 11:05:21 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "src/lib/libft.h"

typedef	struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
	int			num;
	int			point;
	int			asterisk;
	int			has_precission;
	size_t		precission;
	int			has_width;
	size_t		width;
}				t_flags;

const char		*ft_printsymbol(const char *str, t_flags **flags, int **count);
const char		*ft_checkflags_sym(const char *str, va_list args,
			t_flags *flags);
const char		*ft_checkflags_num(const char *str, t_flags *flags);
char			*ft_uitoa(unsigned long long int n);
char			*ft_strtoupper(char *str);
const char		*ft_printint(const char *str, va_list args, int **count,
			t_flags **flags);
int				ft_prespace(t_flags **flags, size_t length, int count,
				char filler);
int				ft_posspace(size_t width, size_t length, int count,
				char filler);
const char		*ft_printstring(const char *str, va_list args, int **count,
			t_flags **flags);
const char		*ft_printchar(const char *str, va_list args, int **count,
			t_flags **flags);
int				ft_printword(char *str, t_flags **flags, int count);
char			*ft_long_itoa(long int nbr);
char			*ft_uitohex(unsigned int q);
char			*ft_ultohex(unsigned long q);
const char		*ft_printuint(const char *str, va_list args, int **count,
			t_flags **flags);
const char		*ft_printhex(const char *str, va_list args, int **count,
			t_flags **flags);
const char		*ft_printpointer(const char *str, va_list args, int **count,
			t_flags **flags);
int				ft_isflag(char *str);
int				max_int(int a, int b);
char			*ft_strjoin_free(char *str1, char *str2, int i);
int				ft_isnum(int c);

#endif
