/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:57:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/20 09:57:51 by vthomas          ###   ########.fr       */
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
	grid = (char*)malloc(sizeof(char) * (nbr));
	while (nbr--)
		grid[nbr] = '.';
	return (grid);
}
