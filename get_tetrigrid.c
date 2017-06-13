/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:55:06 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 18:18:23 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

char	**get_tetriminos_grid(char *tetri_grid, int *grid_count)
{
	int		fd_ret[2];
	int		y;
	char	buf[BUF_SIZE];
	char	**sstr_grid;

	y = 0;
	if ((fd_ret[0] = open(tetri_grid, O_RDONLY, S_IRUSR)) == -1)
		norme_get_tgrid();
	if ((fd_ret[1] = read(fd_ret[0], buf, BUF_SIZE)))
		buf[fd_ret[1]] = '\0';
	if (fd_ret[1] == 0)
		norme_get_tgrid();
	tetriminos_y_size(buf, &y);
	*grid_count = y;
	sstr_grid = ft_malloctab2d(20, y);
	sstr_grid = fill_strstr_tetrigrid(sstr_grid, buf);
	if (fd_ret[1] == 1)
		norme_get_tgrid();
	if (close(fd_ret[0]) == -1)
		norme_get_tgrid();
	return (sstr_grid);
}

char	**ft_malloctab2d(int x, int y)
{
	char	**strstr;
	int		i;

	i = 0;
	if ((strstr = (char **)malloc(sizeof(char *) * (y + 1))) == NULL)
		return (NULL);
	while (i < y)
	{
		if ((strstr[i] = (char *)malloc(sizeof(char) * (x + 1))) == NULL)
			return (NULL);
		strstr[i][x] = '\0';
		i++;
	}
	strstr[i] = NULL;
	return (strstr);
}

void	tetriminos_y_size(char *tetri_grid_str, int *y)
{
	int		i;
	int		yy;

	i = 0;
	yy = 0;
	while (tetri_grid_str[i] != '\0')
	{
		if (tetri_grid_str[i] == '\n')
			yy += 1;
		if (yy == 5)
		{
			yy = 0;
			*y = *y + 1;
		}
		i++;
	}
	if (*y >= 26)
		norme_get_tgrid();
	*y += 1;
}

char	**fill_strstr_tetrigrid(char **sstr_grid, char *str_grid)
{
	int		i[4];

	init_strstr_var(&i[0], &i[1], &i[2], &i[3]);
	while (str_grid[i[0]] != '\0')
	{
		i[2] = 0;
		i[3] = 0;
		while (i[3] < 20)
		{
			if (str_grid[i[0]] != '.' && str_grid[i[0]] != '#' && str_grid[i[0]]
					!= '\n')
				norme_get_tgrid();
			sstr_grid[i[1]][i[2]] = str_grid[i[0]];
			norme_fill_sstr_grid_1(&i[0], &i[2], &i[3]);
		}
		if (str_grid[i[0]] == '\0')
			i[0]--;
		if (str_grid[i[0]] != '\n')
			norme_get_tgrid();
		sstr_grid[i[1]][i[2]] = '\0';
		norme_fill_sstr_grid_2(&i[1], &i[0]);
	}
	norme_fill_sstr_grid_3(str_grid, i[0]);
	sstr_grid[i[1]] = NULL;
	return (sstr_grid);
}

void	init_strstr_var(int *i, int *j, int *k, int *delim)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*delim = 0;
}
