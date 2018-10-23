/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_type_2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:04:28 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:04:29 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_rr_a(t_pile *pile_a, t_move *mvt, int *i)
{
	if (*i >= (pile_a->index - *i))
	{
		*i += 1;
		mvt->move[++mvt->nbr_move] = RRA;
	}
	else if (*i <= (pile_a->index - *i))
	{
		*i -= 1;
		mvt->move[++mvt->nbr_move] = RA;
	}
}

void			ft_place(t_pile *pile_a, t_pile *pile_b, t_move *mvt, int i)
{
	while (1)
	{
		if (pile_b->value[pile_b->index] > pile_a->min
			&& pile_b->value[pile_b->index] < pile_a->max)
		{
			if (pile_b->value[pile_b->index] < pile_a->value[pile_a->index]
				&& pile_b->value[pile_b->index] > pile_a->value[1])
				break ;
		}
		else if (pile_b->value[pile_b->index] > pile_a->max)
		{
			if (pile_a->value[1] == pile_a->max)
				break ;
		}
		else if (pile_b->value[pile_b->index] < pile_a->min)
		{
			if (pile_a->value[pile_a->index] == pile_a->min)
				break ;
		}
		i++;
		ft_rr_a(pile_a, mvt, &i);
		ft_move(pile_a, pile_b, mvt, 1);
	}
}

static void		ft_last_turn_a(t_pile *pile_a, t_pile *pile_b, t_move *mvt)
{
	int		i;
	int		nbr;

	i = 1;
	while (pile_a->value[i] != pile_a->max)
		i++;
	if (i - 1 < pile_a->nbr_value - i)
		nbr = i - 1;
	else
		nbr = pile_a->nbr_value - i;
	while (nbr > 0)
	{
		if ((pile_a->nbr_value - i) < i)
			mvt->move[++mvt->nbr_move] = RA;
		else
			mvt->move[++mvt->nbr_move] = RRA;
		nbr--;
	}
	ft_move(pile_a, pile_b, mvt, 1);
}

static void		ft_insert_a(t_pile *pile_a, t_pile *pile_b, t_move *mvt)
{
	int i;

	i = 0;
	while (pile_b->index > 0)
	{
		i = 0;
		if (pile_a->value[pile_a->index] < pile_a->min)
			pile_a->min = pile_a->value[pile_a->index];
		if (pile_a->value[pile_a->index] > pile_a->max)
			pile_a->max = pile_a->value[pile_a->index];
		ft_place(pile_a, pile_b, mvt, 0);
		mvt->move[++mvt->nbr_move] = PA;
		ft_move(pile_a, pile_b, mvt, 1);
	}
}

void			ft_sort_type_2(t_pile *pile_a, t_pile *pile_b, t_move *mvt)
{
	if (pile_a->index >= 5)
		mvt->move[++mvt->nbr_move] = PB;
	if (pile_a->index >= 4)
		mvt->move[++mvt->nbr_move] = PB;
	ft_move(pile_a, pile_b, mvt, 1);
	ft_sort_type_1(pile_a, pile_b, mvt);
	min_max(pile_a);
	min_max(pile_b);
	ft_insert_a(pile_a, pile_b, mvt);
	min_max(pile_a);
	min_max(pile_b);
	ft_last_turn_a(pile_a, pile_b, mvt);
}
