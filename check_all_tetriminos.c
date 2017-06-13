/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_tetriminos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:30:05 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 12:06:04 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		check_all_tetriminos(t_tetrimino *tetriminos, int yy)
{
	int		i;

	i = 0;
	while (i < yy && ((check_tetriminos_1(tetriminos, i) == 0)
	|| (check_tetriminos_2(tetriminos, i) == 0)
	|| (check_tetriminos_3(tetriminos, i) == 0)
	|| (check_tetriminos_4(tetriminos, i) == 0)
	|| (check_tetriminos_5(tetriminos, i) == 0)
	|| (check_tetriminos_6(tetriminos, i) == 0)
	|| (check_tetriminos_7(tetriminos, i) == 0)))
		i++;
	if (i == yy)
		return (0);
	else
		return (1);
}
