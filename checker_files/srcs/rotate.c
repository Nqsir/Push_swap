/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:02:06 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:02:07 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/checker.h"

void		rotate(t_pile *pile)
{
	int		tmp;
	int		i;

	tmp = pile->value[pile->index];
	i = pile->index;
	if (pile->index > 1)
	{
		while (i > 1)
		{
			pile->value[i] = pile->value[i - 1];
			i--;
		}
		pile->value[1] = tmp;
	}
}

void		rotate_rotate(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->index > 1 && pile_b->index > 1)
	{
		rotate(pile_a);
		rotate(pile_b);
	}
}

void		reverse_rotate(t_pile *pile)
{
	int		tmp;
	int		i;

	i = 1;
	tmp = pile->value[i];
	if (pile->index > 1)
	{
		while (i < pile->index)
		{
			pile->value[i] = pile->value[i + 1];
			i++;
		}
		pile->value[i] = tmp;
	}
}

void		reverse_rotate_rotate(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->index > 1 && pile_b->index > 1)
	{
		reverse_rotate(pile_a);
		reverse_rotate(pile_b);
	}
}
