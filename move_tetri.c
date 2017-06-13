/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:45:33 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/11 16:19:36 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	all_left_top(t_tetrimino *pos, int t_nbr)
{
	int	i;

	i = 0;
	while (i < t_nbr)
	{
		while (!(pos[i].x[0] == 0 || pos[i].x[1] == 0 || pos[i].x[2] == 0
					|| pos[i].x[3] == 0))
			move_left(&pos[i]);
		while (!(pos[i].y[0] == 0 || pos[i].y[1] == 0 || pos[i].y[2] == 0
					|| pos[i].y[3] == 0))
			move_top(&pos[i]);
		i++;
	}
}

void	move_right(t_tetrimino *tetri_pos)
{
	tetri_pos->x[0] += 1;
	tetri_pos->x[1] += 1;
	tetri_pos->x[2] += 1;
	tetri_pos->x[3] += 1;
}

void	move_left(t_tetrimino *tetri_pos)
{
	tetri_pos->x[0] -= 1;
	tetri_pos->x[1] -= 1;
	tetri_pos->x[2] -= 1;
	tetri_pos->x[3] -= 1;
}

void	move_top(t_tetrimino *tetri_pos)
{
	tetri_pos->y[0] -= 1;
	tetri_pos->y[1] -= 1;
	tetri_pos->y[2] -= 1;
	tetri_pos->y[3] -= 1;
}

void	all_left_top_except_n(t_tetrimino *pos, int n, int t_nbr)
{
	int i;

	i = 0;
	while (i < t_nbr)
	{
		if (i != n)
		{
			while (!(pos[i].x[0] == 0 || pos[i].x[1] == 0 || pos[i].x[2] == 0
					|| pos[i].x[3] == 0))
				move_left(&pos[i]);
			while (!(pos[i].y[0] == 0 || pos[i].y[1] == 0 || pos[i].y[2] == 0
					|| pos[i].y[3] == 0))
				move_top(&pos[i]);
		}
		i++;
	}
}
