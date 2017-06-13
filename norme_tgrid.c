/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_terror_tgrid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:11:57 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 17:23:16 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	norme_fill_sstr_grid_1(int *i, int *k, int *delim)
{
	*i = *i + 1;
	*k = *k + 1;
	*delim = *delim + 1;
}

void	norme_fill_sstr_grid_2(int *j, int *i)
{
	*j = *j + 1;
	*i = *i + 1;
}

void	norme_fill_sstr_grid_3(char *str_grid, int i)
{
	if (str_grid[i - 2] == '\n')
	{
		ft_putstr("error\n");
		exit(0);
	}
}

void	norme_get_tgrid(void)
{
	ft_putstr("error\n");
	exit(0);
}
