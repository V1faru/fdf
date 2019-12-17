/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:39:06 by amurtone          #+#    #+#             */
/*   Updated: 2019/12/17 18:22:27 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

const char	*ft_next_word(const char *s, char c, int skip)
{
	if (skip)
		while (*s != '\0' && *s == c)
			s++;
	else
		while (*s != '\0' && *s != c)
			s++;
	return (s);
}

int		ft_count_words(const char *s, char c)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s = ft_next_word(s, c, 1);
		if (*s != '\0')
		{
			i++;
			s = ft_next_word(s, c, 0);
		}
	}
	return (i);
}