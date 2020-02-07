/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:16:37 by mlopes-d          #+#    #+#             */
/*   Updated: 2020/01/29 09:16:41 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		change_char(char *tab, char fill_char)
{
	while (*tab)
	{
		if (*tab == '#')
			*tab = fill_char;
		tab++;
	}
}

void		find_min(char **array, char letter, int *min_i, int *min_j)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] == letter)
			{
				if (i < *min_i)
					*min_i = i;
				if (j < *min_j)
					*min_j = j;
			}
			j++;
		}
		i++;
	}
}
