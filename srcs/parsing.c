/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:14:02 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/18 21:42:05 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		ft_count(char **tab)
{
	int count;

	count = 0;
	while (tab[count] != 0)
		count++;
	return (count);
}

void	*free_tab(char **tmp)
{
	int k;

	k = -1;
	while (tmp[++k])
	{
		if (tmp[k] != NULL)
		{
			free(tmp[k]);
			tmp[k] = NULL;
		}
	}
	if (tmp != NULL)
		free(tmp);
	return (NULL);
}

int		**parse_in_int(char **tab, int line_value)
{
	int		**grid;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	if ((grid = (int **)malloc(sizeof(int*) * line_value)) == NULL)
		return (NULL);
	grid[line_value] = 0;
	while (i < line_value)
	{
		tmp = ft_split(tab[i], " ");
		j = 0;
		if ((grid[i] = (int*)malloc(sizeof(int) * ft_count(tmp))) == NULL)
			return (NULL);
		while (j < ft_count(tmp))
		{
			grid[i][j] = ft_getnbr(tmp[j]);
			j++;
		}
		tmp = free_tab(tmp);
		i++;
	}
	return (grid);
}

/*char	**fill_tab(int line_value, char *file)
{
	int		fd;
	int		i;
	char	**tab;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * line_value)) == NULL)
		return (NULL);
	fd = open(file, O_RDONLY, S_IREAD);
	while (i < line_value)
	{
		get_next_line(fd, &tab[i]);
		if (check_char(tab[i]) == 0)
			exit(0);
		i++;
	}
	return (tab);
}*/

char	**create_map(int y)
{
	char **map;

	if ((map = (char **)malloc(sizeof(char*) * y)) == NULL)
		return (NULL);
	map[0] = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1";
	map[1] = "1 0 0 1 0 0 0 0 1 0 0 0 1 0 1 1 0 1 0 1";	
	map[2] = "1 0 0 1 0 1 1 0 1 0 1 1 1 0 1 1 0 1 0 1";
	map[3] = "1 0 0 1 0 1 1 0 1 0 1 0 0 0 1 0 0 0 0 1";
	map[4] = "1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 1 0 1";
	map[5] = "1 1 1 1 1 1 0 0 0 0 1 1 1 0 1 0 1 1 0 1";
	map[6] = "1 0 0 0 1 0 0 1 1 0 1 0 1 1 1 0 0 0 1 1";
	map[7] = "1 0 1 0 1 0 1 0 0 0 1 1 0 0 0 0 1 0 0 1";
	map[8] = "1 0 0 0 1 0 1 0 1 0 0 0 0 1 1 1 1 1 0 1";
	map[9] = "1 1 0 1 1 0 1 1 0 0 1 1 1 1 1 0 1 0 0 1";
	map[10] = "1 0 0 1 1 0 1 1 0 0 1 1 1 1 1 0 1 0 0 1";
	map[11] = "1 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1";
	map[12] = "1 0 0 0 1 1 0 0 1 1 1 1 1 1 0 1 0 1 0 1";
	map[13] = "1 0 1 0 1 0 0 0 0 1 0 0 0 0 0 1 1 1 1 1";
	map[14] = "1 1 0 0 0 0 0 1 1 0 0 1 0 1 1 1 1 1 0 1";
	map[15] = "1 0 0 0 1 0 1 0 1 0 1 0 0 0 1 0 0 0 0 1";
	map[16] = "1 0 1 0 1 0 1 0 1 0 1 0 0 0 1 0 1 1 1 1";
	map[17] = "1 0 1 0 1 1 1 0 0 0 1 0 1 0 0 0 1 0 0 1";
	map[18] = "1 0 1 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1";
	map[19] = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1";
	return (map);
}

int		parsing(char *filename, t_mlx *mlx)
{
	//int		fd;
	//char	*buffer;
	char	**tab;
	//int		k;

	//k = -1;
	//fd = open(filename, O_RDONLY, S_IREAD);*/
	Y_NBR = 20;
	ft_putstr(filename);
	printf("\n");
	/*while (get_next_line(fd, &buffer) > 0)
	{
		Y_NBR++;
		free(buffer);
	}
	free(buffer);
	close(fd);*/
	//tab = fill_tab(Y_NBR, filename);
	if ((tab = create_map(Y_NBR)) == NULL)
		return (-1);
	if ((GRID = parse_in_int(tab, Y_NBR)) == NULL)
		return (-1);
	check_grid(mlx);
	/*while (++k < Y_NBR)
		free(tab[k]);*/
	free(tab);
	//tab = free_tab(tab);
	return (0);
}
