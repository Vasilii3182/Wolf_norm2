/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 11:14:02 by ofranco           #+#    #+#             */
/*   Updated: 2017/10/18 22:40:38 by ofranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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

int		parsing(t_mlx *mlx)
{
	char	**tab;

	Y_NBR = 20;
	if ((tab = create_map(Y_NBR)) == NULL)
		return (-1);
	if ((GRID = parse_in_int(tab, Y_NBR)) == NULL)
		return (-1);
	free(tab);
	return (0);
}
