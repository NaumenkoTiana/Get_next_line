/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:40:50 by kroselin          #+#    #+#             */
/*   Updated: 2019/10/11 16:19:40 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_rem(char *rem, char **line)
{
	char			*pointer;

	pointer = NULL;
	if (rem)
	{
		if ((pointer = ft_strchr(rem, '\n')))
		{
			*pointer = '\0';
			*line = ft_strdup(rem);
			ft_strcpy(rem, ++pointer);
		}
		else
		{
			*line = ft_strdup(rem);
			ft_strclr(rem);
		}
	}
	else
		*line = ft_strnew(1);
	return (pointer);
}

t_arr	*new_el(int fd)
{
	t_arr			*new;

	new = (t_arr *)malloc(sizeof(t_arr));
	new->fd = fd;
	new->rem = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int		get_line(int fd, char **line, char **rem)
{
	char			buf[BUFF_SIZE + 1];
	int				b_w_r;
	char			*p;
	char			*tmp;

	b_w_r = 1;
	p = check_rem(*rem, line);
	while (p == 0 && (b_w_r = read(fd, buf, BUFF_SIZE)))
	{
		buf[b_w_r] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			*rem = ft_strdup(++p);
		}
		tmp = *line;
		if (!((*line = ft_strjoin(*line, buf)) || b_w_r < 0))
			return (-1);
		free(tmp);
	}
	return ((b_w_r || ft_strlen(*line)) ? 1 : 0);
}

int		get_next_line(int fd, char **line)
{
	static t_arr	*head;
	t_arr			*tmp;
	int				ret;

	if (fd < 0 || !line || (read(fd, 0, 0)))
		return (-1);
	if (head == NULL)
		head = new_el(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_el(fd);
		tmp = tmp->next;
	}
	ret = get_line(tmp->fd, line, &tmp->rem);
	return (ret);
}
