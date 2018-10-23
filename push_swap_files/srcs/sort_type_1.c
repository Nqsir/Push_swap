/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_type_1.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:04:19 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:04:21 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ft_sort_type_1(t_pile *a, t_pile *b, t_move *mvt)
{
	if (a->index == 2)
	{
		if (a->value[2] > a->value[1])
			mvt->move[++mvt->nbr_move] = SA;
	}
	else if (a->index == 3)
	{
		if ((a->value[2] > a->value[1]) && (a->value[1] > a->value[3]))
		{
			mvt->move[++mvt->nbr_move] = SA;
			mvt->move[++mvt->nbr_move] = RA;
		}
		else if ((a->value[1] > a->value[3]) && (a->value[3] > a->value[2]))
			mvt->move[++mvt->nbr_move] = SA;
		else if ((a->value[3] > a->value[1]) && (a->value[1] > a->value[2]))
			mvt->move[++mvt->nbr_move] = RA;
		else if ((a->value[2] > a->value[3]) && (a->value[3] > a->value[1]))
			mvt->move[++mvt->nbr_move] = RRA;
		else if ((a->value[3] > a->value[2]) && (a->value[2] > a->value[1]))
		{
			mvt->move[++mvt->nbr_move] = SA;
			mvt->move[++mvt->nbr_move] = RRA;
		}
	}
	ft_move(a, b, mvt, 1);
}
