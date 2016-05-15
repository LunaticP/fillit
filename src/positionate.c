/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positionate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 00:36:08 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/16 00:50:10 by vthomas          ###   ########.fr       */
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
