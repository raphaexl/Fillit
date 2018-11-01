/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 01:28:32 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/01 22:44:58 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**ft_check_validity(char **argv)
{
	char	temp[BUFF_SIZE + 1];
	char	*content;
	char	**tab;
	int		n;
	int		fd;

	tab = NULL;
	content = NULL;
	fd = open(argv[1], O_RDONLY);
	n = read(fd, temp, BUFF_SIZE);
	if (n <= 0 || n > 545)
		ft_error();
	temp[n] = '\0';
	content = ft_strdup(temp);
	if (!ft_check_linesep(content))
		ft_error();
	ft_only_nhd(content);
	if (!(tab = ft_strsplit(content, '*')))
		ft_error();
	if (!ft_last_check(tab))
		ft_error();
	return (tab);
}

int		ft_last_check(char **tab)
{
	int		i;
	int		k;

	i = 0;
	while (tab[i])
	{
		k = 0;
		while (tab[i][k] && tab[i][k] != '#')
			k++;
		if (tab[i][k] == '#')
			ft_side_connection(tab[i], k);
		if (!ft_check_no_hash(tab[i]))
			ft_error();
		i++;
	}
	return (1);
}

int		ft_init_fillit(char (*board)[MAX_SIZE], char **argv, t_tetriminos **t)
{
	char	**tab;
	int		i;

	tab = NULL;
	i = 0;
	if ((tab = ft_check_validity(argv)))
	{
		while (tab[i])
		{
			ft_push_back_tetriminos(t, ft_create_tetriminos(tab[i], i));
			i++;
		}
		ft_init_board(board, 0);
	}
	return (0);
}

int		ft_fillit(char **argv)
{
	char			board[MAX_SIZE][MAX_SIZE];
	t_tetriminos	*t;

	t = NULL;
	ft_init_fillit(board, argv, &t);
	ft_solve_tetriminos(board, t, 0);
	ft_print_board(board);
	ft_free_tetriminos(&t);
	return (0);
}
