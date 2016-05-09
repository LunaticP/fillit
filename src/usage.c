/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 23:35:47 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/09 19:20:27 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage(void)
{
	ft_putstr("usage:\t");
	ft_putendl("./fillit file");
	exit(-1);
}

void	tetri_exit(int *fd)
{
	ft_putendl("\e[33m(tetri_exit)\t\e[31mFile not OK\e[0m");
	if (fd != NULL)
		close(*fd);
	ft_putendl("error");
	exit(-1);
}
