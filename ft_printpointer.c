/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:47:05 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:18:41 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*applyprecission_pointer(char *hex, t_flags **flags)
{
	char	*filler;

	if ((*flags)->precission >= ft_strlen(hex) && (*flags)->precission > 0)
	{
		filler = ft_calloc((*flags)->precission - ft_strlen(hex) +
				1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(hex));
		hex = ft_strjoin_free(filler, hex, 3);
	}
	hex = ft_strjoin_free("0x", hex, 2);
	return (hex);
}

char		*applywidth_pointer(char *hex, t_flags **flags)
{
	char	*filler;

	if ((*flags)->width > ft_strlen(hex))
	{
		filler = ft_calloc((*flags)->width - ft_strlen(hex) + 1, sizeof(char));
		ft_memset(filler, ((*flags)->zero == 1 ? '0' : ' '),
				(*flags)->width - ft_strlen(hex));
		if ((*flags)->minus == 0)
			hex = ft_strjoin_free(filler, hex, 3);
		else
			hex = ft_strjoin_free(hex, filler, 3);
	}
	return (hex);
}

const char	*ft_printpointer(const char *str, va_list args, int **count,
		t_flags **flags)
{
	unsigned long	i;
	char			*hex;

	i = va_arg(args, unsigned long);
	if ((((*flags)->has_precission == 1 && (*flags)->precission == 0) ||
				((*flags)->has_width == 1 && (*flags)->width == 0)) && (i == 0))
		hex = ft_strjoin("", "");
	else
		hex = ft_ultohex(i);
	hex = applyprecission_pointer(hex, flags);
	hex = applywidth_pointer(hex, flags);
	*(*(count)) += ft_strlen(hex);
	ft_putstr_fd(hex, 1);
	free(hex);
	str++;
	return (str);
}
