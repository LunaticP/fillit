/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:47:34 by ngaillar          #+#    #+#             */
/*   Updated: 2016/02/09 16:49:02 by ngaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*grid_exp(unsigned short *tetri[2], int n, int *i, char *grid)
{
	grid = alloc_grid(i, grid);
	n += tetri[0] - tetri[1];
	pl_tetri(NULL, -1, tetri[0][0], *i);
	tetri[0] = tetri[1];
	grid = resolv(tetri, n, i, grid);
	return (grid);
}

static void		resolv_next(int *x, int *n, unsigned short *tetri[2], int *i)
{
	*x = *x + 1;
	*n = *n + 1;
	tetri[0]--;
	pl_tetri(NULL, *x, tetri[0][0], *i);
}

char			*resolv(unsigned short *tetri[2], int n, int *i, char *grid)
{
	int				test;
	int				x;

	grid = resolvini(tetri, i, grid, &x);
	test = pl_tetri(grid, x, tetri[0][0], *i);
	while (x < *i * *i)
	{
		if (test == 1)
			test = pl_tetri(grid, ++x, tetri[0][0], *i);
		if (test == 2 && ((n > 0 && x > *i * *i) || tetri[0] == tetri[1]))
			grid_exp(tetri, n, i, grid);
		else if (test == 2)
			return (rm_tetri(grid, *i));
		if (test == 0)
		{
			test_exit(grid, i, &n, tetri);
			if (n > 0)
				if (NULL == resolv(tetri, n, i, grid))
				{
					resolv_next(&x, &n, tetri, i);
					test = pl_tetri(grid, x, tetri[0][0], *i);
				}
		}
	}
	return (grid);
}
