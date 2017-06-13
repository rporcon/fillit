/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 20:13:28 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/11 16:30:38 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		size_tab(int tetri_number)
{
	int i;

	i = 0;
	while (i * i < tetri_number * 4)
		i++;
	return (i);
}

char	**ft_resolve(char **s, t_tetrimino *pos, int *t_nbr)
{
	int	count[25];

	initialize_count(count);
	all_left_top(pos, t_nbr[0]);
	s = ft_malloctab2d(t_nbr[1], t_nbr[1]);
	s = initialize_tab(s, t_nbr[1]);
	s = if_forest1(s, pos, t_nbr, count);
	return (s);
}

void	ft_swap_tpos(t_tetrimino *pos1, t_tetrimino *pos2)
{
	t_tetrimino	temp;

	temp = *pos1;
	*pos1 = *pos2;
	*pos2 = temp;
}

char	**print_tetri(char **solution, t_tetrimino pos)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		solution[pos.y[j]][pos.x[j]] = 'A' + pos.i;
		j++;
	}
	return (solution);
}

char	**initialize_tab(char **tab, int size)
{
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}
