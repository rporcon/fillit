/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:27:25 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 15:54:23 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

char	**get_strstr_tetriline(char **strstr, int y)
{
	int		ijkm[4];
	char	**strstr_line;

	init_var_tetriline(&ijkm[0], &ijkm[1], &ijkm[2], &ijkm[3]);
	strstr_line = ft_malloctab2d(5, (y * 4) + 1);
	while (strstr[ijkm[0]] != NULL)
	{
		ijkm[1] = 0;
		while (strstr[ijkm[0]][ijkm[1]] != '\0')
		{
			strstr_line[ijkm[2]][ijkm[3]] = strstr[ijkm[0]][ijkm[1]];
			ijkm[3]++;
			if (strstr[ijkm[0]][ijkm[1]] == '\n')
			{
				norme_sstr_tetriline(ijkm[3]);
				strstr_line[ijkm[2]][ijkm[3]] = '\0';
				ijkm[2]++;
				ijkm[3] = 0;
			}
			ijkm[1]++;
		}
		ijkm[0]++;
	}
	strstr[ijkm[0]] = NULL;
	return (strstr_line);
}

void	norme_sstr_tetriline(int m)
{
	if (m != 5)
	{
		ft_putstr("error\n");
		exit(0);
	}
}

void	init_var_tetriline(int *i, int *j, int *k, int *m)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*m = 0;
}
