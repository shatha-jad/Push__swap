/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjadalla <sjadalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:13:18 by aalaghba          #+#    #+#             */
/*   Updated: 2022/06/20 17:55:37 by sjadalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>


int	count_chars(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		strs;
	int		strc;
	int		string_length;
	char	**pointer;

	if (!s)
		return (NULL);
	string_length = count_words(s, c);
	pointer = (char **)malloc(sizeof(char *) * (string_length + 1));
	if (!pointer)
		ft_free(pointer);
	strs = 0;
	while (strs < string_length)
	{
		strc = 0;
		while (*s == c)
			s++;
		pointer[strs] = (char *)malloc(sizeof(char) * (count_chars(s, c) + 1));
		if (!pointer)
			ft_free(pointer);
		while (*s && *s != c)
			pointer[strs][strc++] = *s++;
		pointer[strs][strc] = '\0';
		strs++;
	}
	pointer[strs] = 0;
	return (pointer);
}