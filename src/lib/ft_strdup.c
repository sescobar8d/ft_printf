/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:07:30 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:07:32 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*copy;

	i = ft_strlen(s1) + 1;
	if ((copy = malloc(i)))
	{
		ft_memcpy(copy, s1, i);
		return (copy);
	}
	return (0);
}
