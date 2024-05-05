/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:18:43 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/16 17:33:10 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_get_first_pos(char const *str, char const *set)
{
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = ft_strlen(str);
	while (i < len_str)
	{
		if (!ft_strchr(set, str[i]))
			break ;
		i++;
	}
	return (i);
}

static int	ft_get_last_pos(char const *str, char const *set)
{
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = ft_strlen(str);
	while (i < len_str)
	{
		if (ft_strchr(set, str[len_str - i - 1]) == 0)
			break ;
		i++;
	}
	return (len_str - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_result;
	int		len_trim;
	int		start;
	int		end;

	start = ft_get_first_pos(s1, set);
	end = ft_get_last_pos(s1, set);
	len_trim = (ft_get_last_pos(s1, set) - ft_get_first_pos(s1, set));
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	if (start >= end)
		return (ft_strdup(""));
	trim_result = (char *)malloc((len_trim + 1) * sizeof(char));
	if (trim_result == NULL)
		return (NULL);
	ft_strlcpy(trim_result, s1 + start, len_trim + 1);
	return (trim_result);
}

/*
int	main(void)
{
	char const	*str;
	char const	*set;
	char		*result_trim;
	int			start;
	int			end;
	int			total;

	str = "abc";
	set = "ab";
	result_trim = ft_strtrim(str, "");
	printf("result trim : %s\n", result_trim);
	
	start = ft_get_first_pos(str, set);
	end = ft_get_last_pos(str, set);
	total = ft_total_len(str, set);
	printf("total len: %d\n", total);
	printf("pos init : %d\n", start);
	printf("post final : %d\n", end);
}
*/
