/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   opti_mvt.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:03:49 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:03:50 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ra_rb(t_move *mvt)
{
	mvt->nbr_move = 0;
	while (mvt->nbr_move < mvt->ra && mvt->nbr_move < mvt->rb)
		mvt->move[++mvt->nbr_move] = RR;
	while (mvt->nbr_move < (mvt->ra) || mvt->nbr_move < (mvt->rb))
	{
		if (mvt->ra > mvt->rb)
			mvt->move[++mvt->nbr_move] = RA;
		else
			mvt->move[++mvt->nbr_move] = RB;
	}
	mvt->move[++mvt->nbr_move] = PB;
}

static void	ra_rrb(t_move *mvt)
{
	int		i;

	mvt->nbr_move = 0;
	while (mvt->nbr_move < mvt->ra)
		mvt->move[++mvt->nbr_move] = RA;
	i = mvt->ra;
	while (mvt->nbr_move < (mvt->rrb + i))
		mvt->move[++mvt->nbr_move] = RRB;
	mvt->move[++mvt->nbr_move] = PB;
}

static void	rra_rrb(t_move *mvt)
{
	mvt->nbr_move = 0;
	mvt->nbr_move = 0;
	while (mvt->nbr_move < mvt->rra && mvt->nbr_move < mvt->rrb)
		mvt->move[++mvt->nbr_move] = RRR;
	while (mvt->nbr_move < (mvt->rra) || mvt->nbr_move < (mvt->rrb))
	{
		if (mvt->rra > mvt->rrb)
			mvt->move[++mvt->nbr_move] = RRA;
		else
			mvt->move[++mvt->nbr_move] = RRB;
	}
	mvt->move[++mvt->nbr_move] = PB;
}

static void	rra_rb(t_move *mvt)
{
	int		i;

	mvt->nbr_move = 0;
	while (mvt->nbr_move < mvt->rb)
		mvt->move[++mvt->nbr_move] = RB;
	i = mvt->rb;
	while (mvt->nbr_move < (mvt->rra + i))
		mvt->move[++mvt->nbr_move] = RRA;
	mvt->move[++mvt->nbr_move] = PB;
}

void		opti_mvt(t_move *mvt)
{
	int		tab[4];

	tab[0] = (mvt->ra > mvt->rb) ? mvt->ra : mvt->rb;
	tab[1] = mvt->ra + mvt->rrb;
	tab[2] = (mvt->rra > mvt->rrb) ? mvt->rra : mvt->rrb;
	tab[3] = mvt->rra + mvt->rb;
	if (tab[0] <= tab[1] && tab[0] <= tab[2] && tab[0] <= tab[3])
		ra_rb(mvt);
	else if (tab[1] <= tab[0] && tab[1] <= tab[2] && tab[1] <= tab[3])
		ra_rrb(mvt);
	else if (tab[2] <= tab[0] && tab[2] <= tab[1] && tab[2] <= tab[3])
		rra_rrb(mvt);
	else if (tab[3] <= tab[0] && tab[3] <= tab[1] && tab[3] <= tab[2])
		rra_rb(mvt);
}
