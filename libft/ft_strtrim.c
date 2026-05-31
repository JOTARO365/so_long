/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:41:13 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/08/28 17:55:25 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*str1;
	const char	*str2;
	size_t		i;
	char		*res;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	str1 = s1;
	str2 = ft_strchr(s1, '\0');
	while (str2 > str1 && ft_strchr(set, *(str2 - 1)))
		str2--;
	i = str2 - str1;
	if (i == 0)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, str1, (i + 1));
	return (res);
}
