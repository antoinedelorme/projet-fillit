/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:21:22 by mlopes-d          #+#    #+#             */
/*   Updated: 2020/02/06 15:25:11 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!correct_file(argv[1]))
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
