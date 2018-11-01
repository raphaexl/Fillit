/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 04:26:04 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/31 04:27:52 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
