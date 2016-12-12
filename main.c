/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:09:43 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/12 17:25:40 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit(char *sol, char **tab)
{
	int i;

	i = 0;
	ft_putstr(sol);
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	exit(0);
}

char	**ft_aloctab(const char *salope)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char **) * 27);
	while (i < 27)
	{
		tab[i] = malloc(sizeof(char *) * 6);
		++i;
	}
	return (ft_starter((char *)salope, tab, 1));
}

char	**ft_trie(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		tab[i][3] = '1';
	return (tab);
}

int		main(int ac, char const **av)
{
	int		avant;
	char	**tab;

	avant = 8;
	if (ac != 2)
		ft_error(0);
	if (ac == 2)
	{
		tab = ft_aloctab(av[1]);
		tab = ft_trie(tab);
		ft_algo(tab);
	}
	return (0);
}
