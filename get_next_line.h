/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:19:01 by oredoine          #+#    #+#             */
/*   Updated: 2022/12/30 03:12:35 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>

char	*ft_strjoin(char *s1, char *s2);
int		bufferlenght(char *str);
int		ft_strlen(const char *p);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
int		ft_buf_len(const char *p);
#endif