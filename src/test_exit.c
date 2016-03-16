/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:58:07 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/20 09:58:08 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		test_exit(char *grid, int *i, int *n, unsigned short *tetri[2])
{
	*n = *n - 1;
	tetri[0]++;
	if (*n == 0)
	{
		tetri_show_result(grid, *i);
		free(grid);
		free(tetri[1]);
		exit(0);
	}
}
