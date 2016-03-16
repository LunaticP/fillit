/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:55:35 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/20 09:55:37 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*pl_int(int *count, int *over_ligne, char *grid, int i)
{
	char *grid_temp;

	*count = 0;
	*over_ligne = 0;
	grid_temp = (char*)malloc(sizeof(char) * (i * i));
	ft_strncpy(grid_temp, grid, i * i);
	return (grid_temp);
}
