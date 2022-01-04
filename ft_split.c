/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:39:42 by akeryan           #+#    #+#             */
/*   Updated: 2022/01/02 12:52:49 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void freeAll(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}

int		countWords(char const *str, char c)
{
	while (*str == c)
		str++;
	if (*str == '\0')
		return (0);
	while (*str && *str != c)
		str++;
	return (1 + countWords(str, c));	
}

int		wordLen(char const *str, char c, int isWord)
{
	while (*str == c && isWord == 0)
		str++;
	if (*str == '\0' || *str == c)
		return (0);
	return (1 + wordLen(++str, c, 1));
}

char	**foo(char **out, unsigned int pos, char const *str, char c)
{
	int	i;

	if (out == NULL || str == NULL || *str == '\0')
		return (out);
	while (*str == c)
		str++;
	if (*str == '\0')
		return (out);
	out[pos] = (char *)malloc(wordLen(str, c, 0) + 1);
	if (out[pos] == NULL)
	{
		freeAll(out);
		return (NULL);
	}
	i = 0;
	while (*str && *str != c)
		out[pos][i++] = *str++;
	out[pos][i] = '\0';
	return (foo(out, ++pos, str, c));		
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		len;

	if (s == NULL)
		return (NULL);
	len = countWords(s, c);	
	out = (char **)malloc(sizeof(char *) * (len + 1));
	if (out == NULL)
		return (NULL);
	out = foo(out, 0, s, c);
	return (out);		
}

int main()
{
	char **out;
	char *str = "  tripouille  42  ";
	out = ft_split(str, ' ');	
	printf("%s\n", out[0]);
	printf("%s\n", out[1]);
	freeAll(out);
	return (0);
}