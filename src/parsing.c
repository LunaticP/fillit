/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <aviau@.42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 07:15:15 by aviau             #+#    #+#             */
/*   Updated: 2016/05/10 01:19:46 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_form(char *buff)
{
	int		x;
	int		y;
	int		around;
	char	**form;

	x = -1;
	around = 0;
	form = ft_strsplit(buff, '\n');
	while (x++ < 3)
	{
		y = -1;
		while (y++ < 3)
		{
			if (form[x][y] == '#')
			{
				around += (y > 0 && form[x][y - 1] == '#') ? 1 : 0;
				around += (x > 0 && form[x - 1][y] == '#') ? 1 : 0;
				around += (x < 3 && form[x + 1][y] == '#') ? 1 : 0;
				around += (y < 3 && form[x][y + 1] == '#') ? 1 : 0;
			}
		}
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
	tetri_conv = ft_strnew(16);
	if (check_char(tetri))
		tetri_exit(NULL);
	if (check_form(tetri))
		tetri_exit(NULL);
	tetri_conv = str_conv(tetri);
	return (tetri_conv);
}

void	first_read(char *file)
{
	int		fd;
	int		ret;
	int		last;
	int		tetri_nb;
	char	*tmp;

	fd = open(file, O_RDONLY);
	tetri_nb = 0;
	last = 0;
	tmp = ft_strnew(21);
	while ((ret = read(fd, tmp, 21)))
	{
		if (tetri_nb++ > 25)
			tetri_exit(&fd);
		last = ret;
	}
	if (ret == 0 && last != 20)
		tetri_exit(&fd);
	ft_memdel((void **)&tmp);
	close(fd);
}

t_tetri	*parsing(char *file)
{
	int		fd;
	int		count;
	char	*tetri;
	t_tetri	*first;
	t_tetri	*tmp;

	ft_putendl("\e[33m(parsing)\t\e[36mParsing start\e[0m");
	first_read(file);
	fd = open(file, O_RDONLY);
	count = 0;
	tetri = ft_strnew(21);
	if (fd < 1)
		tetri_exit(&fd);
	while (read(fd, tetri, 21))
	{
		if (count++ > 1)
			tmp = tetri_new(tmp, count, check_piece(tetri));
		else
		{
			first = tetri_new(NULL, count, check_piece(tetri));
			tmp = first;
		}
		ft_strclr(tetri);
	}
	close(fd);
	ft_putendl("\e[33m(parsing)\t\e[36mfile is OK\e[0m");
	return (first);
}
