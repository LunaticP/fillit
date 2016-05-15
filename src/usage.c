/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 23:35:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/15 03:30:46 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function for show the "usage"
** Args:
**		-void
** Return: void
*/
void	usage(void)
{
	ft_putstr("usage:\t");
	ft_putendl("./fillit file");
	exit(-1);
}

/*
** Function for exit on error
** Args:
**		-int *:	File descriptor for close file if open (If no file send NULL)
** Return: void
*/
void	tetri_exit(int *fd)
{
	if (fd != NULL)
		close(*fd);
	ft_putendl("error");
	exit(-1);
}

/*
** Function for show the final grid
** Args:
**		-char **:	The grid
**		-int:		The size
** Return: void
*/
void tetri_show(char **grid, int size)
{
	int x;
	int y;

	ft_debug_bloc("tetri_show","start");
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			write(1, grid[y][x], size);
			x++;
		}
		write(1, grid[y], size);
		write(1, "\n", 1);
		y++;
	}
	ft_debug_bloc("tetri_show", "end");
}
