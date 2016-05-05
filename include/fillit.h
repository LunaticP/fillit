/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 06:14:40 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/05 08:12:49 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 21

typedef struct	s_tetri
{
	struct s_tetri	*next;
	struct s_tetri	*last;
	size_t			x;
	size_t			y;
	size_t			n;
	char			*tetri;
}				t_tetri;

void			tetri_exit(int *fd);
t_tetri			tetri_new(t_tetri *last, t_tetri *next, size_t nb, char *tetri);
t_tetri			*parsing(char *file);
void			usage(void);
#endif
