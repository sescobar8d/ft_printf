/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:08:42 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:08:43 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*snew;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr((char *)set, s1[i]) != NULL)
		i++;
	len = ft_strlen(&s1[i]);
	if (len != 0)
		while (s1[i + len - 1]
				&& ft_strchr((char *)set, s1[i + len - 1]) != NULL)
			len--;
	if ((snew = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_memcpy(snew, &s1[i], len);
	snew[len] = '\0';
	return (snew);
}
