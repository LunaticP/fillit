/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positionate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 00:36:08 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/16 04:03:56 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void tetri_repositionate(t_tetri *tetri, int size)
{
	if (tetri->x == size)
	{
		tetri->x = 0;
		tetri->y++;
	}
	else
		tetri->x++;
}

int	is_out(t_tetri *tetri, int size, int i)
{
	int x_tmp;
	int y;

	x_tmp = 0;
	y = tetri->y + (i / 4);
	if (y < size)
	{
		while (x_tmp < 4)
		{
			if (tetri->tetri[4 * (i / 4) + x_tmp] == '.')
			{
				tetri->y = 0;
				tetri->x = 0;
				return (1);
			}
			x_tmp++;
		}
	}
	return (0);
}
