/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:07:05 by aespinos          #+#    #+#             */
/*   Updated: 2022/06/23 18:20:33 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	nb;
	{
		nb = 0;
		while (*s != '\0')
		{
			s++;
			nb++;
		}
		return (nb);
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (NULL);
	while (s[a] != '\0')
	{
		if (s[a] == (unsigned char) c)
			return ((char *)s + a);
		a++;
	}
	if (s[a] == (unsigned char)c)
		return ((char *)(s + a));
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		cont;

	cont = 0;
	dst = malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (0);
	while (s1[cont])
	{	
		dst[cont] = s1[cont];
		cont++;
	}
	dst[cont] = '\0';
	return (dst);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	k = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (++i < len1)
		str[i] = s1[i];
	while (++k < len2)
	{
		str[i] = s2[k];
		i++;
	}
	str[i] = '\0';
	free((void *)s1);
	return (str);
}
