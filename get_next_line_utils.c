/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreveren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:03:15 by nreveren          #+#    #+#             */
/*   Updated: 2021/11/20 19:03:28 by nreveren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(count * size);
	if (ptr)
		while (count--)
			ptr[count] = 0;
	return ((void *)ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return ((void *)0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++))
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result_str;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result_str = ft_calloc((len1 + len2 + 1), sizeof(*result_str));
	if (result_str)
	{
		i = 0;
		while (i < len1)
		{
			result_str[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < len2)
		{
			result_str[len1 + i] = s2[i];
			i++;
		}
	}
	return (result_str);
}

void	ft_bzero(char *s, size_t n)
{
	while (n--)
		*s++ = 0;
}
