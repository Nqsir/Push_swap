/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 19:01:22 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/29 19:01:24 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/checker.h"

void		check_double(t_pile *pile)
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
			pile->value[pos] == pile->value[pos + 1] ? error() : 0;
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

void		check_argv(int argc, char **argv)
{
	int					i;
	long long int		val;

	i = 1;
	while (i < argc)
	{
		if (!ft_strisdigit_pos_neg(argv[i]))
			error();
		val = ft_atoi(argv[i]);
		if (val > 2147483647 || val < -2147483648)
			error();
		i++;
	}
}

static int	check_conv(char *str)
{
	if (ft_strcmp("sa", str) == 0)
		return (0);
	else if (ft_strcmp("sb", str) == 0)
		return (1);
	else if (ft_strcmp("ss", str) == 0)
		return (2);
	else if (ft_strcmp("pa", str) == 0)
		return (3);
	else if (ft_strcmp("pb", str) == 0)
		return (4);
	else if (ft_strcmp("ra", str) == 0)
		return (5);
	else if (ft_strcmp("rb", str) == 0)
		return (6);
	else if (ft_strcmp("rr", str) == 0)
		return (7);
	else if (ft_strcmp("rra", str) == 0)
		return (8);
	else if (ft_strcmp("rrb", str) == 0)
		return (9);
	else if (ft_strcmp("rrr", str) == 0)
		return (10);
	else
		return (-1);
}

t_cmd		*check_cmd(void)
{
	t_cmd	*rep;
	char	*tmp;
	int		i;

	i = 1;
	if ((rep = (t_cmd*)malloc(sizeof(t_cmd))) == NULL)
		exit(-1);
	if ((rep->value = (char*)malloc(sizeof(char) * SIZE_CMD + 1)) == NULL)
		exit(-1);
	while (get_next_line(0, &tmp) == 1)
	{
		if ((rep->value[i++] = check_conv(tmp)) < 0)
			error();
		free(tmp);
	}
	free(tmp);
	i -= 1;
	rep->index = i;
	return (rep);
}

int			check_solver(t_pile *pile_a, t_pile *pile_b, t_cmd *cmd)
{
	int		i;
	int		rep;

	i = 1;
	rep = 1;
	while (i <= cmd->index)
		switch_cmd(cmd->value[i++], pile_a, pile_b);
	i = 1;
	while (i < pile_a->index)
	{
		if (pile_a->value[i] < pile_a->value[i + 1])
			rep = 0;
		i++;
	}
	if (pile_b->index != 0 || rep == 0)
	{
		ft_printf("KO\n");
		exit(1);
	}
	else
		ft_printf("OK\n");
	return (0);
}
