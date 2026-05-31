/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:43:42 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/08/30 10:54:06 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_tokenized(char **arr, char const *s, char c)
{
	size_t			len;
	char const		*start;

	while (*s)
	{
		while (*s && *s == c)
			++s;
		start = s;
		len = 0;
		while (*s && *s != c)
		{
			++s;
			++len;
		}
		if (s > start)
		{
			*arr = ft_substr(start, 0, len);
			arr++;
		}
	}
	*arr = NULL;
}

int	count_word(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
			count++;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		size;

	if (!s)
		return (NULL);
	size = count_word(s, c);
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	str_tokenized(res, s, c);
	return (res);
}
