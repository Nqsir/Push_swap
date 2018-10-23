/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:02:38 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:02:39 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/checker.h"

int			*ft_tabrev(int *tab, int size)
{
	int		tampon;
	int		position;

	position = 0;
	while (position < size)
	{
		tampon = tab[position];
		tab[position] = tab[size];
		tab[size] = tampon;
		position++;
		size--;
	}
	return (tab);
}

void		pile_free(t_pile *pile)
{
	free(pile->value);
	free(pile);
}

void		error(void)
{
	ft_printf("Error\n");
	exit(1);
}
