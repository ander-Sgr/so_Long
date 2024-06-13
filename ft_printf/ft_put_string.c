/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:01:17 by aestrell          #+#    #+#             */
/*   Updated: 2024/03/04 21:01:17 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_string(char *str)
{
	int	len_str;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len_str = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return ((int)len_str);
}
