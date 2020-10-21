/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:35:52 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:35:55 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			max_int(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

char		*ft_strjoin_free(char *str1, char *str2, int i)
{
	char *temp;

	temp = ft_strjoin(str1, str2);
	if (i == 1)
		free(str1);
	else if (i == 2)
		free(str2);
	if (i == 3)
	{
		free(str1);
		free(str2);
	}
	return (temp);
}

int			ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char		*ft_strtoupper(char *str)
{
	int	c;
	
	c = 0;
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		c++;
		str++;
	}
	return (str - c);
}

