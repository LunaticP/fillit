/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:53:34 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/20 09:53:40 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*rm_tetri(char *grid, int i)
{
	int		n;
	char	c;

	c = 'A';
	i = i * i;
	n = i;
	while (n--)
		if (grid[n] > c)
			c = grid[n];
	while (i--)
		if (grid[i] == c)
			grid[i] = '.';
	return (NULL);
}
