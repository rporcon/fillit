/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:24:21 by rporcon           #+#    #+#             */
/*   Updated: 2015/12/11 17:26:44 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# define BUF_SIZE 600

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_tetrimino
{
	int		x[4];
	int		y[4];
	int		i;
}				t_tetrimino;

void			norme_fill_sstr_grid_1(int *i, int *k, int *delim);
void			norme_fill_sstr_grid_2(int *i, int *j);
void			norme_fill_sstr_grid_3(char *str_grid, int i);
void			norme_get_tgrid(void);
void			norme_terror_1(int *m, int *k, int *diez_count);
void			norme_terror_2(int diez_count, int yy);
char			**get_tetriminos_grid(char *tetri_grid, int *grid_count);
void			tetriminos_y_size(char *tetri_grid_str, int *y);
char			**ft_malloctab2d(int x, int y);
char			**fill_strstr_tetrigrid(char **sstr_grid, char *str_grid);
void			norme_fill_sstr_grid(int *i, int *k, int *delim);
void			init_strstr_var(int *i, int *j, int *k, int *delim);
void			x_y_error(char **strstr);
void			init_x_y_error_var(int *i, int *j, int *bsn_count, int *error);
void			norme_sstr_tetriline(int m);
char			**get_strstr_tetriline(char **strstr, int y);
t_tetrimino		*get_tetri_form_pos(char **strstr, int yy);
void			analyze_struc(t_tetrimino *tetriminos, int yy);
int				check_tetriminos_1(t_tetrimino *tetriminos, int i);
int				check_tetriminos_2(t_tetrimino *tetriminos, int i);
int				check_tetriminos_3(t_tetrimino *tetriminos, int i);
int				check_tetriminos_4(t_tetrimino *tetriminos, int i);
int				check_tetriminos_5(t_tetrimino *tetriminos, int i);
int				check_tetriminos_6(t_tetrimino *tetriminos, int i);
int				check_tetriminos_7(t_tetrimino *tetriminos, int i);
int				check_all_tetriminos(t_tetrimino *tetriminos, int yy);
void			init_var_tetriline(int *i, int *j, int *k, int *m);
char			**compare(char **s, char **t, int *i);
void			initialize_count(int *count);
int				check(char **s);
char			**tabcpy(char **s, char **t);
int				*check_before(char **s, int *i);
void			move_down(t_tetrimino *tetri_pos);
void			move_top(t_tetrimino *tetri_pos);
void			move_left(t_tetrimino *tetri_pos);
void			move_right(t_tetrimino *tetri_pos);
char			**try_soluce2(char **s, t_tetrimino *p, int *t_nbr, int *i);
void			try_soluce3(char **s, t_tetrimino *p, int *t_nbr, int *i);
void			try_soluce4(char **s, t_tetrimino *p, int *t_nbr, int *i);
void			all_left_top(t_tetrimino *pos, int t_nbr);
void			all_left_top_except_n(t_tetrimino *pos, int n, int t_nbr);
int				size_tab(int tetri_number);
char			**ft_resolve(char **s, t_tetrimino *pos, int *t_nbr);
void			ft_swap_tpos(t_tetrimino *pos1, t_tetrimino *pos2);
char			**print_tetri(char **solution, t_tetrimino pos);
char			**initialize_tab(char **tab, int size);
char			**resolve1(char **s, t_tetrimino *p, int *t_nbr);
char			**resolve2(char **s, t_tetrimino *p, int *t_nbr, int *count);
char			**resolve3(char **s, t_tetrimino *p, int *t_nbr, int *count);
char			**resolve4(char **s, t_tetrimino *p, int *t_nbr, int *count);
char			**resolve5(char **s, t_tetrimino *p, int *t_nbr, int *count);
char			**resolve6(char **s, t_tetrimino *p, int *t_nbr, int *count);
char			**resolve7(char **s, t_tetrimino *p, int *t_nbr, int *count);
void			more_move(char **s, t_tetrimino *p, int *t_nbr, int *t);
char			**if_forest1(char **s, t_tetrimino *p, int *t_nbr, int *count);

#endif
