/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_resolv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 03:32:17 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 04:54:44 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function for try to place an tetrinimos
** Args:
**		-t_tetri:	The tetrinimos to place
**		-char **:	The grid where the tetri must be placed
**		-int:		The size of the grid (size * size)
** Return: int
**		- 0:
**		- 1:
**		- -1:
*/
static int	f_tetri_place(t_tetri *tetri, char **grid, int size)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i / 4)
	}
}

/*
** Function for reassemble the grid
** Args:
**		-t_tetri:	The first tetri
**		-char **:	The grid.
**		-int:		The Size of the grid
** Return: void
*/
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

/*
** Function for resolve the fillit
** Args:
**		-t_tetri:	The tetrinimos list
** Return: void
*/
void		tetri_resolv(t_tetri *tetri)
{
	int		size;
	int		ret;
	char	**grid;

	size = 2;
	grid = NULL;
	while (tetri->next != NULL || tetri->pos != 1)
	{
		if (grid != NULL)
			ft_memdel(&grid);
		grid = ft_memalloc(size);
		feed_grid(grid, size);
		f_reassembly(tetri_get_first(tetri), grid, size);
		ret = f_tetri_place(tetri, grid, size);
		tetri_show(grid, size);
	}
	ft_putendl("<END>");
}
