/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:58:29 by kroselin          #+#    #+#             */
/*   Updated: 2019/10/11 15:48:18 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft/libft.h"

typedef struct		s_arr
{
	int				fd;
	char			*rem;
	struct s_arr	*next;
}					t_arr;

int					get_line(int fd, char **line, char **rem);
int					get_next_line(const int fd, char **line);
char				*check_rem(char *rem, char **line);
t_arr				*new_el(int fd);
#endif
