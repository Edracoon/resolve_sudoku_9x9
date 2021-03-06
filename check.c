/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:09:11 by epfennig          #+#    #+#             */
/*   Updated: 2021/09/15 14:40:48 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	set_cub(int *cubx, int *cuby);

int	check_line_row(int x, int y, int value, char cpymap[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		// printf("value %i\n", value);
		// printf("value map x %i\n", cpymap[y][i]);
		// printf("value map y %i\n", cpymap[i][x]);
		if (cpymap[y][i] == value && i != x)
			return (0);
		if (cpymap[i][x] == value && i != y)
			return (0);
		i++;
	}
	return (1);
}

int	check_3x3(int x, int y, int value, char cpymap[9][9])
{
	int	cubx	= x / 3;
	int	cuby	= y / 3;

	set_cub(&cubx, &cuby);
	int	j		= cubx - 3;
	int	i		= cuby - 3;

	while (i < cuby)
	{
		while (j < cubx)
		{
			if (i != y && j != x && cpymap[i][j] == value)
				return (0);
			j++;
		}
		j = cubx - 3;
		i++;
	}
	return (1);
}

void	set_cub(int *cubx, int *cuby)
{
	switch (*cubx)
	{
		case 0:
			*cubx = 3;
			break ;
		case 1:
			*cubx = 6;
			break ;
		case 2:
			*cubx = 9;
			break ;
	}
	switch (*cuby)
	{
		case 0:
			*cuby = 3;
			break ;
		case 1:
			*cuby = 6;
			break ;
		case 2:
			*cuby = 9;
			break ;
	}
}
