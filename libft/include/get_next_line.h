/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 08:55:27 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 09:31:55 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	unsigned int	size;
	unsigned int	nb;
	char			*endl;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
