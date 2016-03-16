/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_adjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:08:15 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/09 23:33:15 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		stc_check_hor(unsigned short us_tetri)
{
	if (us_tetri & 0x8000 || us_tetri & 0x0800
			|| us_tetri & 0x0080 || us_tetri & 0x00008)
		return (0);
	if (us_tetri & 0x4000 || us_tetri & 0x0400
			|| us_tetri & 0x0040 || us_tetri & 0x00004)
		return (1);
	if (us_tetri & 0x2000 || us_tetri & 0x0200
			|| us_tetri & 0x0020 || us_tetri & 0x00002)
		return (2);
	if (us_tetri & 0x1000 || us_tetri & 0x0100
			|| us_tetri & 0x0010 || us_tetri & 0x00001)
		return (3);
	return (-1);
}

static int		stc_check_ver(unsigned short us_tetri)
{
	if (us_tetri & 0x8000 || us_tetri & 0x4000
			|| us_tetri & 0x2000 || us_tetri & 0x1000)
		return (0);
	if (us_tetri & 0x0800 || us_tetri & 0x0400
			|| us_tetri & 0x0200 || us_tetri & 0x0100)
		return (1);
	if (us_tetri & 0x0080 || us_tetri & 0x0040
			|| us_tetri & 0x0020 || us_tetri & 0x0010)
		return (2);
	if (us_tetri & 0x0008 || us_tetri & 0x0004
			|| us_tetri & 0x0002 || us_tetri & 0x0001)
		return (3);
	return (-1);
}

unsigned short	*tetri_adjust(unsigned short *us_tetri, int i_nb)
{
	int index;

	index = 0;
	while (index < i_nb)
	{
		us_tetri[index] = us_tetri[index] << stc_check_hor(us_tetri[index]);
		index++;
	}
	index = 0;
	while (index < i_nb)
	{
		us_tetri[index] = us_tetri[index] << 4 * stc_check_ver(us_tetri[index]);
		index++;
	}
	return (us_tetri);
}
