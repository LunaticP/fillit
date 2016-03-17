/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 06:36:34 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/17 20:19:30 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 21

typedef unsigned short t_tetri;
t_tetri	*tetri_read(char *path, int *n);
t_tetri	*tetri_adjust(t_tetri *us_tetri, int i_nb);
char	*resolv(unsigned short *tetri[2], int n, int *i, char *grid);
void	tetri_show_result(const char *tetri, const int size);
void	tetri_validate(t_tetri tetri);
void	tetri_sp_check(char *t);
void	tetri_exit(int *fd);
void	usage(void);
void	*rm_tetri(char *grid, int i);
int		pl_intest(char *grid, int x, int *nbr);
int		pl_count(int *count, int i, int *over_ligne, int *x);
int		pl_seg(char *grid, char *ptr);
int		pl_end(char *grid, char *ptr, int i, int *nbr);
void	pl_over(int x, int i, int *over_ligne);
int		pl_over2(char *grid, char *ptr, int nbr, int over_ligne);
char	*pl_int(int *count, int *over_ligne, char *grid, int i);
char	*pl_int2(char *grid_temp, int *x, int i, int *nbr);
int		pl_tetri(char *grid, int x, unsigned short tetriminos, int i);
char	*alloc_grid(int *i, char *grid);
char	*resolvini(unsigned short *tetri[2], int *i, char *grid, int *x);
void	test_exit(char *grid, int *i, int *n, unsigned short *tetri[2]);
#endif
