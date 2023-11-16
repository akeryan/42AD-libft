/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:41:53 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/16 16:25:38 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_attach(char *tail, char *buf, size_t size)
{
	char	*str;
	char	*tail_ptr;
	char	*buf_ptr;
	int		i;

	if (tail == NULL)
		return (NULL);
	if (buf == NULL || size == 0)
		return (tail);
	str = (char *)malloc(ft_strlen(tail) + size + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	tail_ptr = tail;
	buf_ptr = buf;
	while (*tail_ptr)
		str[++i] = *tail_ptr++;
	while (size--)
		str[++i] = *buf_ptr++;
	str[++i] = '\0';
	free(tail);
	tail = NULL;
	return (str);
}

int	ft_has_nl(char *tail)
{
	int	i;

	if (tail == NULL)
		return (-1);
	i = 0;
	while (tail[i])
	{
		if (tail[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_read(int fd, char **tail, char **buf)
{
	int		nl;
	ssize_t	bsize;

	nl = ft_has_nl(*tail);
	bsize = 1;
	while (nl == -1 && bsize > 0)
	{
		bsize = read(fd, *buf, BUFFER_SIZE);
		if (bsize > 0)
		{		
			*tail = ft_attach(*tail, *buf, bsize);
			nl = ft_has_nl(*tail);
		}
	}	
	return (nl);
}
