/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 21:00:09 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/11 16:21:22 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

char	**resolve1(char **s, t_tetrimino *p, int *t_nbr)
{
	int i[4];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	all_left_top(p, t_nbr[0]);
	s = try_soluce2(s, p, t_nbr, i);
	if (t_nbr[0] == 1 && check(s) == 0)
	{
		t_nbr[1]++;
		free(s);
		return (ft_resolve(s, p, t_nbr));
	}
	else
		return (s);
}

char	**resolve2(char **s, t_tetrimino *p, int *t_nbr, int *count)
{
	count[0]++;
	s = resolve1(s, p, t_nbr);
	if (count[0] != 2)
	{
		ft_swap_tpos(&p[t_nbr[0] - 1], &p[t_nbr[0] - 2]);
		return (resolve2(s, p, t_nbr, count));
	}
	else if (count[0] == 2 && t_nbr[0] == 2 && (check(s) == 0))
	{
		t_nbr[1]++;
		free(s);
		return (ft_resolve(s, p, t_nbr));
	}
	else
		return (s);
}

char	**resolve3(char **s, t_tetrimino *p, int *t_nbr, int *count)
{
	count[1]++;
	count[0] = 0;
	s = resolve2(s, p, t_nbr, count);
	if (count[1] != 3)
	{
		ft_swap_tpos(&p[t_nbr[0] - 2], &p[t_nbr[0] - 3]);
		return (resolve3(s, p, t_nbr, count));
	}
	else if (count[1] == 3 && t_nbr[0] == 3 && (check(s) == 0))
	{
		t_nbr[1]++;
		free(s);
		return (ft_resolve(s, p, t_nbr));
	}
	else
		return (s);
}

char	**resolve4(char **s, t_tetrimino *p, int *t_nbr, int *count)
{
	count[2]++;
	count[1] = 0;
	s = resolve3(s, p, t_nbr, count);
	if (count[2] != 4)
	{
		if (count[2] == 3)
			ft_swap_tpos(&p[t_nbr[0] - 1], &p[t_nbr[0] - 4]);
		else
			ft_swap_tpos(&p[t_nbr[0] - 3], &p[t_nbr[0] - 4]);
		return (resolve4(s, p, t_nbr, count));
	}
	else if (count[2] == 4 && t_nbr[0] == 4 && (check(s) == 0))
	{
		t_nbr[1]++;
		free(s);
		return (ft_resolve(s, p, t_nbr));
	}
	else
		return (s);
}

char	**resolve5(char **s, t_tetrimino *p, int *t_nbr, int *count)
{
	count[3]++;
	count[2] = 0;
	s = resolve4(s, p, t_nbr, count);
	if (count[3] != 5)
	{
		ft_swap_tpos(&p[t_nbr[0] - 4], &p[t_nbr[0] - 5]);
		return (resolve5(s, p, t_nbr, count));
	}
	else if (count[3] == 5 && t_nbr[0] == 5 && (check(s) == 0))
	{
		t_nbr[1]++;
		free(s);
		return (ft_resolve(s, p, t_nbr));
	}
	else
		return (s);
}
