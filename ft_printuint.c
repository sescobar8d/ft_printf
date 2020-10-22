/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:47:27 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/22 11:11:43 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*applyprecissionzeroes_uint(char *num, t_flags **flags)
{
	char *temp;

	if ((*flags)->precission >= ft_strlen(num) && (*flags)->precission > 0)
	{
		temp = ft_calloc(max_int((*flags)->precission, (*flags)->width) -
				ft_strlen(num) + 1, sizeof(char));
		ft_memset(temp, '0', (*flags)->precission - ft_strlen(num));
		num = ft_strjoin_free(temp, num, 3);
	}
	return (num);
}

char		*applywidthzeroes_uint(char *num, t_flags **flags)
{
	char *temp;

	if ((*flags)->width > ft_strlen(num) && (*flags)->zero == 1)
	{
		temp = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(temp, '0', (*flags)->width - ft_strlen(num));
		if ((*flags)->minus == 0)
			num = ft_strjoin_free(temp, num, 3);
		else
			num = ft_strjoin_free(num, temp, 3);
	}
	return (num);
}

char		*applyminus_uint(char *num, long int i, t_flags **flags)
{
	if (i < 0)
	{
		if (*num == '0' && (*flags)->width == ft_strlen(num))
			*num = '-';
		else if (*num != '-')
			num = ft_strjoin_free("-", num, 2);
	}
	return (num);
}

char		*applyspaces_uint(char *num, t_flags **flags)
{
	char *temp;

	if ((*flags)->width > ft_strlen(num))
	{
		temp = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(temp, ' ', (*flags)->width - ft_strlen(num));
		if ((*flags)->minus == 0)
			num = ft_strjoin_free(temp, num, 3);
		else
			num = ft_strjoin_free(num, temp, 3);
	}
	return (num);
}

const char	*ft_printuint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	unsigned int			i;
	unsigned long long	int neg;
	char					*num;

	i = va_arg(args, long int);
	neg = ((i < 0) ? (-i) : (i));
	if (i == 0 && (*flags)->precission == 0 && (*flags)->has_precission == 1)
		num = ft_strjoin("", "");
	else
		num = ft_uitoa(neg);
	num = applyprecissionzeroes_uint(num, flags);
	num = applywidthzeroes_uint(num, flags);
	num = applyminus_uint(num, i, flags);
	num = applyspaces_uint(num, flags);
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	va_end(args);
	return (str);
}
