/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:00:42 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/10 17:00:42 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_integer(int nbr)
{
	int		number_len;
	char	*ptr_nbr;

	ptr_nbr = ft_itoa(nbr);
	number_len = ft_strlen(ptr_nbr);
	ft_putnbr_fd(nbr, 1);
	free(ptr_nbr);
	return ((int)number_len);
}
