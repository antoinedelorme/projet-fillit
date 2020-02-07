/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:49:02 by mlopes-d          #+#    #+#             */
/*   Updated: 2019/11/12 12:54:55 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict d, const char *restrict src, size_t nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (d[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		d[i] = src[j];
		i++;
		j++;
	}
	d[i] = '\0';
	return (char*)(d);
}
