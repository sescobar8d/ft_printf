/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsymbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:47:20 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:19:53 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printsymbol(const char *str, t_flags **flags, int **count)
{
	size_t	t;

	t = 0;
	if ((*flags)->minus == 0 && (*flags)->width > 0)
		while (t < ((*flags)->width - 1))
		{
			ft_putchar_fd((((*flags)->zero == 1) ? '0' : ' '), 1);
			(*(*count))++;
			t++;
		}
	ft_putchar_fd('%', 1);
	(*(*count))++;
	str++;
	if ((*flags)->minus == 1 && (*flags)->width > 0)
		while (t < ((*flags)->width - 1))
		{
			ft_putchar_fd((((*flags)->zero == 1) ? '0' : ' '), 1);
			(*(*count))++;
			t++;
		}
	return (str);
}
