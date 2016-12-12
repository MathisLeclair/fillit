/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:26:31 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/12 21:02:12 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_unfill(char *sol, int pos, char **tab)
{
	char	c;
	int		i;
	int		j;

	c = sol[pos];
	if (c != '.')
	{
		j = 0;
		while (tab[j][4] != c)
			++j;
		i = pos;
		while (sol[i])
		{
			if (sol[i] == c)
				sol[i] = '.';
			++i;
		}
		tab[j][3] = '1';
	}
}

void	ft_fill(char *sol, int pos, char *str, int len)
{
	int i;

	i = 0;
	sol[pos] = str[4];
	while (i < 3)
	{
		if (str[i] == '1' || str[i] == '2')
		{
			if (sol[pos + str[i] - '0'])
			{
				sol[pos + str[i] - '0'] = str[4];
				pos = pos + str[i] - '0';
			}
		}
		if (str[i] >= '3' && str[i] <= '5')
		{
			if (sol[pos + len + 1 + str[i] - '5'])
			{
				sol[pos + len + 1 + str[i] - '5'] = str[4];
				pos = pos + len + 1 + str[i] - '5';
			}
		}
		++i;
	}
	str[3] = '0';
}

char	ft_secondtry(char **tab, int i)
{
	int j;
	int k;

	if (tab[i][3] == '0')
		return (1);
	j = 0;
	while (j < i)
	{
		k = 0;
		while (tab[j][k] == tab[i][k])
			++k;
		if (k == 4)
			return (1);
		++j;
	}
	return (0);
}

char	ft_isvalid(t_struct *stru, char **tab, int pos, int p)
{
	int i;

	if (ft_secondtry(tab, p))
		return (0);
	i = -1;
	while (++i < 3)
	{
		if (tab[p][i] == '1' || tab[p][i] == '2')
		{
			if (ft_isalpha(stru->sol[pos + tab[p][i] - '0'])
				|| stru->sol[pos + tab[p][i] - '0'] == '\0'
				|| stru->sol[pos + tab[p][i] - '0'] == '\n')
				return (0);
			pos = pos + tab[p][i] - '0';
		}
		if (tab[p][i] >= '3' && tab[p][i] <= '5')
		{
			if (ft_isalpha(stru->sol[pos + stru->len + 1 + tab[p][i] - '5'])
				|| stru->sol[pos + stru->len + 1 + tab[p][i] - '5'] == '\0'
				|| stru->sol[pos + stru->len + 1 + tab[p][i] - '5'] == '\n')
				return (0);
			pos = pos + stru->len + 1 + tab[p][i] - '5';
		}
	}
	return (1);
}

char	ft_easy(t_struct *stru)
{
	int pos;
	int i;

	pos = 0;
	while (stru->tab[pos] && stru->tab[pos][3] == '0')
		++pos;
	if (pos == stru->lentab)
		ft_exit(stru->sol, stru->tab);
	i = -1;
	while (stru->tab[++i])
	{
		pos = 0;
		while (stru->sol[pos])
		{
			if (stru->sol[pos] == '.')
				if (ft_isvalid(stru, stru->tab, pos, i))
				{
					ft_fill(stru->sol, pos, stru->tab[i], stru->len);
					if (ft_easy(stru))
						ft_unfill(stru->sol, pos, stru->tab);
				}
			++pos;
		}
	}
	return (1);
}
