/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_valide.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:48:42 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/24 02:10:08 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_characters(char *content)
{
	int		i;

	i = 0;
	while (content[i])
	{
		if (content[i] != '#' && content[i] != '\n' && content[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_no_hash(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_linesep(char *content)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	if (!ft_check_characters(content))
		return (0);
	while (content[n + (++i) + 1])
	{
		if (i && !((i + 1) % 5))
			if (content[i + n] != '\n')
				return (0);
		if (i && !((n + i + 1) % 21))
		{
			if (content[i - 1 + n] == '\n' && content[n + i] == '\n')
			{
				content[i + n] = '*';
				n++;
				i--;
			}
			else
				return (0);
		}
	}
	return (1);
}

void	ft_side_connection(char *str, int i)
{
	str[i] = '@';
	if (i - 5 > 0 && str[i - 5] == '#')
		ft_side_connection(str, i - 5);
	if (i - 1 > 0 && str[i - 1] == '#')
		ft_side_connection(str, i - 1);
	if (str[i + 1] && str[i + 1] == '#')
		ft_side_connection(str, i + 1);
	if (str[i + 5] && str[i + 5] == '#')
		ft_side_connection(str, i + 5);
	return ;
}

int		ft_only_nhd(char *content)
{
	int i;
	int n_hash;
	int n_dots;
	int n_newline;

	i = 0;
	n_hash = 0;
	n_newline = 0;
	n_dots = 0;
	while (content[i])
	{
		n_hash = (content[i] == '#') ? n_hash + 1 : n_hash;
		n_dots = (content[i] == '.') ? n_dots + 1 : n_dots;
		n_newline = (content[i] == '\n') ? n_newline + 1 : n_newline;
		if (content[i] == '*' || (content[i] && content[i + 1] == '\0'))
		{
			if (n_hash != 4 || n_newline != 4 || n_dots != 12)
				ft_error();
			n_hash = 0;
			n_newline = 0;
			n_dots = 0;
		}
		i++;
	}
	return (1);
}
