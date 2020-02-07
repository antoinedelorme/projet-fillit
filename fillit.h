/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:24:39 by mlopes-d          #+#    #+#             */
/*   Updated: 2020/01/29 09:24:42 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 1

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_tetri
{
	char			*tab;
	char			**array;
	char			fill_char;
	int				*tabx;
	int				*taby;
	struct s_tetri	*next;
}					t_tetri;

int					correct_file(char *file);
int					get_nb_diese(char *str);
int					is_correct_char(char *str);
int					is_valid_size(char *str, int nb_rows);
int					count_touch(char *str);
int					fill_lst(char *tmp, int i, t_tetri **lst_tetri);
int					solve(t_tetri *lst_tetri, int nb_tetri);
void				change_char(char *tab, char fill_char);
void				find_min(char **array, char letter, int *min_i, int *min_j);
char				**create_board(int min_size);
int					free_place(char **board, t_tetri *lst_tetri, int *tab,
								int min_size);
void				put_tetri(char **board, t_tetri *lst_tetri, int a, int b);
#endif
