/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:03:41 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:03:42 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pile_free(t_pile *pile)
{
	free(pile->value);
	free(pile);
}

void		ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

static void	get_arg(int argc, char **argv, t_arg *arg)
{
	int		i;
	int		n;
	char	**tab;

	arg->ac = -1;
	n = -1;
	if (!(arg->av = malloc(sizeof(char *) * VAL_MAX)))
		return ;
	while (++n < argc)
	{
		i = -1;
		tab = ft_strsplit(argv[n], ' ');
		while (tab[++i])
		{
			arg->av[++arg->ac] = ft_strdup(tab[i]);
			free(tab[i]);
		}
		free(tab);
	}
	arg->av[++arg->ac] = NULL;
}

static void	free_arg(t_arg *arg)
{
	int		i;

	i = -1;
	while (++i < arg->ac)
	{
		free(arg->av[i]);
	}
	free(arg->av);
}

int			main(int argc, char **argv)
{
	t_pile		*pile_a;
	t_pile		*pile_b;
	t_move		mvt;
	t_arg		arg;
	int			type_algo;

	mvt.nbr_move = 0;
	get_arg(argc, argv, &arg);
	check_argv(arg.ac, arg.av);
	pile_a = pile_create(arg.ac, arg.ac - 1, arg.av);
	pile_b = pile_create(arg.ac, 0, NULL);
	type_algo = check_sort(pile_a);
	type_algo == 1 ? ft_sort_type_1(pile_a, pile_b, &mvt) : 0;
	type_algo == 2 ? ft_sort_type_2(pile_a, pile_b, &mvt) : 0;
	type_algo == 3 ? ft_sort_type_3(pile_a, pile_b, &mvt) : 0;
	pile_free(pile_a);
	pile_free(pile_b);
	free_arg(&arg);
	return (0);
}
