/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 19:55:48 by adubedat          #+#    #+#             */
/*   Updated: 2015/12/11 16:17:14 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

char	**compare(char **s, char **t, int *i)
{
	while (t[i[1]])
	{
		while (t[i[1]][i[2]])
		{
			if (s[i[1]][i[2]] == ('A' + i[0]) && t[i[1]][i[2]] == ('A' + i[0]))
			{
				i[0]++;
				i = check_before(s, i);
				return (compare(s, t, i));
			}
			else if (s[i[1]][i[2]] == ('A' + i[0])
					&& t[i[1]][i[2]] != ('A' + i[0]))
				return (s);
			else if (t[i[1]][i[2]] == ('A' + i[0])
					&& s[i[1]][i[2]] != ('A' + i[0]))
				return (s = tabcpy(s, t));
			i[2]++;
		}
		i[2] = 0;
		i[1]++;
	}
	return (s);
}

void	initialize_count(int *count)
{
	int i;

	i = 0;
	while (i < 8)
	{
		count[i] = 0;
		i++;
	}
}

int		check(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**tabcpy(char **s, char **t)
{
	int i;
	int j;

	i = 0;
	while (t[i])
	{
		j = 0;
		while (t[i][j])
		{
			s[i][j] = t[i][j];
			j++;
		}
		i++;
	}
	return (s);
}
