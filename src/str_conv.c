/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:32:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/10 04:59:45 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*str_conv(char *input)
{
	char	*output;

	output = ft_strnew(16);
	if (output == NULL)
		tetri_exit(NULL);
	ft_strncpy(&output[0], &input[0], 4);
	ft_strncpy(&output[4], &input[5], 4);
	ft_strncpy(&output[8], &input[10], 4);
	ft_strncpy(&output[12], &input[15], 4);
	return (output);
}

void feed_grid(char **grid, int size)
{
	ft_putendl("\e[33m(tetri_resolv)\t\e[36mentered [feed]\e[0m");
	int x = 0;
	int y = 0;
	while (y < size)
	{
		while (x < size)
		{
			grid[y][x] = '.';
			x++;
		}
		y++;
	}
}
