/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:40:01 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:40:03 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prespace(t_flags **flags, size_t length, int count, char filler)
{
	int	t;
	int	dif;

	t = 0;
	dif = (int)(*flags)->width - (int)length;
	if (length == 0)
		t += 6;
	if ((*flags)->has_precission == 1 && (*flags)->has_width == 1)
		while ((t < dif) || (t < ((int)(*flags)->width -
						(int)(*flags)->precission)))
		{
			ft_putchar_fd(filler, 1);
			count++;
			t++;
		}
	else
		while ((t < dif) && (t < ((int)(*flags)->width -
						(int)(*flags)->precission)))
		{
			ft_putchar_fd(filler, 1);
			count++;
			t++;
		}
	return (count);
}

int	ft_uintlength(unsigned long long int n)
{
	if (n < 10)
		return (1);
        else
		return (ft_uintlength(n / 10) + 1);
}

char		*ft_uitoa(unsigned long long int n)
{
	char	*str;
	int		len;
	
	len = ft_uintlength(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (len == 0)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (str);
}

