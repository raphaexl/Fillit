/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:48:38 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/24 23:25:53 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SUCCESS 1
# define FAILURE 0

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "ft_tetriminos.h"

void	ft_usage();
void	ft_error(void);
int		ft_check_characters(char *content);
void	ft_side_connection(char *str, int i);
int		ft_check_no_hash(char *str);
int		ft_only_nhd(char *content);
int		ft_check_linesep(char *content);
int		ft_last_check(char **tab);
char	**ft_check_validity(char **argv);
int		ft_check_tree_align(char *temp);

void	ft_init_board(char (*board)[MAX_SIZE], int size);
int		ft_place_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t,\
		int y, int x);
void	ft_delete_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t,\
		int y, int x);
int		ft_solve_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, \
		int size);
void	ft_print_board(char (*tab)[MAX_SIZE]);

int		ft_init_fillit(char (*board)[MAX_SIZE], char **argv, \
		t_tetriminos **t);
int		ft_fillit(char **argv);
int		ft_tetriminos_len(t_tetriminos *t);
int		ft_sqrt(int n);
#endif
