/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:01:45 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:01:47 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	get_arg(int argc, char **argv, t_arg *arg)
{
	int		i;
	int		n;
	char	**tab;

	n = -1;
	arg->ac = -1;
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
	t_pile		*pile_check;
	t_cmd		*cmd;
	t_arg		arg;

	get_arg(argc, argv, &arg);
	check_argv(arg.ac, arg.av);
	pile_a = pile_create(arg.ac, arg.ac - 1, arg.av);
	pile_b = pile_create(arg.ac, 0, NULL);
	pile_check = pile_create(arg.ac, arg.ac - 1, arg.av);
	check_double(pile_check);
	cmd = check_cmd();
	check_solver(pile_a, pile_b, cmd);
	pile_free(pile_a);
	pile_free(pile_b);
	pile_free(pile_check);
	free(cmd->value);
	free(cmd);
	free_arg(&arg);
	return (0);
}
