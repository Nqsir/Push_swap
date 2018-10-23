/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   switch.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:02:25 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:02:27 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/checker.h"

void		switch_cmd(int value, t_pile *pile_a, t_pile *pile_b)
{
	if (value == 0)
		swap(pile_a);
	else if (value == 1)
		swap(pile_b);
	else if (value == 2)
		swap_swap(pile_a, pile_b);
	else if (value == 3)
		push(pile_b, pile_a);
	else if (value == 4)
		push(pile_a, pile_b);
	else if (value == 5)
		rotate(pile_a);
	else if (value == 6)
		rotate(pile_b);
	else if (value == 7)
		rotate_rotate(pile_a, pile_b);
	else if (value == 8)
		reverse_rotate(pile_a);
	else if (value == 9)
		reverse_rotate(pile_b);
	else if (value == 10)
		reverse_rotate_rotate(pile_a, pile_b);
	else
		exit(-1);
}
