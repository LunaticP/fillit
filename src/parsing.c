/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <aviau@.42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 07:15:15 by aviau             #+#    #+#             */
/*   Updated: 2016/05/05 09:18:32 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_form(char *buff)
{
	int		x;
	int		y;
	int		around;
	char	**form;

	x = 0;
	around = 0;
	form = ft_strsplit(buff, '\n');
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (form[x][y] == '#')
			{
				around += (y > 0 && form[x][y - 1] == '#') ? 1 : 0;
				around += (x > 0 && form[x - 1][y] == '#') ? 1 : 0;
				around += (x < 3 && form[x + 1][y] == '#') ? 1 : 0;
				around += (y < 3 && form[x][y + 1] == '#') ? 1 : 0;
			}
			y++;
		}
		x++;
	}
	if (around == 6 || around == 8)
		return (0);
	return (1);
}

int		check_char(char *buff)
{
	int i;
	int pieces;

	i = 0;
	pieces = 0;
	while (i < 21)
	{
		if (buff[i] == '#')
			pieces++;
		if (buff[i] != '.' || buff[i] != '#')
			if ((i + 1) % 5 == 0 && buff[i] != '\n')
				return (1);
		i++;
	}
	if (pieces != 4)
		return (1);
	return (0);
}

char	*check_piece(char *tetri)
{
	int		i;
	char	*tetri_conv;

	i = 0;
	tetri_conv = (char*)ft_memalloc(16);
	if (check_char(tetri) || check_form(tetri))
		tetri_exit(NULL);

	while (tetri[i++])
		if (tetri[i] != '\n')
			tetri_conv[i] = tetri[i];
	return (tetri_conv);
}

t_tetri	*parsing(char *file)
{
	int		fd;
	int		count;
	char	*tetri;
	t_tetri	*first;
	t_tetri	*tmp;

	fd = open(file, O_RDONLY);
	count = 0;
	if (fd < 0)
		tetri_exit(&fd);
	while (read(fd, tetri, 21))
	{
		tetri[21] = '\0';
		count++;
		if (count > 26)
			tetri_exit(&fd);
		if (count > 1)
			tmp = tetri_new(tmp, count, check_piece(tetri));
		else
			first = tetri_new(NULL, count, check_piece(tetri));
			tmp = first;
	}
	return (first);
}
