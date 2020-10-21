/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:06:24 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:06:25 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (!dst && !src && len > 0)
		return (0);
	s1 = (char *)src;
	s2 = (char *)dst;
	if (dst > src)
	{
		while (len--)
			s2[len] = s1[len];
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
