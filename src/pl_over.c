/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_over.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 09:57:38 by vthomas           #+#    #+#             */
/*   Updated: 2016/02/20 09:57:41 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		pl_over(int x, int i, int *over_ligne)
{
	if (x % i == 0 && *over_ligne == 1)
		*over_ligne = *over_ligne + 1;
	if (x % i == i - 1 && *over_ligne == 0)
		*over_ligne = *over_ligne + 1;
}
