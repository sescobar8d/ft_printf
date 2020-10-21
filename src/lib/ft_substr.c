/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:08:51 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:08:53 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char));
	if (start > len || !s || len == 0)
	{
		new[0] = '\0';
		return (new);
	}
	if ((new = malloc((len * sizeof(char)) + 1)))
	{
		while (i < len)
		{
			new[i] = s[(int)i + start];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
