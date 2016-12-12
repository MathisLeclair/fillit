/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:11:55 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/12 19:07:55 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lenstart(char **tab)
{
	int i;
	int j;

	j = 2;
	i = 0;
	while (tab[i])
		++i;
	while (i * 4 > j * j)
		++j;
	return (j);
}

char	*ft_fillsol(char *sol, int lenstart)
{
	int i;

	i = 0;
	while (i < ((lenstart + 1) * lenstart))
	{
		if ((i + 1) % (lenstart + 1) == 0)
			sol[i] = '\n';
		else
			sol[i] = '.';
		++i;
	}
	while (i < ((lenstart + 3) * lenstart) + 1)
	{
		sol[i] = '\0';
		++i;
	}
	return (sol);
}

int		ft_lentab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

void	ft_algo(char **tab)
{
	int			lenstart;
	char		*sol;
	t_struct	*stru;

	lenstart = ft_lenstart(tab);
	sol = malloc((lenstart + 3) * lenstart + 1);
	ft_fillsol(sol, lenstart);
	stru = malloc(sizeof(t_struct));
	stru->tab = tab;
	stru->sol = sol;
	stru->len = lenstart;
	stru->lentab = ft_lentab(tab);
	while (ft_easy(stru) == 1)
	{
		++lenstart;
		free(sol);
		sol = malloc((lenstart + 3) * lenstart + 1);
		ft_fillsol(sol, lenstart);
		stru->tab = tab;
		stru->sol = sol;
		stru->len = lenstart;
	}
}
