/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:01:08 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:01:09 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../libft/include/libft.h"
# include "../../libft/libft_printf/include/libft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# define SIZE_CMD 10000
# define VAL_MAX 1000

typedef struct		s_pile
{
	int				nbr_value;
	int				index;
	int				*value;
}					t_pile;

typedef struct		s_cmd
{
	int				index;
	char			*value;
}					t_cmd;

typedef struct		s_arg
{
	int				ac;
	char			**av;
}					t_arg;

/*
** ------------------------ check.c -----------------------------
*/
void				check_argv(int argc, char **argv);
t_cmd				*check_cmd(void);
int					check_solver(t_pile *pile_a, t_pile *pile_b, t_cmd *cmd);
void				check_double(t_pile *pile);

/*
** ------------------------ create.c -----------------------------
*/
t_pile				*pile_create(int size, int index, char **str);

/*
** ------------------------ swap.c -----------------------------
*/
void				swap(t_pile *pile);
void				swap_swap(t_pile *pile_a, t_pile *pile_b);

/*
** ------------------------ push.c -----------------------------
*/
void				push(t_pile *pile_tx, t_pile *pile_rx);

/*
** ------------------------ rotate.c -----------------------------
*/
void				rotate(t_pile *pile);
void				rotate_rotate(t_pile *pile_a, t_pile *pile_b);
void				reverse_rotate(t_pile *pile);
void				reverse_rotate_rotate(t_pile *pile_a,
													t_pile *pile_b);

/*
** ------------------------ switch.c -----------------------------
*/
void				switch_cmd(int cmd, t_pile *pile_a, t_pile *pile_b);

/*
** ------------------------ utils.c -----------------------------
*/
int					*ft_tabrev(int *tab, int size);
void				pile_free(t_pile *pile);
void				error(void);
#endif
