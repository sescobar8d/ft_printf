/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:47:13 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:54:43 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printstring(const char *str, va_list args, int **count,
		t_flags **flags)
{
	char	*c;

	c = va_arg(args, char*);
	if ((*flags)->minus == 0 && (*flags)->width > 0 &&
			(c != NULL && *c != '\0'))
		(*(*count)) = ft_prespace((&(*flags)), ft_strlen(c), *(*(count)),
				((*flags)->zero == 0 ? ' ' : '0'));
	(*(*count)) = ft_printword(c, &(*flags), (*(*count)));
	if ((*flags)->minus == 1 && (*flags)->width > 0 &&
			(c != NULL && *c != '\0'))
		(*(*count)) = ft_prespace((&(*flags)), ft_strlen(c), *(*(count)), ' ');
	str++;
	return (str);
}
