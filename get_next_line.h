/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:48:41 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/09/17 17:00:17 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// # if BUFFER_SIZE < 1
// #  undef BUFFER_SIZE
// #  define BUFFER_SIZE 42
// # endif

char	*get_next_line(int	fd);
size_t	ft_strlen(char	*str);
char	*ft_strchr(char	*s, int	c);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_strdup(const char	*s1);

#endif