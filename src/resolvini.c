/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:57:58 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/20 09:57:59 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*resolvini(unsigned short *tetri[2], int *i, char *grid, int *x)
{
	int	n;

	if (grid == NULL)
	{
		n = *i;
		*i = 0;
		tetri[1] = tetri[0];
		n = n * 4;
		while (n > *i * *i)
			*i = *i + 1;
		grid = alloc_grid(i, NULL);
	}
	*x = 0;
	return (grid);
}
