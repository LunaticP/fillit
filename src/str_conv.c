/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:32:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 03:28:54 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*remerge(char **t)
{
	char	*output;

	output = ft_strnew(16);
	ft_strcpy(&output[0], t[0]);
	ft_strcpy(&output[4], t[1]);
	ft_strcpy(&output[8], t[2]);
	ft_strcpy(&output[12], t[3]);
	return (output);
}

char	**replace(char *input)
{
	int		x;
	char	**t;

	t = ft_strsplit(input, '\n');
	while (t[0][0] == '.' && t[1][0] == '.' && t[2][0] == '.' && t[3][0] == '.')
	{
		x = -1;
		while (x++ < 3)
		{
			t[0][x] = (t[0][x + 1]) ? t[0][x + 1] : '.';
			t[1][x] = (t[1][x + 1]) ? t[1][x + 1] : '.';
			t[2][x] = (t[2][x + 1]) ? t[2][x + 1] : '.';
			t[3][x] = (t[3][x + 1]) ? t[3][x + 1] : '.';
		}
	}
	while (!ft_strcmp(t[0], "....") && (x = -1))
		while (x++ < 3)
		{
			t[x] = (t[x + 1]) ? t[x + 1] : "....";
			t[x] = (t[x + 1]) ? t[x + 1] : "....";
			t[x] = (t[x + 1]) ? t[x + 1] : "....";
			t[x] = (t[x + 1]) ? t[x + 1] : "....";
		}
	return (t);
}

char	*str_conv(char *input)
{
	char	*output;

	output = ft_strnew(16);
	if (output == NULL)
		tetri_exit(NULL);
	output = remerge(replace(input));
	ft_putendl(output);
	return (output);
}

void feed_grid(char **grid, int size)
{
	int x;
	int y;

	ft_putendl("\e[32mFeed the grid\e[0m");
	y = 0;
	while (y < size)
	{
		grid[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			grid[y][x] = '.';
			x++;
		}
		y++;
	}
}
