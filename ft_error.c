/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:55:48 by mleclair          #+#    #+#             */
/*   Updated: 2016/11/10 14:28:13 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int c)
{
	if (c == -1)
	{
		ft_putstr("error\n");
		exit(666);
	}
	else if (c == 0)
	{
		ft_putstr(
			"usage : ./fillit \"fichier contenant les pieces a agencer\"\n");
		exit(42);
	}
}
