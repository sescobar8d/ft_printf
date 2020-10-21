/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:06:08 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:06:09 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	unsigned char		*s2;

	i = 0;
	if (!dst && !src)
		return (0);
	s1 = (const unsigned char *)src;
	s2 = (unsigned char *)dst;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
