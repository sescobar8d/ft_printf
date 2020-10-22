/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:46:57 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/22 11:01:22 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*applyprecission_hex(char *hex, t_flags **flags)
{
	char *temp;

	if ((*flags)->precission >= ft_strlen(hex) && (*flags)->precission > 0)
	{
		temp = ft_calloc((*flags)->precission - ft_strlen(hex) +
				1, sizeof(char));
		ft_memset(temp, '0', (*flags)->precission - ft_strlen(hex));
		hex = ft_strjoin_free(temp, hex, 3);
	}
	return (hex);
}

char		*applywidth_hex(char *hex, t_flags **flags)
{
	char *temp;

	if ((*flags)->width > ft_strlen(hex))
	{
		temp = ft_calloc((*flags)->width - ft_strlen(hex) + 1, sizeof(char));
		ft_memset(temp, ((*flags)->zero == 1 ? '0' : ' '),
				(*flags)->width - ft_strlen(hex));
		if ((*flags)->minus == 0)
			hex = ft_strjoin_free(temp, hex, 3);
		else
			hex = ft_strjoin_free(hex, temp, 3);
	}
	return (hex);
}

const char	*ft_printhex(const char *str, va_list args, int **count,
		t_flags **flags)
{
	unsigned int	i;
	char			*hex;

	i = va_arg(args, unsigned int);
	if ((((*flags)->has_precission == 1 && (*flags)->precission == 0) ||
			((*flags)->has_width == 1 && (*flags)->width == 0)) && (i == 0))
		hex = ft_strjoin("", "");
	else
		hex = ft_uitohex(i);
	hex = applyprecission_hex(hex, flags);
	hex = applywidth_hex(hex, flags);
	if (*str == 'X')
		hex = ft_strtoupper(hex);
	*(*(count)) += ft_strlen(hex);
	ft_putstr_fd(hex, 1);
	free(hex);
	str++;
	return (str);
}
