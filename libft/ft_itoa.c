/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 07:46:57 by mlopes-d          #+#    #+#             */
/*   Updated: 2019/11/18 08:51:46 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		size;
	long	nb;

	nb = n;
	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char		*ft_itoa(int nb)
{
	char	*str;
	long	nbr;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_size(nb) + 1)))
		return (NULL);
	if (nb < 0)
		str[0] = '-';
	nbr = nb;
	if (nbr < 0)
		nbr = -nbr;
	str[ft_size(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_size(nb) - i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_size(nb) - i++] = (nbr % 10) + 48;
	return (str);
}
