/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:58:21 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/20 09:58:48 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		pl_tetri(char *grid, int x, unsigned short tetriminos, int i)
{
	char		*ptr;
	char		*grid_temp;
	static int	nbr;
	int			count;
	int			over_ligne;

	if (pl_intest(grid, x, &nbr))
		return (3);
	grid_temp = pl_int(&count, &over_ligne, grid, i);
	ptr = grid_temp;
	grid_temp = pl_int2(grid_temp, &x, i, &nbr);
	while (tetriminos)
	{
		grid_temp += pl_count(&count, i, &over_ligne, &x);
		if (pl_seg(grid_temp, ptr))
			return (2);
		if (tetriminos & 0x8000)
			pl_over(x, i, &over_ligne);
		if (tetriminos & 0x8000)
			if (pl_over2(grid_temp, ptr, nbr, over_ligne))
				return (1);
		grid_temp++;
		tetriminos <<= 1;
	}
	return (pl_end(grid, ptr, i, &nbr));
}
