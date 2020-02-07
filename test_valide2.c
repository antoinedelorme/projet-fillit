/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valide2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:21:57 by mlopes-d          #+#    #+#             */
/*   Updated: 2020/01/29 09:22:01 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_nb_diese(char *str)
{
	int	nb_diese;

	nb_diese = 0;
	while (*str)
	{
		if (*str == '#')
			nb_diese++;
		str++;
	}
	if (nb_diese != 4)
		return (0);
	return (1);
}

int		is_correct_char(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (0);
		str++;
	}
	return (1);
}

int		is_valid_size(char *str, int nb_rows)
{
	int	i;
	int	count_line;

	i = 0;
	count_line = 0;
	if (nb_rows != 4)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			count_line++;
		if (i % 5 == 4 && str[i] != '\n')
			return (0);
		i++;
	}
	if (count_line != 4)
		return (0);
	return (1);
}
