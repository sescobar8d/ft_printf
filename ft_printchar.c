/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:59:54 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/22 11:00:03 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printchar(const char *str, va_list args, int **count,
		t_flags **flags)
{
	char	c;
	size_t	i;

	i = 0;
	c = va_arg(args, int);
	if ((*flags)->width > 0 && (*flags)->minus == 0)
	{
		while (i < (*flags)->width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
			(*(*count))++;
		}
	}
	ft_putchar_fd(c, 1);
	(*(*count))++;
	str++;
	if ((*flags)->width > 0 && (*flags)->minus == 1)
		while (i < (*flags)->width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
			(*(*count))++;
	}
return (str);
}
