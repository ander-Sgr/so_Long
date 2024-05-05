/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:13:22 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/11 14:13:22 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;

	n_long = n;
	if (n_long < 0)
	{
		ft_putchar_fd('-', fd);
		n_long = -n_long;
	}
	if (n_long >= 10)
	{
		ft_putnbr_fd(n_long / 10, fd);
	}
	ft_putchar_fd(n_long % 10 + '0', fd);
}
