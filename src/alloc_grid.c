/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:57:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/04/14 10:23:22 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*alloc_grid(int *i, char *grid)
{
	int		nbr;

	if (grid)
	{
		free(grid);
		*i = *i + 1;
	}
	nbr = *i * *i;
	if (!(grid = (char*)malloc(sizeof(char) * (nbr))))
		tetri_exit(NULL);
	while (nbr--)
		grid[nbr] = '.';
	return (grid);
}
