/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 06:41:53 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/16 14:51:57 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*tetri_new(t_tetri *last, size_t nb, char *tetri)
{
	t_tetri	*tetri_new;

	tetri_new = (t_tetri *)ft_memalloc(sizeof(t_tetri));
	if (tetri_new == NULL)
		tetri_exit(NULL);
	if (last != NULL)
		last->next = tetri_new;
	tetri_new->last = last;
	tetri_new->n = nb - 1;
	tetri_new->tetri = ft_strnew(16);
	ft_strcpy(tetri_new->tetri, tetri);
	tetri_new->pos = 0;
	return (tetri_new);
}

t_tetri	*tetri_get_first(t_tetri *tetri)
{
	while (tetri->last != NULL)
		tetri = tetri->last;
	return (tetri);
}
