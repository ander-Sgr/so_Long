/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 01:02:43 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/17 18:48:02 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <ctype.h>
#include <stdio.h>

void	to_lowercase(unsigned int index, char *c)
{
	if (index % 2 != 0)
		*c = ft_toupper(*c);
}
int	main(void)
{
	char	str[];

	str[] = "Hello Word!";
	ft_striteri(str, &to_lowercase);
	printf("result: %s\n", str);
}
*/
