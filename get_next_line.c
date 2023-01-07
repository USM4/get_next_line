/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:21:43 by oredoine          #+#    #+#             */
/*   Updated: 2023/01/03 20:59:03 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	look_for_new_line(char *r)
{
	int	i;

	i = 0;
	if (!r)
		return (-1);
	while (r[i])
	{
		if (r[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*cut(char *str)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_buf_len(str);
	if (!len)
		return (NULL);
	temp = malloc(len * sizeof(char) + 1);
	if (!temp)
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*clean_sht(char *str)
{
	int		i;
	int		len;
	char	*temp;
	int		p;

	i = 0;
	if (!str)
		return (free(str), NULL);
	p = look_for_new_line(str) + 1;
	if (p == 0)
		return (free(str), NULL);
	len = ft_strlen(str + p);
	temp = malloc(len + 1);
	if (!temp)
		return (free(temp), NULL);
	while (str[p])
	{
		temp[i] = str[p];
		i++;
		p++;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}

char	*ft_read(char *str, int fd)
{
	char	*buffer;
	char	*tmp;
	int		i;

	i = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		free(buffer);
	while (look_for_new_line(str) == -1 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i == -1)
			return (free(buffer), free(str), NULL);
		buffer[i] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tempo;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!str)
		str = ft_strdup("");
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	tempo = cut(str);
	str = clean_sht(str);
	return (tempo);
}
int main()
{
	int fd;
	fd = open("txt.txt",O_RDONLY);
	char *line;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s",line);
		line = get_next_line(fd);		
	}
	
}
