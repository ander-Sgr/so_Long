/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:44:30 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/16 16:09:04 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

/*
#include <stdio.h>
int main(void)
{
	int c = '8';
	if(ft_isdigit(c))
		printf("the input is digit: %c", c);
	else
		printf("no digit");
}
*/
