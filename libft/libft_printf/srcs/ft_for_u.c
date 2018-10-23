/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_for_u.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/28 19:25:38 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/07 10:21:30 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft_printf.h"

static void		ft_flags(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;

	if (strt->arg != '0' && strt->prec != 0)
	{
		if (strt->width && strt->prec < 0 && strt->flag[1] && !strt->flag[2])
		{
			strt->prec = strt->width;
			strt->width = 0;
			tmpsarg = ft_strnew(strt->l_arg);
			ft_strcpy(tmpsarg, strt->s_arg);
			tmps = ft_strnew(strt->l_arg + 1);
			ft_memset(tmps, '0', strt->prec - strt->l_arg - 2);
			ft_strjoinfree(tmps, tmpsarg, strt, 0);
		}
		strt->l_arg = ft_strlen(strt->s_arg);
		tmps = ft_strnew(1);
		ft_strncpy(tmps, "0", 1);
		tmpsarg = ft_strnew(strt->l_arg);
		ft_strcpy(tmpsarg, strt->s_arg);
		ft_strjoinfree(tmps, tmpsarg, strt, 0);
	}
}

static void		ft_width(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;
	char	c;

	c = ' ';
	if (strt->flag[1] && !strt->flag[2] && strt->prec < 0)
		c = '0';
	strt->l_arg = ft_strlen(strt->s_arg);
	tmps = ft_strnew(strt->width - strt->l_arg);
	ft_memset(tmps, c, strt->width - strt->l_arg);
	tmpsarg = ft_strnew(strt->l_arg);
	ft_strcpy(tmpsarg, strt->s_arg);
	ft_strjoinfree(tmps, tmpsarg, strt, strt->flag[2]);
}

static void		ft_prec(t_struct *strt)
{
	char	*tmps;
	char	*tmpsarg;

	tmpsarg = ft_strnew(strt->l_arg + 1);
	(strt->prec == 0 && strt->arg == 0) ? (ft_strcpy(tmpsarg, " ")) :
		ft_strcpy(tmpsarg, strt->s_arg);
	if (strt->prec == 0 && strt->arg == 0)
		ft_bzero(tmpsarg, 1);
	tmps = ft_strnew(strt->l_arg + 1);
	if (strt->prec > strt->l_arg)
		ft_memset(tmps, '0', strt->prec - strt->l_arg);
	ft_strjoinfree(tmps, tmpsarg, strt, 0);
	strt->l_arg = ft_strlen(strt->s_arg);
}

void			ft_for_u(t_struct *strt)
{
	if (strt->size == L || strt->type == 'U')
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == H)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == HH)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == LL)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == J)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == Z)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else if (strt->size == T)
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	else
		strt->s_arg = ft_itoa_base_unsi(strt->arg, 10, "0123456789");
	strt->l_arg = ft_strlen(strt->s_arg);
	if (strt->prec >= 0 || (strt->width && strt->prec < 0 && strt->flag[1]))
		ft_prec(strt);
	if (strt->flag[0])
		ft_flags(strt);
	if (strt->width > strt->l_arg)
		ft_width(strt);
}
