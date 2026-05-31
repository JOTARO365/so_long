/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:16:32 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/08/27 17:47:32 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		len;
	size_t		to_cp;

	len = ft_strlen(src);
	to_cp = len;
	if (dstsize > 0)
	{
		if (to_cp >= dstsize)
			to_cp = dstsize - 1;
		ft_memcpy(dst, src, to_cp);
		dst[to_cp] = '\0';
	}
	return (len);
}
