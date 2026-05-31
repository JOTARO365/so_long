/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:00:18 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/08/30 17:22:45 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	get_numb(long numb)
{
	long	len;

	len = 0;
	if (numb <= 0)
		len++;
	while (numb)
	{
		len++;
		numb /= 10;
	}
	return (len);
}

char	*ft_itoa(int c)
{
	long	size;
	char	*res;
	long	yeah;

	yeah = c;
	size = get_numb(yeah);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (yeah < 0)
	{
		res[0] = '-';
		yeah = -yeah;
	}
	else if (yeah == 0)
		res[0] = '0';
	while (yeah)
	{
		res[--size] = (yeah % 10) + 48;
		yeah /= 10;
	}
	return (res);
}
