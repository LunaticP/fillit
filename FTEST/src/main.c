/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 06:36:54 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/16 14:50:43 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetri	*tetri;

	if (ac != 2)
		usage();
	tetri = parsing(av[1]);
	tetri_resolv(tetri_get_first(tetri));
	return (0);
}
