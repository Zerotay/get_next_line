/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:33:56 by dongguki          #+#    #+#             */
/*   Updated: 2021/01/07 14:57:09 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if ((char)c == 0)
		return ((char*)s);
	return (0);
}

char		*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(s1);
	if (!(dup = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!dst)
		return (0);
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = 0;
	return (ft_strlen(src));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ans = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (0);
	ft_strlcpy(ans, s1, i + 1);
	ft_strlcpy((ans + i), s2, j + 1);
	if ((!*s1 && !*s2) || (!s1 && !s2))
		ans[0] = 0;
	return (ans);
}
