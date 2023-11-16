/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:17:22 by akeryan           #+#    #+#             */
/*   Updated: 2023/11/15 17:06:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_INTERNAL_H
# define GNL_INTERNAL_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

size_t	ft_strlen(const char *str);
int		ft_has_nl(char *tail);
char	*ft_substr(char const *str, unsigned int start, size_t length);
char	*ft_attach(char *tail, char *buf, size_t size);
int		ft_read(int fd, char **tail, char **buf);

#endif
