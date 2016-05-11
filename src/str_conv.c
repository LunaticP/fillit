/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:32:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 09:53:15 by vthomas          ###   ########.fr       */
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

/*
** Function for create the grid and feed it
** Args:
**		-int:	The size of the grid
** Return:
**		-char **: The grid
*/
char **feed_grid(int size)
{
	int		x;
	int		y;
	char	**grid;

	ft_debug_info("feed_grid", "Feed the grid...");
	grid = (char **)ft_memalloc(size);
	y = 0;
	while (y < size)
	{
		grid[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			ft_putnbr_endl(x);
			grid[y][x] = '.';
			x++;
		}
		ft_debug_var_int("feed_grid", "y", y);
		ft_debug_var_char("feed_grid","grid",grid[0]);
		y++;
	}
	ft_debug_var_char("feed_grid","grid[0]",grid[0]);
	ft_debug_var_char("feed_grid","grid[1]",grid[1]);
	ft_debug_var_char("feed_grid","grid[2]",grid[2]);
	ft_debug_var_char("feed_grid","grid[3]",grid[3]);
	ft_debug_var_int("feed_grid","size",size);
	tetri_show(grid, size);
	return (grid);
}
