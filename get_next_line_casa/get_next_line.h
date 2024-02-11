/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:23:46 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/30 20:23:51 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

size_t	len(const char *s);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_substr(char *s, size_t start, size_t len);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize); 
char	*get_next_line(int fd);

#endif
