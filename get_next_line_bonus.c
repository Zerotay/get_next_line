/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 22:07:30 by dongguki          #+#    #+#             */
/*   Updated: 2020/12/13 22:07:30 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		str_len(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

int		make(int fd, char **save, char **line)
{
	int		len;
	char	*temp;

	len = str_len(save[fd]);
	*line = ft_substr(save[fd], 0, len);
	if (save[fd][len] == '\n')
	{
		temp = ft_strdup(save[fd] + len + 1);
		free(save[fd]);
		save[fd] = temp;
		if (save[fd][0] == '\0')
		{
			free(save[fd]);
			save[fd] = 0;
		}
		return (1);
	}
	free(save[fd]);
	save[fd] = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*save[9999];
	char		*temp;
	int			ret;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		temp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		save[fd] = temp;
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	free(buf);
	if (ret < 0)
		return (-1);
	return (make(fd, save, line));
}
