/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:47:09 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/09/17 17:00:04 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static void	*ft_free(char	*buf)
{
	free(buf);
	return (NULL);
}

static char	*ft_front(char	*save)
{
	char	*tmp;
	int		i;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (tmp == NULL)
		return (ft_free(save));
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		tmp[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		tmp[i] = save[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static void	ft_back(char	*save, char	*buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
	{
		save[0] = '\0';
		return ;
	}
	i++;
	while (buf[i] != '\0')
	{
		save[j] = buf[i];
		i++;
		j++;
	}
	save[j] = '\0';
}

char	*get_next_line(int	fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*buf;
	int			n;

	n = -42;
	buf = ft_strdup(save);
	if (!buf)
		return (NULL);
	while ((ft_strchr(buf, '\n') == NULL) && n != 0)
	{
		n = read(fd, save, BUFFER_SIZE);
		if (n == -1)
		{
			ft_free(buf);
			return (NULL);
		}
		save[n] = '\0';
		buf = ft_strjoin(buf, save);
		if (buf == NULL)
			return (NULL);
	}
	ft_back(save, buf);
	ft_free(buf);
	return (ft_front(buf));
}

/*
#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>

int	main(int	argc, char	*argv[])
{
	int		fd;
	int		i;
	char	*s;

	if (BUFFER_SIZE <= 0)
		return (0);
	if (argc == 1)
	{
		fd = 1;
		while (1)
		{
			s = get_next_line(fd);
			if (s == NULL)
				break ;
			printf("%s", s);
			free(s);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while (1)
			{
				s = get_next_line(fd);
				if (s == NULL)
					break ;
				printf("%s", s);
				free(s);
			}
			printf("\n");
			close(fd);
			i++;
		}
	}
	return (0);
}
*/
/*
int main(int    argc, char **argv) //direct input
{
    char    *str;
    int        fd;
    if(argc == 1)
        fd = 0;
    else
        fd = open(argv[1], O_RDONLY);
    while (1)
    {
        str = get_next_line(fd);
        printf("%s", str);
        if (!str)
            break;
        free(str);
    }
    close(fd);
    //system("leaks a.out");
    return (0);
}
*/
