/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:19:03 by mlopes-d          #+#    #+#             */
/*   Updated: 2020/01/29 09:19:09 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_zero(char *str, int i)
{
	int		count;

	count = 0;
	if (str[i + 1] == '#')
		count++;
	if (str[i + 5] == '#')
		count++;
	return (count);
}

static int	check_first_row(char *str, int i)
{
	int		count;

	count = 0;
	if (str[i - 1] == '#')
		count++;
	if (str[i + 1] == '#')
		count++;
	if (str[i + 5] == '#')
		count++;
	return (count);
}

static int	check_mid_tab(char *str, int i)
{
	int		count;

	count = 0;
	if (str[i - 1] == '#')
		count++;
	if (str[i + 1] == '#')
		count++;
	if (str[i - 5] == '#')
		count++;
	if (str[i + 5] == '#')
		count++;
	return (count);
}

static int	check_last_row(char *str, int i)
{
	int		count;

	count = 0;
	if (str[i - 1] == '#')
		count++;
	if (str[i + 1] == '#')
		count++;
	if (str[i - 5] == '#')
		count++;
	return (count);
}

int			count_touch(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i <= 19)
	{
		if (str[i] == '#')
		{
			if (i == 0)
				count += check_zero(str, i);
			if (i < 4)
				count += check_first_row(str, i);
			if (i > 4 && i < 14)
				count += check_mid_tab(str, i);
			if (i > 14 && i < 19)
				count += check_last_row(str, i);
		}
		i++;
	}
	return (count);
}
