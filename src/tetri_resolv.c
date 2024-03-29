/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_resolv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 03:32:17 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/11 02:32:00 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	f_tetri_place(t_tetri *tetri, char **grid, int size)
{
	int i;
	int pos;

	i = -1;
	pos = 0;
	ft_putendl("\e[33m(f_tetri_place)\t\e[32mplacing tetri\e[0m");
	ft_putnbr_desc("\e[33m(f_tetri_place)\t\e[32mx = \e[35m", tetri->x);
	ft_putnbr_desc("\e[33m(f_tetri_place)\t\e[32my = \e[35m", tetri->y);
	ft_putstr("\e[0m");
	while (++i < 16)
	{
		if (i > 15)
		{
			ft_putendl("");
			ft_putnbr_desc("\e[33m(f_tetri_place)\t\e[32mx = \e[35m", tetri->x + (i % 4));
			ft_putnbr_desc("\e[33m(f_tetri_place)\t\e[32my = \e[35m", tetri->y + (i /4));
			ft_putendl("");
			return (0);
		}
		else if (tetri->tetri[i] == '.')
			continue;
		else if (tetri->tetri[i] == '#' && size > tetri->x + i % 4 &&
				size > tetri->y + (i / 4) &&
				grid[tetri->x + (i % 4)][tetri->y + (i / 4)] == '.')
			pos++;
	}
	tetri->pos = 1;
	i = -1;
	while (++i < size)
		ft_putendl(grid[0]);
	i = -1;
	while (++i != 16)
		if (tetri->tetri[i] != '.')
			grid[tetri->x + (i % 4)][tetri->x + (i / 4)] = 'B' + tetri->n;
	return (1);
}

static void	f_reassembly(t_tetri *head, char **grid, int size)
{
	while (head->last != NULL)
		head = head->last;
	while (head->pos == 1)
	{
		f_tetri_place(head, grid, size);
		head = head->next;
	}
}

static void	f_repos(t_tetri *tetri, int size)
{
	if (tetri->x >= size)
	{
		tetri->x = 0;
		tetri->y++;
	}
	else if (tetri->x < size && tetri->y < size)
		tetri->x++;
	else
	{
		tetri->x = 0;
		tetri->y = 0;
		tetri = tetri->last;
	}
}

void		tetri_resolv(t_tetri *tetri)
{
	char	**grid;
	int		size;
	int		ret;

	size = 2;
	grid = NULL;
	ft_putendl("\e[33m(tetri_resolv)\t\e[36malgo start");
	ft_putstr("\e[33m(tetri_resolv)\t\e[32mtetri = \e[35m");
	ft_putendl(tetri->tetri);
	ft_putstr("\e[33m(tetri_resolv)\t\e[32mtetri->pos = \e[35m");
	ft_putnbr_endl((int)tetri->pos);
	if (!tetri->next)
		ft_putendl("\e[33m(tetri_resolv)\t\e[32mtetri->next = \e[31mNULL\e[0m");
	while (tetri->next != NULL || tetri->pos != 1)
	{
		ft_putendl("\e[33m(tetri_resolv)\t\e[36mentered [while]");
		ft_putstr("\e[33m(tetri_resolv)\t\e[32mtetri = \e[35m");
		ft_putendl(tetri->tetri);
		ft_putnbr_desc("\e[33m(tetri_resolv)\t\e[32msize = \e[35m", size);
		ft_putnbr_desc("\e[33m(tetri_resolv)\t\e[32mx = \e[35m", tetri->x);
		ft_putnbr_desc("\e[33m(tetri_resolv)\t\e[32my = \e[35m", tetri->y);
		ft_putstr("\e[0m");
		if (grid)
		{
			ft_memdel((void **)&grid);
			ft_putendl("\e[33m(tetri_resolv)\t\e[32mgrid memdel");
		}
		grid = (char **)ft_memalloc(size);
		feed_grid(grid, size);
		ft_putendl("\e[33m(tetri_resolv)\t\e[32mgrid memalloc");
		f_reassembly(tetri, grid, size);
		ft_putendl("\e[33m(tetri_resolv)\t\e[32mf_reassembly\e[0m");
		if ((ret = f_tetri_place(tetri, grid, size)) == 0)
		{
			ft_putendl("\e[33m(tetri_resolv)\t\e[36mentered [if]");
			ft_putendl("\e[33m(tetri_resolv)\t\e[32mf_tetri_place returned 0\e[0m");
			size++;
			continue;
		}
		else if (ret > 0)
		{
			ft_putendl("\e[33m(tetri_resolv)\t\e[32mf_tetri_place returned 1\e[0m");
			tetri = tetri->next;
		}
		else
		{
			ft_putendl("\e[33m(tetri_resolv)\t\e[32mf_tetri_place returned -1\e[0m");
			f_repos(tetri, size);
		}
		ft_putendl("\e[33m(tetri_resolv)\t\e[36mexited [if]");
	}
	ft_putendl("\e[33m(tetri_resolv)\t\e[36mexited [while]\e[0m");
	ret = -1;
	while (++ret < size)
		ft_putstr(grid[ret]);
}
