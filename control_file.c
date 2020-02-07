/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:13:26 by mlopes-d          #+#    #+#             */
/*   Updated: 2020/02/07 09:54:19 by mlopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int is_file(char *file)
{
	int fd;
	char buf[BUF_SIZE];

	fd = open(file, O_RDONLY);
	if (read(fd, buf, BUF_SIZE) == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static int get_nb_tetri(char *file)
{
	int nb_tetri;
	int fd;
	int ret;
	char buf[BUF_SIZE];
	int rows;

	rows = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (buf[0] == '\n')
			rows++;
	}
	close(fd);
	nb_tetri = (rows / 5) + 1;
	return (nb_tetri);
}

static int get_nb_rows(char *str)
{
	int nb_rows;

	nb_rows = 0;
	while (*str)
	{
		if (*str == '\n')
			nb_rows++;
		str++;
	}
	return (nb_rows);
}

static int get_infos(char *file, char *str)
{
	int nb_tetri;
	int nb_rows;
	int i;
	char *tmp;
	t_tetri *lst_tetri;
	t_tetri *tmp2;

	lst_tetri = NULL;
	tmp = NULL;
	nb_tetri = get_nb_tetri(file);
	i = 0;
	while (i < nb_tetri)
	{
		i == (0) ? (tmp = ft_strsub(str, 0, 20)) : (tmp = ft_strsub(str, i * 20 + i, 20));
		tmp[20] = '\0';
		nb_rows = get_nb_rows(tmp);
		if (!get_nb_diese(tmp) || !is_correct_char(tmp) ||
			!is_valid_size(tmp, nb_rows) || count_touch(tmp) < 6)
		{
			free(tmp);
			return (0);
		}
		if (!fill_lst(tmp, i, &lst_tetri))
		{
			free(lst_tetri);
			//printf("3-dealocate: %p \n", lst_tetri);
			free(tmp);
			return (0);
		}
		if (tmp)
			free(tmp);
		i++;
	}
	//printf("4-dealocate: %p \n", lst_tetri);
	if (!solve(lst_tetri, nb_tetri))
	{
		free(lst_tetri);
		printf("1-dealocate: %p \n", lst_tetri);
		return (0);
	}
	while (!(lst_tetri == NULL))
	{
		tmp2 = lst_tetri->next;
		i = 0;
		while (i < 4)
		{
			free(lst_tetri->array[i++]);
			printf("dealocate array[i]: \t\t%p\n",lst_tetri->array[i-1]); 
		}
		printf("@dealocate lst_tetri: \t\t\t\t\t%p \n", lst_tetri);	
		free(lst_tetri->array);	
		free(lst_tetri->taby);
		free(lst_tetri->tabx);			
		free(lst_tetri);
		lst_tetri = tmp2;
		
	}
	return (1);
}

int correct_file(char *file)
{
	int fd;
	int ret;
	char buf[BUF_SIZE];
	int size;
	char *str;

	if (!is_file(file))
		return (0);
	size = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, BUF_SIZE)))
		size++;
	close(fd);
	if (!(str = (char *)malloc(sizeof(*str) * size + 1)))
		return (0);
	fd = open(file, O_RDONLY);
	ret = read(fd, str, size);
	str[ret] = '\0';
	close(fd);
	if (!get_infos(file, str))
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
