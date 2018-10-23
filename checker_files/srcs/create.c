/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:01:35 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:01:37 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/checker.h"

t_pile		*pile_create(int size, int index, char **str)
{
	t_pile	*new_pile;
	int		i;

	i = 0;
	if ((new_pile = (t_pile *)malloc(sizeof(*new_pile))) == NULL)
		exit(-1);
	new_pile->nbr_value = size;
	new_pile->index = 0;
	if ((new_pile->value = malloc(sizeof(int) * size)) == NULL)
		exit(-1);
	while (i < new_pile->nbr_value)
	{
		if (str == NULL)
			new_pile->value[i] = 0;
		else
			new_pile->value[i] = atoi(str[i]);
		i++;
	}
	new_pile->index = index;
	ft_tabrev(new_pile->value + 1, new_pile->index - 1);
	return (new_pile);
}
