/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_resolv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 03:32:17 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 03:20:20 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	f_tetri_place(t_tetri *tetri, char **grid, int size)
{
}

static void	f_reassembly(t_tetri *head, char **grid, int size)
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
}

void		tetri_resolv(t_tetri *tetri)
{
	int		size;
	char	**grid;

	size = 2;
	grid = NULL;
	while (tetri->next != NULL || tetri->pos != 1)
	{
		if (grid != NULL)
			ft_memdel(&grid);
		grid = ft_memalloc(size);
		feed_grid(grid, size);
		tetri_show(grid, size);
	}
	ft_putendl("<END>");
}
