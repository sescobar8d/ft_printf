/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:46:46 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/22 11:06:10 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*applypreczeroes(char *num, t_flags **flags)
{
	char	*temp;

	if ((*flags)->precission >= ft_strlen(num) && (*flags)->precission > 0)
	{
		temp = ft_calloc(max_int((*flags)->precission, (*flags)->width) -
				ft_strlen(num) + 1, sizeof(char));
		ft_memset(temp, '0', (*flags)->precission - ft_strlen(num));
		num = ft_strjoin_free(temp, num, 3);
	}
	return (num);
}

char		*applywidthzeroes(char *num, t_flags **flags)
{
	char	*temp;

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

char		*applyminus(int i, char *num, t_flags **flags)
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

char		*applyspaces(char *num, t_flags **flags)
{
	char	*temp;

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

const char	*ft_printint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	int		i;
	int		neg;
	char	*num;

	i = va_arg(args, int);
	neg = ((i < 0) ? (-i) : (i));
	if (i == 0 && (*flags)->precission == 0 && (*flags)->has_precission == 1)
		num = ft_strjoin("", "");
	else
		num = ft_itoa(neg);
	num = applypreczeroes(num, flags);
	num = applywidthzeroes(num, flags);
	num = applyminus(i, num, flags);
	num = applyspaces(num, flags);
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	return (str);
}
