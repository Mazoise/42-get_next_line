/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:32:00 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/27 18:49:24 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define B BUFFER_SIZE

typedef struct		s_buf
{
	int				r[256];
	char			buf[256][B + 1];
}					t_buf;

int					get_next_line(int fd, char **line);
char				*ft_strjoin(char *s1, char *s2);
void				ft_init(t_buf *tab);
void				ft_reinit(t_buf *tab, int fd);

#endif
