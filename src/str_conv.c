/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:32:33 by vthomas           #+#    #+#             */
/*   Updated: 2016/05/05 10:36:21 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*str_conv(char *input)
{
	char	*output;

	output = ft_strnew(16);
	if (output == NULL)
		tetri_exit(NULL);
	ft_strncpy(output, &input[0], 4);
	ft_strncpy(output, &input[5], 4);
	ft_strncpy(output, &input[10], 4);
	ft_strncpy(output, &input[15], 4);
	return (output);
}
