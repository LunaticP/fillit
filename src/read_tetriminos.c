/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:14:21 by ngaillar          #+#    #+#             */
/*   Updated: 2016/01/03 10:06:42 by ngaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	read_tetri(char *buf)
{
	unsigned short	tetri;
	int				i;

	i = 0;
	tetri = 0;
	while (*buf != '\0')
	{
		if (*buf++ == '#')
			tetri += 1;
		if (*buf == '\n')
			continue;
		tetri <<= (*buf != '\0') ? 1 : 0;
	}
	return (tetri);
}

unsigned short			*read_tetriminos(char *path, int *n)
{
	int				fd;
	int				ret;
	unsigned short	*tetriminos;
	unsigned short	*ptr;
	char			*buf;

	buf = (char*)malloc(sizeof(char) * 22);
	fd = open(path, O_RDONLY);
	tetriminos = (unsigned short*)malloc(sizeof(unsigned short) * 26);
	ptr = tetriminos;
	while ((ret = read(fd, buf, 21)))
	{
		*n = *n + 1;
		buf[ret] = '\0';
		*tetriminos = read_tetri(buf);
		tetriminos++;
	}
	return (ptr);
}
