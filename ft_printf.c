/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:46:22 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:14:46 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize_struct(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->num = 0;
	flags->point = 0;
	flags->asterisk = 0;
	flags->has_precission = 0;
	flags->precission = 0;
	flags->has_width = 0;
	flags->width = 0;
}

char		*ft_print_variable(char *str, va_list args, int *count,
		t_flags *flags)
{
	if (*str == 'i' || *str == 'd')
		str = (char *)ft_printint(str, args, &count, &flags);
	else if (*str == '%')
		str = (char *)ft_printsymbol(str, &flags, &count);
	else if (*str == 'c')
		str = (char *)ft_printchar(str, args, &count, &flags);
	else if (*str == 's')
		str = (char *)ft_printstring(str, args, &count, &flags);
	else if (*str == 'p')
		str = (char *)ft_printpointer(str, args, &count, &flags);
	else if (*str == 'u')
		str = (char *)ft_printuint(str, args, &count, &flags);
	else if (*str == 'x' || *str == 'X')
		str = (char *)ft_printhex(str, args, &count, &flags);
	return (str);
}

int			ft_isflag(char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ' ||
		(*str == '.' && *(str + 1) == '*') ||
		(*str == '0') || *str == '#' || *str == '*')
		return (1);
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	t_flags	flags;

	count = 0;
	va_start(args, str);
	while (str && *str != '\0')
		if (*str == '%')
		{
			initialize_struct(&flags);
			str++;
			while (ft_isflag((char *)str) == 1)
				str = (char *)ft_checkflags_sym((char *)str, args, &flags);
			if (*str == '.' || (*str >= '0' && *str <= '9'))
				str = (char *)ft_checkflags_num((char *)str, &flags);
			str = (char *)ft_print_variable((char *)str, args, &count, &flags);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			count++;
		}
	va_end(args);
	return (count);
}
