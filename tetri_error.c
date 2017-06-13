/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:11:39 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 15:29:25 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void			x_y_error(char **strstr)
{
	int					i;
	int					j;
	int					bsn_error[2];

	init_x_y_error_var(&i, &j, &bsn_error[0], &bsn_error[1]);
	while (strstr[i] != NULL)
	{
		j = 0;
		while (strstr[i][j] != '\0')
		{
			if (strstr[i][j] != '.' && strstr[i][j] != '#' && strstr[i][j]
					!= '\n')
				norme_get_tgrid();
			if (strstr[i][j] == '\n')
				bsn_error[0]++;
			j++;
		}
		i++;
	}
	if ((bsn_error[0] / i) != 4)
		norme_get_tgrid();
}

t_tetrimino		*get_tetri_form_pos(char **strstr, int yy)
{
	int					i[5];
	t_tetrimino			*tetri_form;

	init_x_y_error_var(&i[0], &i[1], &i[2], &i[3]);
	i[4] = 0;
	tetri_form = (t_tetrimino *)malloc(sizeof(t_tetrimino) * yy);
	while (strstr[i[0]])
	{
		i[1] = 0;
		if (i[0] % 4 == 0)
			tetri_form[i[2]].i = i[0] / 4;
		while (strstr[i[0]][i[1]])
		{
			if (strstr[i[0]][i[1]] == '#')
			{
				(tetri_form + i[2])->x[i[3]] = i[1];
				tetri_form[i[2]].y[i[3]] = i[0];
				norme_terror_1(&i[3], &i[2], &i[4]);
			}
			i[1]++;
		}
		i[0]++;
	}
	norme_terror_2(i[4], yy);
	return (tetri_form);
}

void			init_x_y_error_var(int *i, int *j, int *k, int *m)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*m = 0;
}
