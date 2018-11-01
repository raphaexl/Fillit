/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:36:30 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/31 10:45:08 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_init_board(char (*board)[MAX_SIZE], int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAX_SIZE)
	{
		j = 0;
		while (j < MAX_SIZE)
		{
			board[i][j] = (i < size && j < size) ? '.' : '0';
			j++;
		}
		i++;
	}
}

int		ft_place_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, \
		int y, int x)
{
	int			i;

	if (t)
	{
		i = 0;
		while (i < 4)
			if (board[y + t->tab[i].y][x + t->tab[i].x] != '.')
				return (0);
			else
				i++;
		i = 0;
		while (i < 4)
		{
			if (board[y + t->tab[i].y][x + t->tab[i].x] == '.')
				board[y + t->tab[i].y][x + t->tab[i].x] = t->name;
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_delete_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t,\
		int y, int x)
{
	int		i;

	if (t)
	{
		i = 0;
		while (i < 4)
		{
			if (board[y + t->tab[i].y][x + t->tab[i].x] != '.')
				board[y + t->tab[i].y][x + t->tab[i].x] = '.';
			i++;
		}
	}
	return ;
}

int		ft_solve_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, int size)
{
	int		i;
	int		j;

	i = -1;
	while (board[++i][0] != '0' && (j = -1))
	{
		while (board[i][++j] != '0')
		{
			if (ft_place_tetriminos(board, t, i, j))
			{
				if (!t->next)
					return (1);
				if (ft_solve_tetriminos(board, t->next, size))
					return (1);
				else
					ft_delete_tetriminos(board, t, i, j);
			}
		}
	}
	if (t && t->name == 'A')
	{
		ft_init_board(board, size + 1);
		ft_solve_tetriminos(board, t, size + 1);
	}
	return (0);
}

void	ft_print_board(char (*board)[MAX_SIZE])
{
	int		i;
	int		j;

	i = 0;
	while (board[i][0] != '0')
	{
		j = 0;
		while (board[i][j] != '0')
			ft_putchar(board[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
