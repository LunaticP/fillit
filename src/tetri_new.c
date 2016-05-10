/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 06:41:53 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/10 01:24:51 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*tetri_new(t_tetri *last, size_t nb, char *tetri)
{
	t_tetri	*tetri_new;

	ft_putstr("\e[33m(tetri_new)\t\e[32mtetri = \e[35m");
	ft_putstr(tetri);
	ft_putstr("\e[35m [");
	ft_putnbr(nb);
	ft_putendl("]\e[0m");
	tetri_new = (t_tetri *)ft_memalloc(sizeof(t_tetri));
	if (tetri_new == NULL)
		tetri_exit(NULL);
	if (last != NULL)
		last->next = tetri_new;
	tetri_new->last = last;
	tetri_new->n = nb;
	tetri_new->tetri = ft_strnew(16);
	ft_strcpy(tetri_new->tetri, tetri);
	tetri_new->pos = 0;
	return (tetri_new);
}

t_tetri	*tetri_get_first(t_tetri *tetri)
{
	while (tetri->next != NULL)
		tetri = tetri->next;
	return (tetri);
}
