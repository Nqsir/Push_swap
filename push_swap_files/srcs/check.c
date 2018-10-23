/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:03:20 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:03:21 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				check_sort(t_pile *pile)
{
	int		i;
	int		rep[2];

	rep[1] = 0;
	i = 1;
	if (pile->index == 1)
		rep[0] = 0;
	else if (pile->index <= 3)
		rep[0] = 1;
	else if (pile->index <= 5)
		rep[0] = 2;
	else
		rep[0] = 3;
	if (rep[0] != 0)
	{
		while (i < pile->nbr_value - 1)
		{
			if (pile->value[i] < pile->value[i + 1])
				rep[1] += 1;
			i++;
		}
	}
	return (rep[1] == 0 ? rep[1] : rep[0]);
}

static void		check_double(t_pile *pile)
{
	int		loop;
	int		next_step;
	int		pos;
	int		tmp;

	loop = 0;
	next_step = 1;
	while (next_step)
	{
		next_step = 0;
		loop++;
		pos = 1;
		while (pos < pile->nbr_value - loop)
		{
			pile->value[pos] == pile->value[pos + 1] ? ft_error() : 0;
			if (pile->value[pos] > pile->value[pos + 1])
			{
				next_step = 1;
				tmp = pile->value[pos];
				pile->value[pos] = pile->value[pos + 1];
				pile->value[pos + 1] = tmp;
			}
			pos++;
		}
	}
}

void			check_argv(int argc, char **argv)
{
	int					i;
	long long int		val;
	t_pile				*pile_check;

	i = 1;
	while (i < argc)
	{
		if (!ft_strisdigit_pos_neg(argv[i]))
			ft_error();
		val = ft_atoi(argv[i]);
		if (val > INT_MAX || val < INT_MIN)
			ft_error();
		i++;
	}
	pile_check = pile_create(argc, argc - 1, argv);
	check_double(pile_check);
	pile_free(pile_check);
}
