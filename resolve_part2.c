/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:32:31 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/11 16:22:03 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

char	**resolve6(char **s, t_tetrimino *p, int *t_nbr, int *count)
{
	count[4]++;
	count[3] = 0;
	s = resolve5(s, p, t_nbr, count);
	if (count[4] != 6)
	{
		if (count[4] == 3)
		{
			ft_swap_tpos(&p[t_nbr[0] - 6], &p[t_nbr[0] - 3]);
			ft_swap_tpos(&p[t_nbr[0] - 5], &p[t_nbr[0] - 2]);
			ft_swap_tpos(&p[t_nbr[0] - 4], &p[t_nbr[0] - 1]);
		}
		else
			ft_swap_tpos(&p[t_nbr[0] - 6], &p[t_nbr[0] - 5]);
		return (resolve6(s, p, t_nbr, count));
	}
	else if (count[4] == 6 && t_nbr[0] == 6 && (check(s) == 0))
	{
		t_nbr[1]++;
		free(s);
		return (ft_resolve(s, p, t_nbr));
	}
	else
		return (s);
}

char	**resolve7(char **s, t_tetrimino *p, int *t_nbr, int *count)
{
	count[5]++;
	count[4] = 0;
	s = resolve6(s, p, t_nbr, count);
	if (count[5] != 7)
	{
		if (count[5] == 3)
		{
			ft_swap_tpos(&p[t_nbr[0] - 7], &p[t_nbr[0] - 5]);
			ft_swap_tpos(&p[t_nbr[0] - 6], &p[t_nbr[0] - 4]);
			ft_swap_tpos(&p[t_nbr[0] - 2], &p[t_nbr[0] - 1]);
		}
		else if (count[5] == 6)
			ft_swap_tpos(&p[t_nbr[0] - 7], &p[t_nbr[0] - 5]);
		else
			ft_swap_tpos(&p[t_nbr[0] - 7], &p[t_nbr[0] - 6]);
		return (resolve7(s, p, t_nbr, count));
	}
	else if (count[5] == 7 && t_nbr[0] >= 7 && (check(s) == 0))
	{
		t_nbr[1]++;
		free(s);
		return (ft_resolve(s, p, t_nbr));
	}
	else
		return (s);
}
