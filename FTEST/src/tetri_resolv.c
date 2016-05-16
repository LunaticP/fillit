/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_resolv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 03:32:17 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/16 14:56:59 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function for try to place an tetrinimos.
** Args:
**		-t_tetri:	The tetrinimos to place.
**		-char **:	The grid where the tetri must be placed.
**		-int:		The size of the grid (size * size).
** Return: int
**		- 0:	Must move.
**		- 1:	Can positionnate the current tetrinimos.
**		- -1:	To large, must grow the grid.
*/
static int	f_tetri_place(t_tetri *tetri, char **grid, int size)
{
	int		i;
	int		x;
	int		y;
	int		pos;
	char	*t;

	i = 0;
	pos = 0;
	x = tetri->x;
	y = tetri->y;
	t = ft_strdup(tetri->tetri);
	while (i < 16)
	{
		if ((x + (i % 4) > size - 1 || y + (i / 4) > size - 1))//si on est trop grand
			if (!is_out(tetri, size, i))
				return (-1);
		if (grid[y + (i / 4)][x + (i % 4)] == '.')
			if (t[i] == '#')
				pos++;
		i++;
	}
	if (pos == 4)//si on a positionner 4 bloc
		return (1);
	return (0);
}

/*
** Function for reassemble the grid.
** Args:
**		-t_tetri:	The first tetri.
**		-char **:	The grid.
**		-int:		The Size of the grid.
** Return: void
*/
static void		f_reassembly(t_tetri *head, char **grid, int size)
{
	while (head->pos == 1)
		head = f_repos(head, grid, size);
}

/*
** Function for positionnate the current tetriminos in the grid.
** Args:
**		-t_tetri:	Current tetriminos.
**		-char**:	The grid.
**		-int:		The size of the grid
** Return: t_tetri
**		-Next tetriminos
*/
t_tetri			*f_repos(t_tetri *tetri, char ** grid, int size)
{
	int		i;
	int		x;
	int		y;
	int		pos;
	char	*t;

	i = 0;
	pos = 0;
	x = tetri->x;
	y = tetri->y;
	tetri->pos = 1;
	t = ft_strdup(tetri->tetri);
	while (i < 16)
	{
		if (y + (i / 4) < size && x + (i % 4) < size)
			if (grid[y + (i / 4)][x + (i % 4)] == '.')
				if (t[i] == '#')
					grid[y + (i / 4)][x + (i % 4)] = 'A' + tetri->n;
		i++;
	}
	return ((tetri->next == NULL) ? tetri : tetri->next);
}

/*
** Function for resolve the fillit.
** Args:
**		-t_tetri:	The tetrinimos list.
** Return: void
*/
void			tetri_resolv(t_tetri *tetri)
{
	int		size;
	int		ret;
	char	**grid;

	size = 2;
	grid = NULL;
	while (tetri->next != NULL || tetri->pos != 1)
	{
		if (grid != NULL)
			ft_memdel((void **)&grid);
		grid = feed_grid(size);
		f_reassembly(tetri_get_first(tetri), grid, size);
		ret = f_tetri_place(tetri, grid, size);
		if (ret == -1)
			size++;
		else if (ret == 1)
			tetri = f_repos(tetri, grid, size);
		else
			tetri_repositionate(tetri, size);
	}
	tetri_show(grid, size);
}
