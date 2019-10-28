/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:28:24 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/27 18:49:36 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	char			*temp_s1;

	i = 0;
	j = 0;
	temp_s1 = s1;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	if (!(str = malloc(sizeof(char*) * (i + j + 1))))
	{
		free(s1);
		return (0);
	}
	while (s1 && *temp_s1)
		*str++ = *temp_s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = 0;
	free(s1);
	return (str - i - j);
}

void	ft_init(t_buf *tab)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		tab->r[i] = 0;
		tab->buf[i][0] = -1;
		i++;
	}
}

void	ft_reinit(t_buf *tab, int fd)
{
	tab->r[fd] = 0;
	tab->buf[fd][0] = -1;
}
