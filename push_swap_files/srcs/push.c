/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:04:05 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:04:06 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		push(t_pile *pile_tx, t_pile *pile_rx)
{
	if (pile_tx->index > 0)
	{
		pile_rx->index++;
		pile_rx->value[pile_rx->index] = pile_tx->value[pile_tx->index];
		pile_tx->value[pile_tx->index] = 0;
		pile_tx->index--;
	}
}
