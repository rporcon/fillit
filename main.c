/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:06:59 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 17:21:32 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		main(int argc, char **argv)
{
	int				error_1;
	int				y[2];
	char			**solution;
	char			**strstr;
	t_tetrimino		*tetri_form_pos;

	error_1 = 0;
	if (argc != 2)
		norme_get_tgrid();
	strstr = get_tetriminos_grid(argv[1], &y[0]);
	x_y_error(strstr);
	strstr = get_strstr_tetriline(strstr, y[0]);
	tetri_form_pos = get_tetri_form_pos(strstr, y[0]);
	free(strstr);
	solution = NULL;
	error_1 = check_all_tetriminos(tetri_form_pos, y[0]);
	if (error_1 == 1)
		norme_get_tgrid();
	y[1] = size_tab(y[0]);
	solution = ft_resolve(strstr, tetri_form_pos, y);
	ft_puttab2d(solution);
	return (0);
}
