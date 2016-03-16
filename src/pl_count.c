/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:54:12 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/20 09:54:15 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		pl_count(int *count, int i, int *over_ligne, int *x)
{
	*x = *x + 1;
	if (*count % 4 == 0 && *count != 0)
	{
		*x = *x + i - 4;
		if (*over_ligne > 0)
			*over_ligne = *over_ligne - 1;
		*count = *count + 1;
		return (i - 4);
	}
	*count = *count + 1;
	return (0);
}
