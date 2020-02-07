/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:01:51 by mlopes-d          #+#    #+#             */
/*   Updated: 2019/11/18 13:44:14 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char chr[2];

	if (c >= 0)
	{
		write(1, &c, 1);
		return ;
	}
	chr[0] = (c >= -64) ? 195 : 194;
	chr[1] = (c >= -64) ? c + 192 : c + 256;
	write(1, chr, 2);
}