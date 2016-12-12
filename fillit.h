/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:51:02 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/13 10:59:45 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_struct
{
	char			**tab;
	char			*sol;
	int				len;
	int				lentab;
}					t_struct;

void				ft_putstr(char const *s);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
void				ft_error(int c);
int					ft_strlen(char const *str);
char				*ft_penis(int i);
char				**ft_starter(char *name, char **tab, int nbr);
void				ft_algo(char **tab);
int					ft_sqrt(int nb);
char				ft_easy(t_struct *stru);
void				ft_exit(char *sol, char **tab);

#endif
