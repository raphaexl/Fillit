/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 00:24:19 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/31 05:22:30 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TETRIMINOS_H
# define FT_TETRIMINOS_H
# define BUFF_SIZE 550
# define MAX_SIZE 20
# include "../includes/libft.h"

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_t
{
	char			name;
	t_point			tab[4];
	struct s_t		*next;
}					t_tetriminos;

t_tetriminos		*ft_create_tetriminos(char *line, int index);
void				ft_print_tetriminos(t_tetriminos	*t);
void				ft_push_front_tetriminos(t_tetriminos **t, t_tetriminos *n);
void				ft_push_back_tetriminos(t_tetriminos **t, t_tetriminos *n);
void				ft_pop_front_tetriminos(t_tetriminos **t);
void				ft_pop_back_tetriminos(t_tetriminos **t);
void				ft_free_tetriminos(t_tetriminos **t);
#endif
