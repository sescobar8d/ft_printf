/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescobar <sescobar@student.42madrid.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:06:43 by sescobar          #+#    #+#             */
/*   Updated: 2020/10/21 10:06:44 by sescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			temp;
	unsigned int	c;

	if (n < 0)
	{
		c = -n;
		write(fd, "-", 1);
	}
	else
		c = n;
	if (c >= 10)
	{
		ft_putnbr_fd(c / 10, fd);
	}
	temp = (c % 10) + '0';
	write(fd, &temp, 1);
}
