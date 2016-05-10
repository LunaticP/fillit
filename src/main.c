/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 06:36:54 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/10 04:18:53 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetri	*tetri;

	if (ac != 2)
		usage();
	ft_putendl("\n\e[34m[ PARSING ]\e[0m\n");
	tetri = parsing(av[1]);
	ft_putendl("\n \e[34m[ ALGO ]\e[0m\n");
	tetri_resolv(tetri_get_first(tetri));
	return (0);
}
