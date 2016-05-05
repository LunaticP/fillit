/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 06:41:53 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/05 11:28:34 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*tetri_new(t_tetri *last, size_t nb, char *tetri)
{
	t_tetri	*tetri_new;

	tetri_new = ft_memalloc(sizeof(t_tetri));
	if (tetri_new == NULL)
		tetri_exit(NULL);
	if (last != NULL)
		last->next = tetri_new;
	tetri_new->last = last;
	tetri_new->next = NULL;
	tetri_new->n = nb;
	ft_strcpy(tetri_new->tetri, tetri);
	tetri_new->pos = 0;
	return (tetri_new);
}
