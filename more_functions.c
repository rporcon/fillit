/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:16:02 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/11 16:49:08 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		*check_before(char **s, int *i)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (s[k] && s[k][j] != ('A' + i[0] - 1))
	{
		j = 0;
		while (s[k][j] && s[k][j] != ('A' + i[0] - 1))
		{
			if (s[k][j] >= ('A' + i[0]))
			{
				i[1] = 0;
				i[2] = 0;
				return (i);
			}
			j++;
		}
		k++;
	}
	return (i);
}

void	move_down(t_tetrimino *tetri_pos)
{
	tetri_pos->y[0] += 1;
	tetri_pos->y[1] += 1;
	tetri_pos->y[2] += 1;
	tetri_pos->y[3] += 1;
}

char	**try_soluce2(char **s, t_tetrimino *p, int *t_nbr, int *i)
{
	i[3] = 0;
	all_left_top(p, t_nbr[0]);
	while (i[3] < t_nbr[0])
	{
		try_soluce3(s, p, t_nbr, i);
		move_right(&p[i[3]]);
		try_soluce3(s, p, t_nbr, i);
		move_right(&p[i[3]]);
		try_soluce3(s, p, t_nbr, i);
		more_move(s, p, t_nbr, i);
		i[3]++;
	}
	return (s);
}

void	try_soluce3(char **s, t_tetrimino *p, int *t_nbr, int *i)
{
	int		j;
	char	**t;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	j = 0;
	t = ft_malloctab2d(t_nbr[1], t_nbr[1]);
	t = initialize_tab(t, t_nbr[1]);
	all_left_top_except_n(p, i[3], t_nbr[0]);
	if ((t_nbr[0] == 1 && p[i[3]].y[0] < t_nbr[1] && p[i[3]].y[1] < t_nbr[1]
		&& p[i[3]].y[2] < t_nbr[1] && p[i[3]].y[3] < t_nbr[1])
		|| (t_nbr[0] >= 2 && p[i[3]].y[0] < t_nbr[1] && p[i[3]].y[1] < t_nbr[1]
		&& p[i[3]].y[2] < t_nbr[1] && p[i[3]].y[3] < t_nbr[1]
		&& p[i[3] + 1].y[0] < t_nbr[1] && p[i[3] + 1].y[1] < t_nbr[1]
		&& p[i[3] + 1].y[2] < t_nbr[1] && p[i[3] + 1].y[3] < t_nbr[1]))
	{
		if ((t[p[i[3]].y[0]][p[i[3]].x[0]] == '.'
			&& t[p[i[3]].y[1]][p[i[3]].x[1]] == '.'
			&& t[p[i[3]].y[2]][p[i[3]].x[2]] == '.'
			&& t[p[i[3]].y[3]][p[i[3]].x[3]] == '.'))
			try_soluce4(s, p, t_nbr, i);
	}
	free(t);
}
