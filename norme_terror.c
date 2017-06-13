/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_terror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:13:39 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 14:42:56 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	norme_terror_1(int *m, int *k, int *diez_count)
{
	*diez_count = *diez_count + 1;
	*m = *m + 1;
	if (*m == 4)
	{
		*k = *k + 1;
		*m = 0;
	}
}

void	norme_terror_2(int diez_count, int yy)
{
	if (((double)diez_count / (double)yy) != 4.00)
	{
		ft_putstr("error\n");
		exit(0);
	}
}
