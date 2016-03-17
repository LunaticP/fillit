/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 11:54:22 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/17 20:42:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	tetri_readtetri(char *buf)
{
	unsigned short	tetri;

	tetri = 0;
	tetri_sp_check(buf);
	while (*buf != '\0')
	{
		if (*buf++ == '#')
			tetri++;
		if (*buf == '\n')
			continue;
		tetri <<= (*buf != '\0') ? 1 : 0;
	}
	tetri_validate(tetri);
	return (tetri);
}

static int				tetri_openfile(char *path, int flags, int *fd)
{
	if (*fd != 0)
		close(*fd);
	*fd = open(path, flags);
	if (*fd < 0)
		tetri_exit(NULL);
	return (*fd);
}

static int				tetri_count(int fd)
{
	int		ret;
	int		nb;
	char	*buf;

	nb = 0;
	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	while ((ret = read(fd, buf, 21)))
		nb++;
	ft_strdel(&buf);
	if (nb < 1)
		tetri_exit(NULL);
	return (nb);
}

static int				verif_tetri(char *str, int tot)
{
	int index;

	index = 0;
	if (tot < 20)
		return (0);
	while (index <= tot)
	{
		if (index != 4 && index != 9 && index != 14 && index < 19)
		{
			if (str[index] != '.' && str[index] != '#')
				return (1);
		}
		if (index == 4 || index == 9 || index == 14 || index == 19)
		{
			if (str[index] != '\n')
				return (2);
		}
		index++;
	}
	return (-1);
}

unsigned short			*tetri_read(char *path, int *n)
{
	int				fd;
	unsigned short	*tetri;
	int				ret;
	char			*buf;
	int				cnt;

	*n = 0;
	fd = 0;
	buf = (char *)malloc(sizeof(char) * BUF_SIZE + 1);
	fd = tetri_openfile(path, O_RDONLY, &fd);
	cnt = tetri_count(fd);
	tetri = ft_memalloc(sizeof(unsigned short) * cnt);
	fd = tetri_openfile(path, O_RDONLY, &fd);
	while ((ret = read(fd, buf, 21)))
	{
		if (ret == 21 && *n == cnt - 1)
			tetri_exit(&fd);
		buf[21] = '\0';
		if (verif_tetri(buf, ret) != -1)
			tetri_exit(&fd);
		tetri[*n] = tetri_readtetri(buf);
		*n += 1;
	}
	ft_strdel(&buf);
	return (tetri);
}
