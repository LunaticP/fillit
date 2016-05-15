/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 02:59:57 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/15 04:54:37 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function for create the line (grid[y])
** Args:
**		-int:		The size of the grid.
** Return:
**		-char **:	The line.
*/
static char	*doting(int const size)
{
	char	*str;
	int		x;

	if ((str = (char *)malloc(size + 1)) == NULL)
		tetri_exit(NULL);
	x = size - 1;
	while (x >= 0)
	{
		str[x] = '.';
		x--;
	}
	str[size] = '\0';
	return (str);
}

/*
** Function for create the grid and feed it
** Args:
**		-int:		The size of the grid.
** Return:
**		-char **:	The grid.
*/
char	**feed_grid(int const size)
{
	int y;
	char **grid;

	if ((grid = (char **)ft_memalloc(sizeof(char **) * (size + 1))) == NULL)
		tetri_exit(NULL);
	y = 0;
	while (y < size)//pour aller de 0 a size
	{
		grid[y] = doting(size);
		y++;//descend de 1
	}
	return (grid);
}
