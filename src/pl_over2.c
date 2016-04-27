/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_over2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:57:06 by vthomas           #+#    #+#             */
/*   Updated: 2016/04/27 06:26:06 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		pl_over2(char *grid, char *ptr, int nbr, int over_ligne)
{
	if (*grid == '.' && over_ligne < 2)
		*grid = 'A' + nbr;
	else
	{
		*ptr = *ptr;
		return (1);
	}
	return (0);
}
