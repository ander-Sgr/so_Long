/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:02:00 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/23 00:02:00 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_put_char(char c);
int		ft_put_string(char *str);
int		ft_put_integer(int nbr);
int		ft_put_unsigned(unsigned int nbr);
char	*ft_convert_to_hex(unsigned long long number, char flag);
int		ft_put_pointer(void *ptr);
int		ft_put_hexadecimal(unsigned int ptr, char flag);

#endif
