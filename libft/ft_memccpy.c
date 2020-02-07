/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:47:30 by mlopes-d          #+#    #+#             */
/*   Updated: 2019/11/13 07:54:21 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, \
		const void *restrict src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char*)src;
	tmp2 = (unsigned char*)dst;
	while (i < n)
	{
		tmp2[i] = tmp1[i];
		if (tmp1[i] == (unsigned char)c)
			return ((void*)&tmp2[i + 1]);
		i++;
	}
	return (NULL);
}
