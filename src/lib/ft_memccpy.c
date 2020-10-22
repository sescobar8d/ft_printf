/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:05:48 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/22 11:31:56 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		count;

	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	count = -1;
	while (++count < n)
	{
		*(ptr_dst + count) = *(ptr_src + count);
		if (ptr_src[count] == (char)c)
			return (ptr_dst + count + 1);
	}
	return (0);
}
