/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:03:07 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:03:09 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libft/include/libft.h"
# include "../../libft/libft_printf/include/libft_printf.h"
# include <limits.h>

# define SIZE_CMD 10000
# define VAL_MAX 1000
# define REC 1

typedef struct	s_pile
{
	int			nbr_value;
	int			index;
	int			*value;
	int			min;
	int			max;
}				t_pile;

typedef struct	s_move
{
	int			move[SIZE_CMD];
	int			nbr_move;
	int			shots;
	int			tab[VAL_MAX];
	int			pos;
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	int			best_shot;
}				t_move;

typedef struct	s_dat
{
	int			rec;
	int			add_move;
}				t_dat;

typedef struct	s_arg
{
	int			ac;
	char		**av;
}				t_arg;

typedef enum	e_val
{
	IF, SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
}				t_val;

/*
 ** ------------------------ main.c -----------------------------
*/
void			pile_free(t_pile *pile);
void			ft_error(void);

/*
 ** ------------------------ check.c -----------------------------
*/
void			check_argv(int argc, char **argv);
int				check_sort(t_pile *pile);

/*
 ** ------------------------ create.c -----------------------------
*/
t_pile			*pile_create(int size, int index, char **str);
t_pile			*ft_create_and_copy(t_pile *pile_src);

/*
 ** ------------------------ sort_type_1.c -----------------------------
*/
void			ft_sort_type_1(t_pile *pile_a, t_pile *pile_b, t_move *mvt);

/*
 ** ------------------------ sort_type_2.c -----------------------------
*/
void			ft_sort_type_2(t_pile *pile_a, t_pile *pile_b, t_move *mvt);

/*
 ** ------------------------ sort_type_3.c -----------------------------
*/
void			ft_sort_type_3(t_pile *pile_a, t_pile *pile_b, t_move *mvt);

/*
 ** ------------------------ swap.c -----------------------------
*/
void			swap(t_pile *pile);
void			swap_swap(t_pile *pile_a, t_pile *pile_b);

/*
 ** ------------------------ push.c -----------------------------
*/
void			push(t_pile *pile_tx, t_pile *pile_rx);

/*
 ** ------------------------ rotate.c -----------------------------
*/
void			rotate(t_pile *pile);
void			rotate_rotate(t_pile *pile_a, t_pile *pile_b);
void			reverse_rotate(t_pile *pile);
void			reverse_rotate_rotate(t_pile *pile_a, t_pile *pile_b);
/*
 ** ------------------------ print.c -----------------------------
*/
void			print_cmd(int cmd);
void			print_mvt(t_move *mvt);

/*
 ** ------------------------- opti_mvt.c --------------------------
*/
void			opti_mvt(t_move *mvt);

/*
 ** ------------------------ utils.c -----------------------------
*/
void			ft_move(t_pile *pile_a, t_pile *pile_b, t_move *mvt, int real);
void			pile_b_to_pile_a(t_pile *pile_a, t_pile *pile_b, t_move *mvt);
void			min_max(t_pile *pile);
void			tab_shots_init(t_move *mvt);

#endif
