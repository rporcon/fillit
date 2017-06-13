/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_soluce4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:55:24 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/11 16:22:33 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	try_soluce4(char **s, t_tetrimino *p, int *t_nbr, int *i)
{
	int		j;
	char	**t;

	j = 0;
	t = ft_malloctab2d(t_nbr[1], t_nbr[1]);
	t = initialize_tab(t, t_nbr[1]);
	while (j < t_nbr[0])
	{
		while (!(t[p[j].y[0]][p[j].x[0]] == '.'
		&& t[p[j].y[1]][p[j].x[1]] == '.'
		&& t[p[j].y[2]][p[j].x[2]] == '.' && t[p[j].y[3]][p[j].x[3]] == '.'))
		{
			if (p[j].x[0] + 1 > t_nbr[1] * 16 || p[j].x[1] + 1 > t_nbr[1] * 16
			|| p[j].x[2] + 1 > t_nbr[1] * 16 || p[j].x[3] + 1 > t_nbr[1] * 16)
			{
				free(t);
				return ;
			}
			else
				move_right(&p[j]);
		}
		t = print_tetri(t, p[j++]);
	}
	s = compare(s, t, i);
	free(t);
}

void	more_move(char **s, t_tetrimino *p, int *t_nbr, int *i)
{
	move_right(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_down(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_left(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_left(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_left(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_left(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_left(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_left(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_top(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_right(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_right(&p[i[3]]);
	try_soluce3(s, p, t_nbr, i);
	move_right(&p[i[3]]);
}

char	**if_forest1(char **s, t_tetrimino *p, int *t_nbr, int *count)
{
	if (t_nbr[0] == 1)
		return (resolve1(s, p, t_nbr));
	if (t_nbr[0] == 2)
		return (resolve2(s, p, t_nbr, count));
	if (t_nbr[0] == 3)
		return (resolve3(s, p, t_nbr, count));
	if (t_nbr[0] == 4)
		return (resolve4(s, p, t_nbr, count));
	if (t_nbr[0] == 5)
		return (resolve5(s, p, t_nbr, count));
	if (t_nbr[0] == 6)
		return (resolve6(s, p, t_nbr, count));
	else
		return (resolve7(s, p, t_nbr, count));
}
