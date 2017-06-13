/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:59:59 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 12:04:12 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		check_tetriminos_1(t_tetrimino *tetriminos, int i)
{
	if ((tetriminos[i].x[1] == tetriminos[i].x[0] + 1) &&
			(tetriminos[i].x[2] == tetriminos[i].x[1] + 1) &&
			(tetriminos[i].y[3] == tetriminos[i].y[2] + 1) &&
			tetriminos[i].x[2] == tetriminos[i].x[3] && (tetriminos[i].y[3]
			== tetriminos[i].y[1] + 1) && (tetriminos[i].y[0] ==
			tetriminos[i].y[1]) && (tetriminos[i].y[1] ==
			tetriminos[i].y[2]))
		return (0);
	if ((tetriminos[i].y[1] == tetriminos[i].y[0] + 1) && (tetriminos[i].y[2]
			== tetriminos[i].y[1] + 1) && (tetriminos[i].x[2]
			== tetriminos[i].x[1] - 1) && (tetriminos[i].y[2]
			== tetriminos[i].y[3]) && (tetriminos[i].x[0] == tetriminos[i].x[1])
			&& (tetriminos[i].x[1] == tetriminos[i].x[3]))
		return (0);
	if ((tetriminos[i].y[1] == tetriminos[i].y[0] + 1) && (tetriminos[i].x[2]
			== tetriminos[i].x[1] + 1) && (tetriminos[i].x[3]
			== tetriminos[i].x[2] + 1) && (tetriminos[i].x[0]
			== tetriminos[i].x[1]) && (tetriminos[i].x[2] ==
			tetriminos[i].x[0] + 1) && (tetriminos[i].y[1]
			== tetriminos[i].y[2]) && (tetriminos[i].y[2]
			== tetriminos[i].y[3]))
		return (0);
	return (1);
}

int		check_tetriminos_2(t_tetrimino *tetriminos, int i)
{
	if ((tetriminos[i].x[1] == tetriminos[i].x[0] + 1) && (tetriminos[i].y[0]
			== tetriminos[i].y[1]) && (tetriminos[i].y[2] ==
			tetriminos[i].y[1] + 1) && (tetriminos[i].y[3] ==
			tetriminos[i].y[2] + 1) && (tetriminos[i].x[2] ==
			tetriminos[i].x[1] - 1) && (tetriminos[i].x[0] ==
			tetriminos[i].x[2]) && (tetriminos[i].x[2] == tetriminos[i].x[3]))
		return (0);
	if ((tetriminos[i].x[1] == tetriminos[i].x[0] + 1) && (tetriminos[i].x[2] ==
			tetriminos[i].x[1] + 1) && (tetriminos[i].x[1] ==
			tetriminos[i].x[3]) && (tetriminos[i].y[3] ==
			tetriminos[i].y[1] + 1) && (tetriminos[i].x[2] == tetriminos[i].x[3]
			+ 1) && (tetriminos[i].y[0] == tetriminos[i].y[1]) &&
			(tetriminos[i].y[1] == tetriminos[i].y[2]))
		return (0);
	return (1);
}

int		check_tetriminos_3(t_tetrimino *tetriminos, int i)
{
	if ((tetriminos[i].y[2] == tetriminos[i].y[0] + 1) && (tetriminos[i].y[3]
			== tetriminos[i].y[2] + 1) && (tetriminos[i].y[1]
			== tetriminos[i].y[2]) && (tetriminos[i].x[1] == tetriminos[i].x[0]
			- 1) && (tetriminos[i].x[0] == tetriminos[i].x[2])
			&& (tetriminos[i].x[2] == tetriminos[i].x[3]))
		return (0);
	if ((tetriminos[i].x[2] == tetriminos[i].x[1] + 1) && (tetriminos[i].x[3] ==
			tetriminos[i].x[2] + 1) && (tetriminos[i].y[2]
			== tetriminos[i].y[0] + 1) && (tetriminos[i].x[0]
			== tetriminos[i].x[2]) && (tetriminos[i].y[1] ==
			tetriminos[i].y[2]) && (tetriminos[i].y[2] == tetriminos[i].y[3]))
		return (0);
	if ((tetriminos[i].y[2] == tetriminos[i].y[0] + 1) && (tetriminos[i].y[3]
			== tetriminos[i].y[1] + 1) && (tetriminos[i].y[1]
			== tetriminos[i].y[2]) && (tetriminos[i].x[2] == tetriminos[i].x[0]
			+ 1) && (tetriminos[i].x[1] == tetriminos[i].x[0]) &&
			(tetriminos[i].x[1] == tetriminos[i].x[3]))
		return (0);
	return (1);
}
