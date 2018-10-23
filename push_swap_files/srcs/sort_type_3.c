/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_type_3.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:04:38 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:04:39 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rr_b(t_pile *pile_a, t_pile *pile_b, t_move *mvt, int n)
{
	int		i;
	int		bot_b;

	i = 0;
	while (1)
	{
		bot_b = pile_b->index - i + 1;
		if (i == 0)
			bot_b = 1;
		if (pile_a->value[n] > pile_b->min && pile_a->value[n] < pile_b->max)
		{
			if (pile_a->value[n] > pile_b->value[pile_b->index - i]
					&& pile_a->value[n] < pile_b->value[bot_b])
				break ;
		}
		else if (pile_a->value[n] > pile_b->max &&
				pile_b->value[pile_b->index - i] == pile_b->max)
			break ;
		else if (pile_a->value[n] < pile_b->min &&
				pile_b->value[bot_b] == pile_b->min)
			break ;
		i++;
	}
	mvt->rrb = pile_b->index - i;
	mvt->rb = i;
}

static void	ft_calc(t_pile *pile_a, t_pile *pile_b, t_move *mvt, int n)
{
	mvt->ra = 0;
	mvt->rra = 0;
	mvt->rb = 0;
	mvt->rrb = 0;
	mvt->ra = pile_a->index - n;
	mvt->rra = n;
	ft_rr_b(pile_a, pile_b, mvt, n);
	opti_mvt(mvt);
}

static void	ft_insert_a(t_pile *pile_a, t_pile *pile_b, t_move *mvt, t_dat data)
{
	int			n;
	t_pile		*c;
	t_pile		*d;
	t_dat		t;

	t.rec = data.rec - 1;
	n = pile_a->index;
	while (n)
	{
		if (data.rec == REC)
			mvt->pos = n;
		mvt->shots = 0;
		c = ft_create_and_copy(pile_a);
		d = ft_create_and_copy(pile_b);
		ft_calc(c, d, mvt, n);
		ft_move(c, d, mvt, 0);
		t.add_move = data.add_move + mvt->shots;
		if (t.rec > 0 && c->index != 0 && t.add_move < mvt->tab[mvt->pos])
			ft_insert_a(c, d, mvt, t);
		if ((t.rec == 0 || c->index == 0) && t.add_move < mvt->tab[mvt->pos])
			mvt->tab[mvt->pos] = t.add_move;
		pile_free(c);
		pile_free(d);
		n--;
	}
}

static void	ft_first(t_pile *pile_a, t_pile *pile_b, t_move *mvt)
{
	if ((pile_a->value[pile_a->index] > pile_a->value[pile_a->index - 1]))
		mvt->move[++mvt->nbr_move] = SA;
	mvt->move[++mvt->nbr_move] = PB;
	mvt->move[++mvt->nbr_move] = PB;
	ft_move(pile_a, pile_b, mvt, 1);
}

void		ft_sort_type_3(t_pile *pile_a, t_pile *pile_b, t_move *mvt)
{
	t_dat	data;
	int		i;
	int		best_index;

	data.rec = REC;
	ft_first(pile_a, pile_b, mvt);
	while (pile_a->index > 0)
	{
		i = 0;
		data.add_move = 0;
		tab_shots_init(mvt);
		ft_insert_a(pile_a, pile_b, mvt, data);
		mvt->best_shot = INT_MAX;
		best_index = 0;
		while (++i <= pile_a->index)
		{
			if (mvt->tab[i] < mvt->best_shot)
				best_index = i;
			if (mvt->tab[i] < mvt->best_shot)
				mvt->best_shot = mvt->tab[i];
		}
		ft_calc(pile_a, pile_b, mvt, best_index);
		ft_move(pile_a, pile_b, mvt, 1);
	}
	pile_b_to_pile_a(pile_a, pile_b, mvt);
}
