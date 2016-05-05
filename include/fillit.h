/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 06:36:34 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/05 05:58:10 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# define BUF_SIZE 21

void	tetri_show_result(const char *tetri, const int size);
void	tetri_validate(t_tetri tetri);
void	tetri_sp_check(char *t);
void	tetri_exit(int *fd);
void	usage(void);
void	test_exit(char *grid, int *i, int *n, unsigned short *tetri[2]);
#endif
