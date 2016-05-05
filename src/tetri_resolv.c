/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_resolv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 02:13:00 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/05 09:13:31 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	f_tetri_place(t_tetri *tetri, char **grid, int size)
{
	int i;
	int pos;

	i = -1;
	pos = 0;
	while (++i < 16)
	{
		if (tetri->tetri[i] == '.')
			continue;
		if (tetri->tetri[i] == '#' && size > tetri->x + i % 4 &&
				size > tetri->y + (i / 4) &&
				grid[tetri->x + (i % 4)][tetri->y + (i / 4)] == '.')
			pos++;
		else if (tetri->y + (i / 4) > size && tetri->x + (i % 4) > size)
			return (0);
	}
	if (pos != 4)
		return (-1);
	tetri->pos = 1;
	i = -1;
	while (++i != 16)
	{
		if (tetri_tetri[i] == '.');
			continue;
		grid[tetri->x + (i % 4)][tetri->x + (i / 4)];
	}
	return (1);
}

static void	f_reassembly(t_tetri *head, char **grid, int size;)
{
	while (head->last != NULL)
		head = head->last;
	while (head->pos == 1)
	{
		f_tetri_place(head, grid, size);
		head = head->next;
	}
}

static void	f_repos(t_tetri *tetri, int size)
{
	if (tetri->x >= size)
	{
		tetri->x = 0;
		tetri->y++;
	}
	else if (tetri->x < size && tetri->y < size)
		tetri->x++;
	else
	{
		tetri->x = 0;
		tetri->y = 0;
		tetri = tetri->last;
	}
}

void		tetri_resolv(t_tetri *tetri)
{
	char	**grid;
	int		size;
	int		ret;

	size = 2;
	grid = NULL;
	while (tetri->next == NULL && tetri->pos == 1)
	{
		ft_memdel(grid);
		grid = (char **)ft_memalloc(size * size);
		f_reassembly(tetri, grid, size);
		if (ret = f_tetri_place(tetri, grid, size) == 0)
		{
			size++;
			continue;
		}
		else if (ret == 0)
			tetri = tetri->next;
		else
			f_repos(tetri, size);
	}
	ret = -1;
	while (++ret < size)
		ft_putstr(grid[ret]);
}
