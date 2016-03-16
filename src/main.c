/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 06:36:54 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/24 06:38:51 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argv, char **argc)
{
	unsigned short	*tetri[2];
	int				n;
	int				i;

	i = 0;
	n = 0;
	if (argv != 2)
		usage();
	tetri[0] = tetri_read(argc[1], &n);
	tetri_adjust(tetri[0], n);
	i = n;
	resolv(tetri, n, &i, NULL);
	return (0);
}
