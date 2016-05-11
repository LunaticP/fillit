/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 23:35:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 04:59:57 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function for show the usage
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
	int i;

	i = -1;
	while (++i < size)
		ft_putendl(grid[i]);
}
