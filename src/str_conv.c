/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:32:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/10 06:24:38 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*replace(char *input)
{
	int		x;
	char	**t;

	t = ft_strsplit(input, '\n');
	ft_putendl(t[0]);
	ft_putendl(t[1]);
	ft_putendl(t[2]);
	ft_putendl(t[3]);
	ft_putchar('\n');
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
	ft_putendl(t[0]);
	ft_putendl(t[1]);
	ft_putendl(t[2]);
	ft_putendl(t[3]);
	return (input);
}

char	*str_conv(char *input)
{
	char	*output;

	output = ft_strnew(16);
	input = replace(input);
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
	int x;
	int y;

	if (size > 100)
	{
		ft_putendl("\e[31mError occured: Size is more big than 100\e[0m");
		tetri_exit(NULL);
	}
	x = 0;
	y = 0;
	while (y < size)
	{
		grid[y] = ft_strnew(size);
		while (x < size)
		{
			grid[y][x] = '.';
			x++;
		}
		y++;
	}
}
