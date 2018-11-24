/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 04:26:04 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/25 00:45:08 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_sqrt(int n)
{
	int		rac;

	rac = 0;
	if (n > 0)
	{
		rac = 1;
		while (rac * rac < n)
			rac++;
		rac = (rac * rac) >= n ? rac : rac + 1;
	}
	return (rac);
}

int		ft_tetriminos_len(t_tetriminos *t)
{
	if (!t)
		return (0);
	else
		return (1 + ft_tetriminos_len(t->next));
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
		ft_usage();
	else
	{
		ft_fillit(argv);
	}
	return (EXIT_SUCCESS);
}
