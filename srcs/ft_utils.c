/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 01:41:06 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/31 06:18:22 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			ft_usage(void)
{
	ft_putendl_fd("usage: ./fillit file", 2);
}

void			ft_error(void)
{
	ft_putendl_fd("error", 1);
	exit(EXIT_FAILURE);
}

void			ft_display_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i++]);
	}
}

void			ft_push_front_tetriminos(t_tetriminos **t, t_tetriminos *new)
{
	if (!t || !new)
		return ;
	else if (!*t)
		*t = new;
	else
	{
		new->next = *t;
		*t = new;
	}
}

void			ft_print_tetriminos(t_tetriminos *t)
{
	t_tetriminos	*p;
	int				i;

	p = t;
	while (p)
	{
		i = 0;
		ft_putstr(" we have \n");
		while (i < 4)
		{
			ft_putchar(t->name);
			ft_putnbr(t->tab[i].x);
			ft_putchar(' ');
			ft_putnbr(t->tab[i].y);
			ft_putchar('\n');
			i++;
		}
		p = p->next;
	}
}
