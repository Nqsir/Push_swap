/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 19:46:25 by fpupier      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 09:31:58 by fpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*ft_ctrl_fd(t_gnl **lst_fd, int fd)
{
	t_gnl	*new;
	t_gnl	*tmp;

	tmp = *lst_fd;
	if (tmp != NULL)
	{
		while (tmp->next && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp->fd == fd)
			return (tmp);
	}
	if ((new = (t_gnl *)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	new->fd = fd;
	new->str = ft_strnew(0);
	new->size = 0;
	new->nb = 0;
	new->next = NULL;
	if (tmp == NULL)
		*lst_fd = new;
	else
		tmp->next = new;
	return (new);
}

static int		ft_creat_line(t_gnl *lst, char **line)
{
	char	*tmp;

	if (lst->endl != NULL)
	{
		lst->endl[0] = '\0';
		*line = ft_strdup(lst->str);
		lst->endl++;
		tmp = ft_strdup(lst->endl);
		free(lst->str);
		lst->str = tmp;
		lst->size = ft_strlen(lst->str);
	}
	else
	{
		*line = ft_strdup(lst->str);
		tmp = ft_strnew(0);
		free(lst->str);
		lst->str = tmp;
		lst->size = ft_strlen(lst->str);
		lst->endl = NULL;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst_fd = NULL;
	t_gnl			*tmp;
	char			buf[BUFF_SIZE + 1];
	char			*str;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if ((tmp = ft_ctrl_fd(&lst_fd, fd)) == NULL)
		return (-1);
	while ((tmp->endl = ft_strchr(tmp->str, '\n')) == NULL
		&& (tmp->nb = read(tmp->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[tmp->nb] = '\0';
		if ((str = ft_strjoin(tmp->str, buf)) == NULL)
			return (-1);
		free(tmp->str);
		tmp->str = str;
		tmp->size += tmp->nb;
		ft_memset(buf, 0, BUFF_SIZE + 1);
	}
	ft_creat_line(tmp, line);
	if (ft_strlen(*line) == 0 && tmp->size == 0 && tmp->nb == 0)
		return (0);
	return (1);
}
