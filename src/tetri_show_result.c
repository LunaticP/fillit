/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_show_result.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 06:38:28 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/24 06:38:31 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetri_show_result(const char *tetri, const int size)
{
	int col;
	int line;
	int index;

	col = 0;
	line = 0;
	index = 0;
	while (line < size)
	{
		while (col < size)
		{
			ft_putchar(tetri[index]);
			index++;
			col++;
		}
		col = 0;
		ft_putchar('\n');
		line++;
	}
}
