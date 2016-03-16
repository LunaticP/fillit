/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_sp_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:47:30 by vthomas           #+#    #+#             */
/*   Updated: 2016/03/16 06:19:14 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "stdio.h"

int	check_form(char *buff)
{
    int x;
    int y;
    int around;
    char **form;
    
    x = 0;
    around = 0;
    form = ft_strsplit(buff, '\n');
    while (x < 4)
    {
        y = 0;
        while (y < 4)
        {
            if (form[x][y] == '#')
            {
                around += (y > 0 && form[x][y - 1] == '#') ? 1 : 0;
//				ft_putnbr_desc("J.F Kennedy:\t", around);
                around += (x > 0 && form[x - 1][y] == '#') ? 1 : 0;
//				ft_putnbr_desc("J.F Kennedy:\t", around);
                around += (x < 3 && form[x + 1][y] == '#') ? 1 : 0;
//				ft_putnbr_desc("J.F Kennedy:\t", around);
                around += (y < 3 && form[x][y + 1] == '#') ? 1 : 0;
//				ft_putnbr_desc("J.F Kennedy:\t", around);
//				ft_putendl("");
            }
            y++;
        }
        x++;
    }
    return (around);
}

int check_char(char *buff)
{
    int i;
    int pieces;
    
    i = 0;
    pieces = 0;
    while (i < 21)
    {
        if (buff[i] == '#')
            pieces++;
        if (buff[i] != '.' || buff[i] != '#')
            if ((i + 1) % 5 == 0 && buff[i] != '\n')
                return (1);
        i++;
    }
    if (pieces != 4)
        return (1);
    return (0);
}

void		tetri_sp_check(char *t)
{
    int		a;
   
    if (check_char(t))
        tetri_exit();
    a = check_form(t);
    if (a != 6 && a != 8)
	{
        tetri_exit();
	}
}
