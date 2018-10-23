/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strisxdigit.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:48:54 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 19:48:54 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisxdigit(const char *s)
{
	if (s == NULL || *s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (ft_isxdigit((int)*s) == 0)
			return (0);
		s++;
	}
	return (1);
}
