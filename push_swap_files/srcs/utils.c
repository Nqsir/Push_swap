/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:04:56 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:04:58 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		tab_shots_init(t_move *mvt)
{
	int x;

	x = -1;
	while (++x < VAL_MAX)
		mvt->tab[x] = INT_MAX;
}

void		ft_move(t_pile *pile_a, t_pile *pile_b, t_move *mvt, int real)
{
	int		i;

	i = 0;
	mvt->shots = mvt->nbr_move;
	while (++i <= mvt->nbr_move)
	{
		(mvt->move[i] == SA) ? swap(pile_a) : 0;
		(mvt->move[i] == SB) ? swap(pile_b) : 0;
		(mvt->move[i] == SS) ? swap_swap(pile_a, pile_b) : 0;
		(mvt->move[i] == PA) ? push(pile_b, pile_a) : 0;
		(mvt->move[i] == PB) ? push(pile_a, pile_b) : 0;
		(mvt->move[i] == RA) ? rotate(pile_a) : 0;
		(mvt->move[i] == RB) ? rotate(pile_b) : 0;
		(mvt->move[i] == RR) ? rotate_rotate(pile_a, pile_b) : 0;
		(mvt->move[i] == RRA) ? reverse_rotate(pile_a) : 0;
		(mvt->move[i] == RRB) ? reverse_rotate(pile_b) : 0;
		(mvt->move[i] == RRR) ? reverse_rotate_rotate(pile_a, pile_b) : 0;
		(real == 1) ? print_cmd(mvt->move[i]) : 0;
		mvt->move[i] = 0;
	}
	mvt->nbr_move = 0;
	min_max(pile_a);
	min_max(pile_b);
}

void		pile_b_to_pile_a(t_pile *pile_a, t_pile *pile_b, t_move *mvt)
{
	int i;
	int	rotate;

	i = pile_b->index;
	while (pile_b->value[i] != pile_b->max)
		i--;
	mvt->rb = pile_b->index - i;
	mvt->rrb = i;
	rotate = (mvt->rb > mvt->rrb) ? mvt->rrb : mvt->rb;
	while (rotate)
	{
		if (mvt->rb > mvt->rrb)
			mvt->move[++mvt->nbr_move] = RRB;
		else
			mvt->move[++mvt->nbr_move] = RB;
		rotate--;
	}
	i = pile_b->index;
	while (i > 0)
	{
		mvt->move[++mvt->nbr_move] = PA;
		i--;
	}
	ft_move(pile_a, pile_b, mvt, 1);
}

void		min_max(t_pile *pile)
{
	int		i;

	i = 1;
	pile->min = INT_MAX;
	pile->max = INT_MIN;
	while (i <= pile->index)
	{
		if (pile->value[i] > pile->max)
			pile->max = pile->value[i];
		if (pile->value[i] < pile->min)
			pile->min = pile->value[i];
		i++;
	}
}
