/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:00:02 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/12 19:07:55 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_piece(char *t, int *l)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	while (i < 19)
	{
		k = 0;
		str = ft_penis(i);
		j = -1;
		while (t[++j])
			if (t[j] == str[j])
				++k;
		if (k == 3)
		{
			t[3] = str[3];
			t[4] = 'A' + ++*l;
			t[5] = '\0';
			return ;
		}
		++i;
	}
	ft_error(-1);
}

char	*ft_recon(char *tab, int t, int j)
{
	int		i;
	int		bool;
	char	*pat2;

	pat2 = malloc(sizeof(char) * 6);
	i = -1;
	bool = 0;
	while (tab[++i])
	{
		if (tab[i] == '#' && bool)
		{
			bool = 0;
			pat2[j] = t + '0';
			t = 0;
			++j;
		}
		if (tab[i] == '#' && !bool)
			bool = 1;
		if (bool == 1)
			t++;
	}
	pat2[j] = '\0';
	return (pat2);
}

void	ft_tronc(char **tab, char *buff, int *l)
{
	char	*t;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			++k;
		++i;
	}
	if (k > 4)
		ft_error(-1);
	t = ft_recon(buff, 0, 0);
	ft_piece(t, l);
	i = 0;
	while (t[i])
	{
		tab[*l][i] = t[i];
		++i;
	}
	tab[*l][i] = '\0';
}

void	ft_valid(char **tab, char *buff, int *l)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if ((i + 1) % 5 == 0 && buff[i] != '\n')
			ft_error(-1);
		if ((i + 1) % 5 != 0 && buff[i] != '.' && buff[i] != '#')
			ft_error(-1);
		i++;
	}
	ft_tronc(tab, buff, l);
}

char	**ft_starter(char *name, char **tab, int nbr)
{
	int		fd;
	char	buff[21];
	int		n;
	int		l;

	l = -1;
	fd = open(name, O_RDONLY);
	while (nbr != 0)
	{
		if ((nbr = read(fd, buff, 20)) == 20)
		{
			buff[20] = '\0';
			ft_valid(tab, buff, &l);
			if ((n = read(fd, buff, 1)))
				if (buff[0] != '\n')
					ft_error(-1);
		}
		else if (nbr != 0)
			ft_error(-1);
	}
	if (n != 0)
		ft_error(-1);
	tab[l + 1] = 0;
	return (tab);
}
