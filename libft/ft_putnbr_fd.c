/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 08:25:43 by mlopes-d          #+#    #+#             */
/*   Updated: 2019/11/15 08:39:45 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long big;

	big = n;
	if (big < 0)
	{
		ft_putchar_fd('-', fd);
		big = big * -1;
	}
	if (big >= 10)
	{
		ft_putnbr_fd((big / 10), fd);
		ft_putnbr_fd((big % 10), fd);
	}
	else
	{
		ft_putchar_fd((big + '0'), fd);
	}
}
