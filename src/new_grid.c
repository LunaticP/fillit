/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 02:59:57 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/15 03:30:13 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*doting(int size)
{
	char	*str;
	int		x;

	if ((str = ft_strnew(size)) == NULL)
		tetri_exit(NULL);
	x = 0;
	while (x < size)
	{
		str[x] = '.';
		x++;
	}
	return (str);
}

/*
** Function for create the grid and feed it
** Args:
**		-int:		The size of the grid
** Return:
**		-char **:	The grid
*/
char	**feed_grid(int size)
{
	int y;
	char **grid;

	y = 0;
	if ((grid = (char **)ft_memalloc(size)) == NULL)
		tetri_exit(NULL);
	while (y < size)
	{
		grid[y] = doting(size);
		ft_debug_var_int("feed_grid", "y", y);
		ft_debug_var_int("feed_grid", "&grid[y]", &grid[y]);
		ft_debug_var_int("feed_grid", "&grid[0]", &grid[0]);
		ft_debug_var_char("feed_grid", "grid[y]", grid[y]);
		ft_debug_var_char("feed_grid", "grid[0]", grid[0]);
		y++;
	}
	tetri_show(grid, size);
	tetri_exit(NULL);
	return (grid);
}
