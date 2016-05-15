/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 03:32:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/16 00:39:43 by vthomas          ###   ########.fr       */
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
	int				x;
	int				y;
	int				n;
	char			*tetri;
	char			pos;
}				t_tetri;
void			usage(void);
void			tetri_exit(int *fd);
char			*str_conv(char *input);
void			tetri_resolv(t_tetri *tetri);
t_tetri			*tetri_new(t_tetri *last, size_t nb, char *tetri);
t_tetri			*parsing(char *file);
t_tetri			*tetri_get_first(t_tetri *tetri);
char			**feed_grid(int size);
void			tetri_show(char **grid, int const size);
t_tetri			*f_repos(t_tetri *tetri, char ** grid, int size);
void			tetri_repositionate(t_tetri *tetri, int size);
#endif
