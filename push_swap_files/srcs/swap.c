/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:04:47 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:04:48 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		swap(t_pile *pile)
{
	int		tmp;
	int		index;

	if (pile->index > 1)
	{
		index = pile->index;
		tmp = pile->value[index];
		pile->value[index] = pile->value[index - 1];
		pile->value[index - 1] = tmp;
	}
}

void		swap_swap(t_pile *pile_a, t_pile *pile_b)
{
	swap(pile_a);
	swap(pile_b);
}
