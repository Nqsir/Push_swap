/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:03:57 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:03:59 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_cmd(int value)
{
	if (value == SA)
		ft_printf("sa\n");
	else if (value == SB)
		ft_printf("sb\n");
	else if (value == SS)
		ft_printf("ss\n");
	else if (value == PA)
		ft_printf("pa\n");
	else if (value == PB)
		ft_printf("pb\n");
	else if (value == RA)
		ft_printf("ra\n");
	else if (value == RB)
		ft_printf("rb\n");
	else if (value == RR)
		ft_printf("rr\n");
	else if (value == RRA)
		ft_printf("rra\n");
	else if (value == RRB)
		ft_printf("rrb\n");
	else if (value == RRR)
		ft_printf("rrr\n");
}

void		print_mvt(t_move *mvt)
{
	int		i;

	i = 0;
	while (++i <= mvt->nbr_move)
	{
		print_cmd(mvt->move[i]);
	}
}
