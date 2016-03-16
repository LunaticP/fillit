/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_resolv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 02:13:00 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/24 03:46:44 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetri_resolv(t_tetri *tetri, size_t nb)
{
	size_t	taille;
	size_t	x;
	size_t	y;
	char	*final_str;

	taille = 2;
	x = 0;
	y = 0;
	final_str = ft_strnew(taille * taille);
}
