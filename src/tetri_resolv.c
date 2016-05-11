/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_resolv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 03:32:17 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 09:37:21 by vthomas          ###   ########.fr       */
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
**		- 1:	Can positionnate the current tetrinimos
**		- -1:	To large, must grow the grid
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
	ft_debug_info("f_tetri_place","ft_strdup\t[OK]");
	ft_debug_var_char("f_tetri_place", "tetri", t);
	ft_debug_bloc("f_tetri_place", "while");
	ft_debug_var_int("f_tetri_place", "size", size);
	while (i < 16)
	{
		if ((x + (i % 4) > size - 1 || y + (i / 4) > size - 1))//si on est trop grand
			return (-1);
		if (grid[x + (i % 4)][y + (i / 4)] == '.')
			if (t[i] == '#')
				pos++;
		i++;
	}
	if (pos == 4)//si on a positionner 4 bloc
		return (1);
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

	size = 4;
	grid = NULL;
	while (tetri->next != NULL || tetri->pos != 1)
	{
		if (grid != NULL)
			ft_memdel(&grid);
		grid = feed_grid(size);
		ft_debug_info("tetri_resolv", "feed_grid\t[OK]");
		tetri_show(grid, size);
		f_reassembly(tetri_get_first(tetri), grid, size);
		ft_debug_info("tetri_resolv", "f_reassembly\t[OK]");
		ret = f_tetri_place(tetri, grid, size);
		ft_debug_info("tetri_resolv","f_tetri_place:\t[OK]");
		ft_debug_var_int("tetri_resolv","ret", ret);
		//if (ret == -1)
		//	size++;
		usleep(500000);
		tetri_show(grid, size);
		ft_putendl("");
	}
	ft_putendl("<END>");
}
