/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft_printf.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 14:45:46 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/03 11:21:18 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include "../../include/libft.h"
# include <stdarg.h>
# include <stddef.h>

typedef enum	e_var
{
	DEF, H, HH, L, LL, J, Z, T
}				t_var;

typedef struct	s_struct
{
	char				type;
	char				flag[5];
	char				nega;
	int					oct;
	int					err;
	va_list				ap;
	t_var				size;
	intmax_t			prec;
	int					width;
	intmax_t			arg;
	char				*s_arg;
	wchar_t				*ws_arg;
	intmax_t			l_arg;
	char				bad_c;
}				t_struct;

int				ft_printf(char *txt, ...);
char			*ft_parse_and_store(t_struct *strt, char *format);
void			ft_initialise(t_struct *strt);
void			ft_get_arg(t_struct *strt);
void			ft_strjoinfree(char *s1, char *s2, t_struct *strt, int n);
void			ft_wstrjoinfree(wchar_t *s1, wchar_t *s2,
				t_struct *strt, int n);
void			ft_for_s(t_struct *strt);
void			ft_for_p(t_struct *strt);
void			ft_for_d_and_i(t_struct *strt);
void			ft_for_o(t_struct *strt);
void			ft_for_u(t_struct *strt);
void			ft_for_x(t_struct *strt);
void			ft_for_c(t_struct *strt);
void			ft_for_pct(t_struct *strt);
void			ft_first_printf(t_struct *strt);
void			ft_bad_parse(t_struct *strt, char *format);

#endif
