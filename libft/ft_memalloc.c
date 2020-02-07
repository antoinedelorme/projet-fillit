/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 07:19:18 by mlopes-d          #+#    #+#             */
/*   Updated: 2019/11/14 11:37:25 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memoire;

	memoire = malloc(size);
	if (memoire)
	{
		ft_bzero(memoire, size);
		return (memoire);
	}
	return (NULL);
}
