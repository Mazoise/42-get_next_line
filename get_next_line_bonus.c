/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:36:58 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/27 20:01:40 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		ft_first_read(t_buf *tab, int fd, int *i)
{
	if ((*i = read(fd, tab->buf[fd], B)) == -1)
		return (0);
	tab->buf[fd][*i] = 0;
	tab->r[fd] = (*i == B ? 0 : 1);
	if (i != 0 && tab->r[fd] == 1 && tab->buf[fd][*i - 1] == '\n')
		tab->r[fd] = 2;
	return (1);
}

static int		ft_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_copy(char **line, t_buf *tab, char **str, int fd)
{
	int		i;
	int		j;
	char	temp_buf[B + 1];

	i = 0;
	while (tab->buf[fd][i] != '\n' && tab->buf[fd][i])
	{
		temp_buf[i] = tab->buf[fd][i];
		i++;
	}
	temp_buf[i] = 0;
	if (!(*line = ft_strjoin(*str, temp_buf)))
		return (0);
	j = 0;
	while (tab->buf[fd][i] != 0 && tab->buf[fd][++i])
		tab->buf[fd][j++] = tab->buf[fd][i];
	tab->buf[fd][j] = 0;
	if (tab->buf[fd][0] == 0 && tab->r[fd] == 2)
		tab->r[fd] = 0;
	*str = 0;
	return (1);
}

static int		ft_str(char **str, t_buf *tab, int fd, int *i)
{
	if (!(*str = ft_strjoin(*str, tab->buf[fd])))
		return (0);
	if ((*i = read(fd, tab->buf[fd], B)) == -1)
	{
		free(*str);
		return (0);
	}
	tab->buf[fd][*i] = 0;
	if (*i != B && tab->r[fd] == 0)
		tab->r[fd] = 1;
	if (i != 0 && tab->r[fd] == 1 && tab->buf[fd][*i - 1] == '\n')
		tab->r[fd] = 2;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_buf	tab = {.buf[0][0] = -2};
	int				i;
	char			*str;

	str = 0;
	if (tab.buf[0][0] == -2)
		ft_init(&tab);
	if (tab.buf[fd][0] == -1 && (!line || fd > 256 || B <= 0
		|| !(ft_first_read(&tab, fd, &i))))
		return (-1);
	else
		i = B;
	while (ft_check(tab.buf[fd]) == -1 && i == B && !(tab.r[fd]))
	{
		if (!(ft_str(&str, &tab, fd, &i)))
			return (-1);
	}
	if (!(ft_copy(line, &tab, &str, fd)))
		return (-1);
	if (tab.r[fd] == 1 && tab.buf[fd][0] == 0)
	{
		ft_reinit(&tab, fd);
		return (0);
	}
	return (1);
}
