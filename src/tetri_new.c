/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 06:41:53 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/05 06:52:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*tetri_new(t_tetri *last, t_tetri *next, size_t nb, char *tetri)
{
	t_tetri	*tetri_new;

	tetri_new = ft_memalloc(sizeof(t_tetri));
	if (tetri_new == NULL)
		return (NULL);
	tetri_new->last = last;
	tetri_new->next = next;
	tetri_new->n = nb;
	ft_strcopy(tetri_new->tetri, tetri);
	return (tetri_new);
}
