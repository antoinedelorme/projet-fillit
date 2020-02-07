/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:16:56 by mlopes-d          #+#    #+#             */
/*   Updated: 2020/01/29 10:25:23 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	del_tetri(char **board, t_tetri *lst_tetri, int a, int b)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 4)
	{
		x = lst_tetri->tabx[i];
		y = lst_tetri->taby[i];
		board[x + a][y + b] = '.';
		i++;
	}
}

static int	fill_board(char **board, int min_size, t_tetri *lst_tetri)
{
	int		tab[2];

	if (lst_tetri)
	{
		tab[0] = -1;
		while (++tab[0] < min_size)
		{
			tab[1] = -1;
			while (++tab[1] < min_size)
			{
				if (free_place(board, lst_tetri, tab, min_size))
				{
					put_tetri(board, lst_tetri, tab[0], tab[1]);
					if (fill_board(board, min_size, lst_tetri->next))
						return (1);
					del_tetri(board, lst_tetri, tab[0], tab[1]);
				}
			}
		}
		if (tab[0] == min_size && tab[1] == min_size)
			return (0);
	}
	return (1);
}

void		free_board(char **board, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

static void	print_board(char **board, int min_size)
{
	int		i;

	i = 0;
	while (i < min_size)
	{
		ft_putstr(board[i]);
		i++;
	}
}

int			solve(t_tetri *lst_tetri, int nb_tetri)
{
	int		min_size;
	char	**board;
	int		finish;
	int		i;

	min_size = 1;
	while (min_size * min_size < (nb_tetri * 4))
		min_size++;
	finish = 0;
	while (!finish)
	{
		board = create_board(min_size);
		if (!board)
			return (0);
		if (!fill_board(board, min_size, lst_tetri))
		{
			free_board(board, min_size);
			min_size++;
		}
		else
		{
			print_board(board, min_size);
			i = 0;
			while (i < min_size){
				free(board[i++]);
			}
			free(board);
			finish = 1;
		}
	}
	return (1);
}
