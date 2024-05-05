/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestrell <aestrell@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:50:41 by aestrell          #+#    #+#             */
/*   Updated: 2024/02/16 17:02:51 by aestrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char separator)
{
	int	i;
	int	is_in_word;
	int	words_count;

	i = 0;
	is_in_word = 0;
	words_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == separator && is_in_word)
		{
			words_count++;
			is_in_word = 0;
		}
		else if (s[i] != separator && !is_in_word)
			is_in_word = 1;
		i++;
	}
	if (is_in_word)
		words_count++;
	return (words_count);
}

static char	**ft_free_split(char **result_split)
{
	size_t	i;

	i = 0;
	while (result_split[i])
	{
		free(result_split[i]);
		i++;
	}
	free(result_split);
	return (NULL);
}

static char	*ft_fill_word(const char *s, int start, int end)
{
	char	*str;
	int		len_str;
	int		i;

	len_str = (end - start);
	str = (char *)malloc((len_str + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len_str)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[len_str] = '\0';
	return (str);
}

static int	find_next_word(const char *s, char c, int *start, int *end)
{
	while (s[*start] != '\0' && s[*start] == c)
	{
		(*start)++;
	}
	*end = *start;
	while (s[*end] != '\0' && s[*end] != c)
	{
		(*end)++;
	}
	return (*end - *start);
}

char	**ft_split(char const *s, char c)
{
	char	**result_split;
	int		start;
	int		end;
	int		word_index;

	if (s == NULL)
		return (NULL);
	result_split = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (result_split == NULL)
		return (NULL);
	start = 0;
	end = 0;
	word_index = 0;
	while (find_next_word(s, c, &start, &end))
	{
		result_split[word_index] = ft_fill_word(s, start, end);
		if (result_split[word_index] == NULL)
			return (ft_free_split(result_split));
		word_index++;
		start = end;
	}
	result_split[word_index] = NULL;
	return (result_split);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	set;
	char	**result;
	int		i;

	str = "hello, how,,,, are, you,,";
	set = ',';
	result = ft_split(str, set);
	//int total_words = ft_count_words(str, set);
	if (result == NULL)
		printf("error agined memory");
	printf("word splitted\n");
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
}
*/
