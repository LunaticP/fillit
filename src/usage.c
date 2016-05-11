/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 23:35:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 03:19:16 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage(void)
{
	ft_putstr("usage:\t");
	ft_putendl("./fillit file");
	exit(-1);
}

void	tetri_exit(int *fd)
{
	if (fd != NULL)
		close(*fd);
	ft_putendl("error");
	exit(-1);
}

void tetri_show(char **grid, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_putendl(grid[i]);
}
